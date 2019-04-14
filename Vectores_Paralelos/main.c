#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_EMP 3
#define LARGO_CAD 20

void pedirCadena(char[], char[], int);
void validarTamCadena(char[], char[], int);
void cargarEmpleados(int[], char[][LARGO_CAD],char[], float[], float[], int);
void ordenarPorLegajo(int[],char[][LARGO_CAD],char[], float[], float[], int);
void ordenarPorNombre(int[],char[][LARGO_CAD],char[], float[], float[], int);
void imprimirVectores(int[],char[][LARGO_CAD],char[], float[], float[], int);


int main()
{
    int legajos[CANT_EMP];
    char nombres[CANT_EMP][LARGO_CAD];
    char sexos[CANT_EMP];
    float sueldoBruto[CANT_EMP];
    float sueldoNeto[CANT_EMP];

    cargarEmpleados(legajos,nombres,sexos,sueldoBruto,sueldoNeto, CANT_EMP);

    ordenarPorLegajo(legajos,nombres,sexos,sueldoBruto,sueldoNeto, CANT_EMP);
    imprimirVectores(legajos,nombres,sexos,sueldoBruto,sueldoNeto, CANT_EMP);

    ordenarPorNombre(legajos,nombres,sexos,sueldoBruto,sueldoNeto, CANT_EMP);
    imprimirVectores(legajos,nombres,sexos,sueldoBruto,sueldoNeto, CANT_EMP);


    return 0;
}

void cargarEmpleados(int legajos[], char nombres[][LARGO_CAD],char sexos[], float sueldBruto[], float sueldoNeto[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("Ingrese el legajo: ");
        scanf("%d", &legajos[i]);
        fflush(stdin);
        printf("Ingrese el nombre: ");
        pedirCadena("NOMBRE", nombres[i], LARGO_CAD);
        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);
        printf("Ingrese el sueldo bruto: ");
        scanf("%f",&sueldBruto[i]);
        sueldoNeto[i]= sueldBruto[i]*0.85;
    }
}

void imprimirVectores(int legajos[],char nombres[][LARGO_CAD],char sexos[], float sueldoBruto[], float sueldoNeto[], int tam){
    int i;
    printf("\n");
    for(i=0; i<tam; i++){
        printf("%d-%s-%c-%.2f-%.2f\n", legajos[i], nombres[i], sexos[i], sueldoBruto[i], sueldoNeto[i]);
    }
    printf("\n");
}
void ordenarPorLegajo(int legajos[],char nombres[][LARGO_CAD],char sexos[], float sueldoBruto[], float sueldoNeto[], int tam){

    int auxLegajo;
    char auxNombre[LARGO_CAD];
    char auxSexo;
    float auxBruto;
    float auxNeto;

    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(legajos[i]> legajos[j]){
                auxLegajo= legajos[i];
                legajos[i]= legajos[j];
                legajos[j]= auxLegajo;

                strcpy(auxNombre, nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j], auxNombre);

                auxSexo= sexos[i];
                sexos[i]= sexos[j];
                sexos[j]= auxSexo;

                auxBruto= sueldoBruto[i];
                sueldoBruto[i]= sueldoBruto[j];
                sueldoBruto[j]= auxBruto;

                auxNeto= sueldoNeto[i];
                sueldoNeto[i]= sueldoNeto[j];
                sueldoNeto[j]= auxNeto;
            }
        }
    }
}
void ordenarPorNombre(int legajos[],char nombres[][LARGO_CAD],char sexos[], float sueldoBruto[], float sueldoNeto[], int tam){

    int auxLegajo;
    char auxNombre[LARGO_CAD];
    char auxSexo;
    float auxBruto;
    float auxNeto;

    int i,j;
    for(i=0; i< tam-1; i++){
        for(j=i+1; j<tam; j++){
            if( stricmp(nombres[i],nombres[j]) == 1  ){

                strcpy(auxNombre, nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j], auxNombre);

                auxLegajo= legajos[i];
                legajos[i]= legajos[j];
                legajos[j]= auxLegajo;

                auxSexo= sexos[i];
                sexos[i]= sexos[j];
                sexos[j]= auxSexo;

                auxBruto= sueldoBruto[i];
                sueldoBruto[i]= sueldoBruto[j];
                sueldoBruto[j]= auxBruto;

                auxNeto= sueldoNeto[i];
                sueldoNeto[i]= sueldoNeto[j];
                sueldoNeto[j]= auxNeto;
            }
        }
    }
}
void pedirCadena(char mensaje[], char cadena[], int tam){

    printf("Ingrese el %s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarTamCadena(mensaje, cadena, tam);

}
void validarTamCadena(char mensaje[], char cadena[], int tam){

    while( strlen(cadena) > tam){
        printf("Reingrese el %s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

