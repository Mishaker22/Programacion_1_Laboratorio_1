#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#include "EMPLEADO.H"

#define T 8
#define R 5

int main()
{

    eEmpleado listaEmpleados[T];
    eSector listaSectores[R];
    inicializarEmpleados(listaEmpleados,T);
    hardcodearDatosSectores(listaSectores,R);
    hardcodearDatosEmpleados(listaEmpleados,5,listaSectores,5);



    int opcion;
    char mensaje[100];

    do{
        opcion = menuDeOpciones("1. Alta\n2. Baja\n3. Modificar\n4. Mostrar\n5. Informar\n6. Salir\n\nElija una opcion",1,6);
        switch(opcion)
        {
            case 1:
                cargarEmpleado(listaEmpleados, T, listaSectores, R);
            break;
            case 2:
                bajaEmpleado(listaEmpleados, T, listaSectores, R, mensaje);
                printf("\n%s\n",mensaje);
                break;
            case 3:
                modificarEmpleado(listaEmpleados, T, listaSectores, R, mensaje);
                printf("\n%s\n",mensaje);
            break;

            case 4:
                mostrarListaEmpleados(listaEmpleados,T,listaSectores,R);
                break;
            case 5:
                    printf("\nLo debo revisar\n\n");

                    //Revisar criterio de los mostrar
                    //mostrar solo los ocupados
                    mostrarEmpleadosPorSector(listaEmpleados,T,listaSectores,R);
                    mostrarSueldosPorSector(listaEmpleados,T,listaSectores,R);
                    mostrarCantEmpleadosPorSector(listaEmpleados,T,listaSectores,R);




                    //mostrarSueldosPorSector(listaEmpleados,T,listaSectores,R);



                //mostrarEmpleadosSueldoMaximo(listaEmpleados,T);
                //printf("La cantidad de carlos es: %d\n", contarCarlos(listaEmpleados,T));

                break;
        }
    }while(opcion!=6);


    return 0;
}
