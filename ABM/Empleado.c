
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"


void cargarEmpleado(eEmpleado lista[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);

        lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }



}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i]);
        }

    }
}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d\t%s\t%c\t%.2f\t\t%.2f\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto);

}
int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={19,15,11,20,12,13};
    char nombres[][50]={"Ana","Victor","Jose","Julieta","Pablo","Marina"};
    char sexo[]={'F','M','M','F','M','F'};
    float sueldosBruto[]={45000,22000,40000,20000,60000,50000};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;

    }
}

int buscarLegajo(eEmpleado lista[], int tam, int legajo){
    int indice= -1;
    int i;
    for(i=0;i<tam;i++){
        if(lista[i].legajo == legajo){
            indice= i;
            break;
        }
    }
    return indice;
}

void modificarSueldoBruto(eEmpleado lista[], int legajo){
    printf("Ingrese el sueldo bruto: ");
    scanf("%f", &lista[legajo].sueldoBruto);
    lista[legajo].sueldoNeto= lista[legajo].sueldoBruto * 0.85;
    printf("\nSueldo actualizado.\n");
}

void modificarNombre(eEmpleado lista[], int legajo){
    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%[^\n]", lista[legajo].nombre);
    printf("\nNombre actualizado.\n");
}

void modificarSexo(eEmpleado lista[], int legajo){
    printf("Ingrese el sexo: ");
    fflush(stdin);
    scanf("%c", &lista[legajo].sexo);
    printf("\nSexo actualizado.\n");
}

void bajaEmpleado(eEmpleado lista[], int legajo){
    lista[legajo].estado= LIBRE;
    printf("\nEmpleado dado de baja (baja logica).\n");
}

void ordenarPorLegajo(eEmpleado lista[], int tam){
    eEmpleado aux;
    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(lista[i].legajo > lista[j].legajo){
                aux= lista[i];
                lista[i]= lista[j];
                lista[j]= aux;
            }
        }
    }
}
void ordenarPorSueldoBruto(eEmpleado lista[], int tam){
    eEmpleado aux;
    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(lista[i].sueldoBruto > lista[j].sueldoBruto){
                aux= lista[i];
                lista[i]= lista[j];
                lista[j]= aux;
            }
        }
    }
}
void ordenarPorNombre(eEmpleado lista[], int tam){

    eEmpleado aux;
    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if( stricmp(lista[i].nombre,lista[j].nombre) > 0  ){
                aux= lista[i];
                lista[i]= lista[j];
                lista[j]= aux;
            }
        }
    }
}
void ordenarPorSexo(eEmpleado lista[], int tam){
    eEmpleado aux;
    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(lista[i].sexo > lista[j].sexo){
                aux= lista[i];
                lista[i]= lista[j];
                lista[j]= aux;
            }
        }
    }
}

