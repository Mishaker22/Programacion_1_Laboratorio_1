#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define T 20

int main()
{
    char nombre[T];
    char apellido[T];
    char apellidoNombre[T+T];

    pedirCadena("NOMBRE",nombre, T);
    pedirCadena("APELLIDO",apellido, T);
    formatearCadena(apellidoNombre, nombre, apellido);

    printf("\n\nLa salida es: %s", apellidoNombre);

    return 0;
}



