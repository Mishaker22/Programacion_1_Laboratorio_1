#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "Entradas.h"



void hardcodearDatosSectores(eSector listaSectores[], int ts){

    int ids[]= {1,2,3,4,5};
    char descripciones[][20]= {"Administrativos","Contables","RR HH","Sistemas","Gerentes"};
    float valoresHora[]= {100,200,300,400,500};

    int i;
    for(i=0; i<ts; i++){
        listaSectores[i].idSector = ids[i];
        strcpy(listaSectores[i].descripcion, descripciones[i]);
        listaSectores[i].valorHora = valoresHora[i];
    }


}

void mostrarListaSectores(eSector listaSectores[], int ts){

    int i;
    for(i=0;i<ts;i++){
        printf("%d-%s.\t",listaSectores[i].idSector,listaSectores[i].descripcion);
    }
    printf("\n");

}

int validarSector(int idSector, eSector listaSectores[], int ts){

    int esValido= 0;
    int i;
    for(i=0;i<ts;i++){
        if(idSector == listaSectores[i].idSector){
            esValido= 1;
            break;
        }
    }
    return esValido;
}

int pedirSector(char mensaje[], eSector listaSectores[], int ts){

    mostrarListaSectores(listaSectores, ts);
    int idSector= pedirEnteroPositivo(mensaje);
    //printf("%s: ", mensaje);
    //scanf("%d", &idSector);
    while( ! validarSector(idSector, listaSectores, ts )){
        mostrarListaSectores(listaSectores, ts);
        printf("Error. ");
        idSector= pedirEnteroPositivo(mensaje);

        //scanf("%d", &idSector);
    }
    return idSector;
}


//Refactorizado
void inicializarEmpleados(eEmpleado listaEmpleados[], int te){
    int i;
    for(i=0; i<te; i++){
        listaEmpleados[i].estado = LIBRE;
    }
}

//Refactorizado
/*
float calcularSueldoBruto(eEmpleado unEmpleado, eSector listaSectores[], int ts){
    float sueldoBruto;
    int i;
    for(i=0;i<ts;i++){
        if(unEmpleado.idSector == listaSectores[i].idSector){
            sueldoBruto= unEmpleado.cantHoras*listaSectores[i].valorHora;
            break;
        }
    }
    return sueldoBruto;
}
*/


void actualizarSalario(eEmpleado listaEmpleados[], int indice, eSector listaSectores[], int ts){

    int i;
    for(i=0;i<ts;i++){
        if(listaEmpleados[indice].idSector == listaSectores[i].idSector){
            listaEmpleados[indice].sueldoBruto= listaEmpleados[indice].cantHoras*listaSectores[i].valorHora;
            break;
        }
    }
    listaEmpleados[indice].sueldoNeto= listaEmpleados[indice].sueldoBruto*0.85;
}

//Refactorizado
void hardcodearDatosEmpleados(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){
    int i;
    int legajos[]= {10,20,30,40,50,60,70,80};
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo","Ana","Gabriela"};
    char sexo[]= {'M','F','M','M','M','M','F','F'};
    int idSector[]= {5,2,3,3,2,4,1,4};
    int cantHoras[]= {200,200,200,200,200,200,200,200};

    for(i=0; i<te; i++){
        listaEmpleados[i].legajo = legajos[i];
        strcpy(listaEmpleados[i].nombre, nombres[i]);
        listaEmpleados[i].sexo = sexo[i];
        listaEmpleados[i].idSector= idSector[i];
        listaEmpleados[i].cantHoras= cantHoras[i];

        actualizarSalario(listaEmpleados,i, listaSectores, ts);
        listaEmpleados[i].estado = OCUPADO;
    }

    //mostrarListaEmpleados(listaEmpleados,te, listaSectores,ts);
}

//Refactorizado
int buscarLibre(eEmpleado listaEmpleados[], int te){
    int i;
    int indice=-1;
    for(i=0; i<te; i++){
        if(listaEmpleados[i].estado==LIBRE){
            indice = i;
            break;
        }
    }
    return indice;
}



