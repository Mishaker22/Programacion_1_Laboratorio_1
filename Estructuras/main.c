#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
}eEmpleado;

int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;

    unEmpleado.legajo= 100;
    strcpy(unEmpleado.nombre,"Fer");
    unEmpleado.sexo= 'm';
    unEmpleado.sueldoBruto=90000;
    unEmpleado.sueldoNeto= unEmpleado.sueldoBruto*0.85;

    //La copia es por valor:
    otroEmpleado= unEmpleado;

    otroEmpleado.legajo= 0;
    strcpy(otroEmpleado.nombre,"Daniel");

    printf("\n%d -- %s -- %c -- %.2f -- %.2f",unEmpleado.legajo,unEmpleado.nombre,unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
    printf("\n%d -- %s -- %c -- %.2f -- %.2f",otroEmpleado.legajo, otroEmpleado.nombre, otroEmpleado.sexo, otroEmpleado.sueldoBruto, otroEmpleado.sueldoNeto);

    return 0;
}
