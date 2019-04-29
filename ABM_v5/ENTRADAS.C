#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pedirFloat(char mensaje[]){
    float unFloat;
    printf("%s: ", mensaje);
    scanf("%f", &unFloat);
    return unFloat;
}

float pedirFloatRango(char mensaje[], float minimo, float maximo){
    float unFloat;
    printf("%s: ", mensaje);
    scanf("%f", &unFloat);
    while(unFloat<minimo || unFloat > maximo){
        printf("Error. %s: ", mensaje);
        scanf("%f", &unFloat);
    }
    return unFloat;
}

float pedirFloatPositivo(char mensaje[]){
    float unFloat;
    printf("%s: ", mensaje);
    scanf("%f", &unFloat);
    while(unFloat<=0){
        printf("Error. %s: ", mensaje);
        scanf("%f", &unFloat);
    }
    return unFloat;
}

int pedirEntero(char mensaje[]){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    return unEntero;
}

int pedirEnteroRango(char mensaje[], int minimo, int maximo){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero < minimo || unEntero > maximo){
        printf("Error. %s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

int pedirEnteroPositivo(char mensaje[]){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero <= 0){
        printf("Error. %s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

char pedirCaracter(char mensaje[]){
    char unChar;
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", &unChar);
    return unChar;
}

char pedirCaracterSexo(char mensaje[]){
    char unChar;
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", &unChar);
    while( !(unChar=='f' || unChar=='F' || unChar == 'm' || unChar == 'M') ){
        printf("Error. %s: ", mensaje);
        fflush(stdin);
        scanf("%c", &unChar);
    }
    return unChar;
}
void validarTamCadena(char mensaje[], char cadena[], int tam){
    while( strlen(cadena) > tam){
        printf("Error. %s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}
void pedirCadena(char mensaje[], char cadena[], int tam){
    char buffer[1000];
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", buffer);
    validarTamCadena(mensaje, buffer, tam);
    strcpy(cadena, buffer);
}
void pedirPalabra(char mensaje[], char cadena[], int tam){
    char buffer[1000];
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%s", buffer);
    validarTamCadena(mensaje, buffer, tam);
    strcpy(cadena, buffer);
}

int menuDeOpciones(char mensaje[],int primera, int ultima)
{
    int opcion;
    opcion= pedirEnteroRango(mensaje,primera,ultima);
    return opcion;
}

