#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarLargo(char[]);

int main()
{



    char cadena[20];
    //Ingresar siempre "hola" como cadena, luego probar con
    //"hola a todos":
    printf("\nIngrese una frase: ");
    scanf("%s",cadena);
    printf("\nLa frase es: %s (usando scanf())", cadena);
    int cantidad= strlen(cadena);
    printf("\nOcupa %d bytes\n", cantidad);
    fflush(stdin);

    printf("\nIngrese una frase: ");
    gets(cadena);
    cantidad= strlen(cadena);
    printf("\nLa frase es: %s (usando gets())", cadena);
    printf("\nOcupa %d bytes\n", cantidad);
    fflush(stdin);

    //Observamos que ocupa un byte más (cuenta el \n)
    printf("\nIngrese una frase: ");
    fgets(cadena,20,stdin);
    cantidad= strlen(cadena);
    printf("\nLa frase es: %s (usando fgets())", cadena);
    printf("\nOcupa %d bytes\n", cantidad);
    fflush(stdin);

    //Piso el \n con un \0:
    cadena[cantidad - 1]= '\0';
    cantidad= strlen(cadena);
    printf("\nLa frase es: %s (usando fgets() y agregando el barra 0)", cadena);
    printf("\nOcupa %d bytes\n", cantidad);
    fflush(stdin);

    printf("\nIngrese otra frase: ");
    fgets(cadena,20,stdin);
    cantidad= contarLargo(cadena);
    printf("\nLa frase es: %s (usando fgets()) y funcion", cadena);
    printf("\nOcupa %d bytes\n", cantidad);
    fflush(stdin);



    //Otras funciones para cadenas
    char marca[20]= "Samsung";
    char otraMarca[20]= "Phillips";

    //otraPalabra= "Samsung" da error, debo usar strcpy():
    strcpy(otraMarca,marca);
    printf("\notraMarca: %s", otraMarca);
    //strcpy también soporta constantes (literal):
    strcpy(otraMarca,"Nokia");
    printf("\notraMarca: %s", otraMarca);

    //Comparar cadenas distintas:
    int result= strcmp(marca,otraMarca);
    printf("\nMarca: %s otraMarca: %s - Comparacion (distintas): %d",marca,otraMarca,result);

    //Comparar cadenas iguales:
    strcpy(otraMarca,marca);
    result= strcmp(marca,otraMarca);
    printf("\nMarca: %s otraMarca: %s - Comparacion (iguales): %d",marca,otraMarca,result);

    //Comparar cadenas distintas (otro orden):
    strcpy(marca,"Nokia");
    result= strcmp(marca,otraMarca);
    printf("\nMarca: %s otraMarca: %s - Comparacion (distintas -otro orden-): %d",marca,otraMarca,result);

    /*
        strcmp(cadena,otraCadena) devuelve:
             0 si son iguales
             1 si otraCadena alfabeticamente esta primero
            -1 si marca alfabeticamente esta primero
    */

    //Cambiamos la primer letra a minuscula:
    strcpy(marca,"nokia");
    strcpy(otraMarca,"Nokia");

    //Comparamos:
    result= strcmp(marca,otraMarca);
    printf("\nMarca: %s otraMarca: %s - Comparacion (distintas -minuscula y mayuscula-): %d",marca,otraMarca,result);

    /*
        Como en la tabla ASCII las mayusculas estan primero que las
        minusculas, el resultado de la comparación es positivo
        (Nokia esta primero que nokia).
    */

    //Pasar a mayusculas:
    strupr(marca);
    printf("\nMarca: %s (en mayuscula)",marca);

    //Pasar a minusculas:
    strlwr(marca);
    printf("\nMarca: %s (en minuscula)",marca);

    strcpy(marca,"Ford");
    strcpy(otraMarca,"Renault");

    //Concatenar cadenas
    //marca= marca+ otraMarca (no funciona)
    //strcat() trabaja de a pares:
    strcat(marca," vs ");
    printf("\nContenido de marca: %s", marca);

    strcat(marca,otraMarca);
    printf("\nContenido de marca: %s", marca);

    strcpy(marca,"FoRD");
    strcpy(otraMarca,"fOrd");

    result= stricmp(marca,otraMarca);
    printf("\nMarca: %s otraMarca: %s - Comparacion (stricmp no es case sensitive!): %d",marca,otraMarca,result);


    return 0;
}

//Consultar
int contarLargo(char palabra[20]){
    int largo;
    largo= strlen(palabra);
    //No estoy seguro de [largo -1].....
    palabra[largo-1]= '\0';
    largo= strlen(palabra);
    return largo;
}
