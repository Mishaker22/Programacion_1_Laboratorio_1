#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void formatearCadena(char salida[], char nom[], char ape[]){
    strcpy(salida,"");
    strcat(salida, ape);
    strcat(salida,", ");
    strcat(salida, nom);
    strlwr(salida);
    salida[0]= toupper(salida[0]);
    int i= 0;
    while(salida[i]!= '\0'){
        if(salida[i]== ' '){
            salida[i+1]= toupper(salida[i+1]);
        }
        i++;
    }
}