//Refactorizado
void cargarEmpleado(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){
    int indice= buscarLibre(listaEmpleados, te);
    if(indice!=-1){
        listaEmpleados[indice].legajo= pedirEnteroPositivo("Ingrese el legajo (mayor a 0)");
        pedirCadena("Ingrese el nombre",listaEmpleados[indice].nombre,TAM_NOMBRE);
        listaEmpleados[indice].sexo= pedirCaracterSexo("Ingrese el sexo");
        listaEmpleados[indice].idSector= pedirSector("Ingrese el id de sector", listaSectores, ts);
        listaEmpleados[indice].cantHoras= pedirEnteroPositivo("Ingrese la cantidad de horas");


        actualizarSalario(listaEmpleados,indice, listaSectores, ts);
        listaEmpleados[indice].estado = OCUPADO;
    }
    else{
        printf("No hay espacio para mas empleados.");
    }
}
//Refactorizado
int buscarLegajo(eEmpleado listaEmpleados[], int te, int legajo){
    int indice= -1;
    int i;
    for(i=0;i<te;i++){
        if(listaEmpleados[i].legajo == legajo){
            indice= i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector listaSectores[], int ts){
    char descripcionSector[50];
    int i;
    for(i=0; i<ts; i++){
        if(unEmpleado.idSector==listaSectores[i].idSector ){
            strcpy(descripcionSector, listaSectores[i].descripcion );
            break;
        }
    }
    printf("%5d%15s%10c%20s%15d%23.2f%23.2f\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, descripcionSector,
                                        unEmpleado.cantHoras, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}



//Refactorizado
void mostrarListaEmpleados(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){
    printf(" Legajo\t      Nombre\t    Sexo\t   Sector\tCant. de horas       Sueldo Bruto\t      SueldoNeto\n\n");

    int i;
    for(i=0; i<te; i++){
        if(listaEmpleados[i].estado!= LIBRE){
            mostrarEmpleado(listaEmpleados[i], listaSectores, ts);
        }
    }
    printf("\n");
}

//Refactorizado
void bajaEmpleado(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts, char mensaje[]){
    int legajo= pedirEnteroPositivo("Ingrese legajo a dar de baja");
    int indice= buscarLegajo(listaEmpleados,te,legajo);
    if(indice != -1){
        mostrarEmpleado(listaEmpleados[indice], listaSectores, ts);
        int opcion= menuDeOpciones("\n1.REALIZAR LA BAJA.\n2.CANCELAR.\n\nElija opcion",1,2);
        if (opcion==1){
            listaEmpleados[indice].estado= LIBRE;
            strcpy(mensaje,"Baja EFECTUADA.");
        }else{
            strcpy(mensaje,"Baja CANCELADA.");
        }
    }else{
        strcpy(mensaje,"El legajo no existe.");
    }
}
void modificarNombre(eEmpleado listaEmpleados[], int indice){
    pedirCadena("Nuevo nombre",listaEmpleados[indice].nombre,TAM_NOMBRE);
}

void modificarSexo(eEmpleado listaEmpleados[], int indice){
    listaEmpleados[indice].sexo= pedirCaracterSexo("Nuevo sexo");
}


void modificarSector(eEmpleado listaEmpleados[], int indice, eSector listaSectores[], int ts){
    listaEmpleados[indice].idSector= pedirSector("Nuevo id de sector", listaSectores, ts);
    actualizarSalario(listaEmpleados, indice, listaSectores, ts);
}

void modificarCantHoras(eEmpleado listaEmpleados[], int indice, eSector listaSectores[], int ts){
    listaEmpleados[indice].cantHoras= pedirEnteroPositivo("Ingrese la cantidad de horas");
    actualizarSalario(listaEmpleados, indice, listaSectores, ts);
}

//ACHICAR
void modificarEmpleado(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts, char mensaje[]){

    int legajo= pedirEnteroPositivo("Ingrese legajo de empleado a modificar");
    int indice= buscarLegajo(listaEmpleados,te,legajo);
    if(indice != -1){
        mostrarEmpleado(listaEmpleados[indice], listaSectores, ts);
        int opcion= menuDeOpciones("\n1. Mod. Nombre\n2. Mod. Sexo\n3. Mod. Sector\n3. Mod. Cantidad de Horas\n5. CANCELAR.\n\nElija opcion",1,5);

        switch (opcion){
            case 1:
                modificarNombre(listaEmpleados, indice);
                strcpy(mensaje,"Nombre modificado.\n");
                break;
            case 2:
                modificarSexo(listaEmpleados, indice);
                strcpy(mensaje,"Sexo modificado.\n");
                break;
            case 3:
                modificarSector(listaEmpleados, indice, listaSectores, ts);
                strcpy(mensaje,"Sector modificado (sueldo actualizado).\n");
                break;
            case 4:
                modificarCantHoras(listaEmpleados, indice, listaSectores, ts);
                strcpy(mensaje,"Cantidad de horas modificada (sueldo actualizado).\n");
                break;
            case 5:
                strcpy(mensaje,"\nSe cancelo la modificacion de los datos.\n");
                break;
        }
    }else{
        strcpy(mensaje,"El legajo no existe.\n");
    }
}



void mostrarEmpleadosPorSector(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){
    int i;
    int j;
    int largo;
    int contador;
    char buffer[1000];
    for(i=0;i<ts;i++){
        printf("\n--Empleados del sector %20s: ",listaSectores[i].descripcion);
        strcpy(buffer,"");
        contador= 0;
        for(j=0;j<te;j++){
            if((listaEmpleados[j].idSector==listaSectores[i].idSector) && (listaEmpleados[j].estado==OCUPADO)){
                strcat(buffer,listaEmpleados[j].nombre);
                strcat(buffer,", ");
                contador++;
            }
        }
        if(contador!=0){
            largo= strlen(buffer);
            //Eliminar la ultima coma:
            buffer[largo-2]='\0';
            printf("%s",buffer);
        }else{
            printf("NO HAY EMPLEADOS EN ESTE SECTOR.");
        }
    }
    printf("\n\n");
}

//Refactorizado
void mostrarSueldosPorSector(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){
    int i;
    int j;
    double brutoTotal;

    for(i=0;i<ts;i++){
        brutoTotal= 0;
        for(j=0;j<te;j++){
            if((listaEmpleados[j].idSector == listaSectores[i].idSector)&&(listaEmpleados[j].estado==OCUPADO)){
                brutoTotal= brutoTotal + listaEmpleados[j].sueldoBruto;
            }
        }
        printf("-- Sueldo total del sector %s\t: %.2f\n",listaSectores[i].descripcion, brutoTotal);
    }

}

//Refactorizado
int contarEmpleadosPorSector(eEmpleado listaEmpleados[], int te, eSector unSector){
    int cantidad=0;
    int i;
    for(i=0;i<te;i++){
        if((listaEmpleados[i].idSector == unSector.idSector)&&(listaEmpleados[i].estado==OCUPADO)){
            cantidad++;
        }
    }
    return cantidad;
}



//Usar otra estructura!!
void mostrarCantEmpleadosPorSector(eEmpleado listaEmpleados[], int te, eSector listaSectores[], int ts){

    eSectorAux listaAux[ts];
    int i;

    for(i=0;i<ts;i++){
        listaAux[i].idSector= listaSectores[i].idSector;
    }

    int cantEmpleados;
    int j;
    for(i=0;i<ts;i++){
        cantEmpleados= 0;
        for(j=0;j<te;j++){

            if((listaEmpleados[j].idSector == listaAux[i].idSector)&&(listaEmpleados[j].estado==OCUPADO)){
                cantEmpleados++;
            }


        }
        listaAux[i].cantEmpleados = cantEmpleados;
    }
    printf("\t Descripcion\tCant. de Empleados\n\n");
    for(i=0;i<ts;i++){
        printf("%22s\t\t%d\n",listaSectores[i].descripcion , listaAux[i].cantEmpleados);
    }
    printf("\n");
}



//Revisar criterio

float buscarSueldoMaximo(eEmpleado listaEmpleados[], int te)
{
    float maximo;
    int flag = 0;
    int i;

    for(i=0; i<te; i++)
    {
        if(listaEmpleados[i].estado==OCUPADO)
        {
            if(flag==0 || listaEmpleados[i].sueldoBruto>maximo)
            {
                maximo = listaEmpleados[i].sueldoBruto;
                flag = 1;
            }
        }

    }



    return maximo;

}
void mostrarEmpleadosSueldoMaximo(eEmpleado listaEmpleados[], int te)
{
    float maximo;
    int i;

    maximo = buscarSueldoMaximo(listaEmpleados, te);

    for(i=0; i<te; i++)
    {
        if(listaEmpleados[i].estado==OCUPADO && maximo == listaEmpleados[i].sueldoBruto)
        {
            //mostrarEmpleado(lista[i]);

        }
    }

}

int contarCarlos(eEmpleado listaEmpleados[], int te)
{
    int contadorCarlos = 0;
    int i;

    for(i=0; i<te; i++)
    {
        if(listaEmpleados[i].estado==OCUPADO)
        {
            if(stricmp(listaEmpleados[i].nombre,"carlos")==0 && listaEmpleados[i].sueldoBruto>20000)
            {
                contadorCarlos++;
            }
        }
    }

    return contadorCarlos;
}
