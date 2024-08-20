Este proyecto es una aplicación en C que captura las pulsaciones de teclas en un sistema Linux utilizando la interfaz de dispositivos de entrada del sistema (/dev/input). Está pensado para fines educativos y de desarrollo.
Características

    Captura y muestra las teclas presionadas en tiempo real.
    Soporte para teclas estándar del teclado.
    Interfaz de bajo nivel con el sistema operativo.

Requisitos

    Sistema operativo Linux.
    Compilador GCC.
    Acceso como superusuario (root) para ejecutar el programa.
    
Uso

Una vez que el programa está en ejecución, capturará las pulsaciones de teclas y las imprimirá en la consola.

Archivos Principales

    main.c: Contiene el código fuente principal del programa.
    keys.h: Define el mapeo de códigos de teclas a caracteres.
    Makefile (opcional): Archivo de configuración para automatizar la compilación.
