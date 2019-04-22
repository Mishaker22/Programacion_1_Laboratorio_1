#include "Entradas.h"
int menuDeOpciones(char mensaje[], int menor, int mayor){
    int opcion;
    opcion= pedirEnteroRango(mensaje, menor, mayor);
    return opcion;
}
