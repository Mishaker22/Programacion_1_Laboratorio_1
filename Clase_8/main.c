#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"


#define T 3
#define LIBRE 0
#define OCUPADO 1

typedef struct{
//struct eEmpleado{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
//};
}eEmpleado;

//Se declaran luego de las estructuras

void mostrarEmpleado(eEmpleado);
int mostrarEmpleados(eEmpleado[], int);
void cargarEmpleados(eEmpleado[], int);

void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int borrarUno(eEmpleado[], int, int);
int buscarUno(eEmpleado[], int, int);

void cargarUnEmpleado(eEmpleado[], int);


int main()
{
    eEmpleado empleados[T];

    int listaInicializada= 0;
    int opcion;
    char seguir= 's';
    do{
        if(listaInicializada){
            printf("\n--LISTA DE EMPLEADOS INICIALIZADA--\n\n");
        }else{
            printf("\n--LISTA DE EMPLEADOS AUN NO INICIALIZADA--\n\n");
        }

        printf("1. Inicializar empleados\n2. Alta de empleado\n3. Informar empleados\n4. Salir\n");
        printf("\n----------------------\n");

        opcion= pedirEnteroRango("Nro de OPCION", 1, 4);

        switch(opcion){
        case 1:
            inicializarEmpleados(empleados,T);
            listaInicializada= 1;
            break;
        case 2:
            if(listaInicializada){
                cargarUnEmpleado(empleados,T);
            }else{
                printf("\nLa lista no esta inicializada!\n");
            }
            break;
        case 3:
            if(listaInicializada){
                if (!mostrarEmpleados(empleados,T)){
                    printf("\nLa lista de empleados esta vacia.\n");
                }
            }else{
                printf("\nLa lista no esta inicializada!\n");
            }
            break;
        case 4:
            printf("\nSaliendo del programa.\n");
            seguir= 'n';
            break;
        default:
            printf("No ingreso una opcion valida.\n");
        }
        printf("\n\n");
        system("pause");
        system("cls");

    }while(seguir=='s');

    return 0;
}


int buscarLibre(eEmpleado lista[], int tam){
    int indice= -1;
    int i;
    for (i=0;i<tam;i++){
        if(lista[i].estado == LIBRE){
            indice= i;
            break;
        }
    }
    return indice;
}

int buscarUno(eEmpleado lista[], int tam, int legajo){
    int i;
    int indice= -1;
    for(i=0;i<tam;i++){
        if(lista[i].legajo==legajo){
            indice= i;
            break;
        }
    }
    return indice;
}

int borrarUno(eEmpleado lista[], int tam, int legajo){
    int fueBorrado= 0;
    int i;
    for(i=0; i< tam; i++){
        if(lista[i].legajo == legajo){
            lista[i].estado= LIBRE;
            fueBorrado= 1;
            break;
        }
    }
    return fueBorrado;
}

void inicializarEmpleados(eEmpleado lista[], int tam){
    int i;
    for(i=0; i<tam; i++){
        lista[i].estado= LIBRE;
    }
}


void mostrarEmpleado(eEmpleado emp){
    printf("\n%d-%s-%c-%.2f-%.2f", emp.legajo, emp.nombre,
           emp.sexo, emp.sueldoBruto, emp.sueldoNeto);

}
int mostrarEmpleados(eEmpleado lista[], int tam){
    int hayEmpleados=0;
    int i;
    for(i=0; i<tam; i++){
        if(lista[i].estado==OCUPADO){
            mostrarEmpleado(lista[i]);
            hayEmpleados=1;
        }
    }
    return hayEmpleados;
}

void cargarUnEmpleado(eEmpleado lista[], int tam){

    int i= buscarLibre(lista,tam);

    if(i>=0){
        printf("\n");
        lista[i].legajo= pedirEnteroRango("LEGAJO (entre 1 y 10000)",1,10000);
        pedirCadena("NOMBRE", lista[i].nombre, 20);
        lista[i].sexo= pedirCaracterSexo("SEXO (f/m)");
        lista[i].sueldoBruto= pedirFloatRango("SUELDO BRUTO (entre 0 y 250000)",0,250000);
        lista[i].sueldoNeto= lista[i].sueldoBruto*0.85;
        lista[i].estado= OCUPADO;
    }else{
        printf("\nLa lista esta llena, no se pudo agregar.");
    }
}

void cargarEmpleados(eEmpleado lista[], int tam){
    int i;
    for (i=0;i<tam;i++){
        lista[i].legajo= pedirEnteroRango("LEGAJO",1,10000);
        pedirCadena("NOMBRE", lista[i].nombre, 20);
        lista[i].sexo= pedirCaracterSexo("SEXO");
        lista[i].sueldoBruto= pedirFloatRango("SUELDO BRUTO",0,250000);
        lista[i].sueldoNeto= lista[i].sueldoBruto*0.85;
        lista[i].estado= OCUPADO;
    }

}
