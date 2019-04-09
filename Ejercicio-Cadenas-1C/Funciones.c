#include <string.h>
#include "Funciones.h"

void concatenar(char cadena[], char apellido[], char nombre[]){
    strcpy(cadena, apellido);
    eliminarEnter(cadena);
    strcat(cadena, ", ");
    strcat(cadena, nombre);
    eliminarEnter(cadena);
}

void eliminarEnter(char cadena[]){
    int len= strlen(cadena);
    cadena[len-1]= '\0';
}

void formatear(char cadena[]){
    strlwr(cadena);
    int len= strlen(cadena);
    int i;
    for(i=0;i<len;i++){
        if(i==0){
            cadena[i]= (cadena[i] - 32);
        }else if(cadena[i]== ' '){
            cadena[i+1]= (cadena[i+1] - 32);
        }
    }
}
