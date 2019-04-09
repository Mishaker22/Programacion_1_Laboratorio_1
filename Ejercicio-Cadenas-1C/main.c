#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define T 100


int main()
{
    char nombre[T];
    char apellido[T];
    char apellidoNombre[T+T];

    printf("Ingrese su nombre completo: ");
    fgets(nombre,T,stdin);
    fflush(stdin);

    printf("\nIngrese su apellido completo: ");
    fgets(apellido,T,stdin);

    concatenar(apellidoNombre, apellido, nombre);
    formatear(apellidoNombre);

    printf("\nNombre: %s", nombre);
    printf("\nApellido: %s", apellido);
    printf("\nCadena Final: %s\n\n",apellidoNombre);

    system("pause");
    return 0;
}
