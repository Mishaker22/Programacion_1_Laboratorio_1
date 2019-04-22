#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Entradas.h"
#include "Menu.h"

#define T 10

int main()
{

    int indice;
    int legajo;
    int opcion;

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);
    hardcodearDatosEmpleados(lista,4);

    do
    {
        opcion = menuDeOpciones("\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Salir\n\nElija una opcion: ",1,6);
        switch(opcion)
        {
        case 1:
            printf("\n");
            cargarEmpleado(lista,  T);
            break;

        case 2:
            legajo= pedirEnteroPositivo("Ingrese legajo a dar de baja: ");
            indice= buscarLegajo(lista,T,legajo);
            if(indice != -1)
            {
                mostrarEmpleado(lista[indice]);

                opcion= menuDeOpciones("\n1.REALIZAR LA BAJA.\n2.CANCELAR.\n\nElija opcion: ",1,2);
                if (opcion==1)
                {
                    bajaEmpleado(lista, indice);
                }
                else
                {
                    printf("\nSe cancelo la operacion de baja de empleado.\n");
                }

            }
            else
            {
                printf("\nEl legajo no existe.\n");
            }
            break;

        case 3:
            legajo= pedirEnteroPositivo("Ingrese legajo a modificar: ");
            indice= buscarLegajo(lista,T,legajo);
            if (indice != -1)
            {
                mostrarEmpleado(lista[indice]);
                opcion= menuDeOpciones("\n1.Mod. Nombre\n2.Mod. Sexo\n3.Mod. Sueldo Bruto\n4.CANCELAR.\n\nElija opcion: ",1,4);
                switch (opcion)
                {
                case 1:
                    modificarNombre(lista, indice);
                    break;
                case 2:

                    modificarSexo(lista, indice);
                    break;
                case 3:

                    modificarSueldoBruto(lista, indice);
                    break;
                case 4:
                    printf("\nNo se modificaron los datos.\n");
                    break;
                default:
                    printf("\nOpcion incorrecta. No se modificaron los datos.\n");
                }
                opcion= 0;
            }
            else
            {
                printf("\nEl legajo no existe.\n");
            }

            break;

        case 4:
            printf("\n--LISTA DE EMPLEADOS--\n\n");
            mostrarListaEmpleados(lista, T);
            printf("\n--FIN DE LA LISTA DE EMPLEADOS--\n");
            break;

        case 5:
            opcion= menuDeOpciones("\n1.Ordenar por Legajo\n2.Ordenar por Nombre\n3.Ordenar por Sexo\n4.Ordenar por Sueldo Bruto\n5.CANCELAR.\n\nElija opcion: ",1,5);

            switch (opcion)
            {
            case 1:
                ordenarPorLegajoAsc(lista,T);
                printf("\nEmpleados ordenados por legajo.\n\n");
                break;
            case 2:
                ordenarPorNombreAsc(lista,T);
                printf("\nEmpleados ordenados por nombre.\n\n");
                break;
            case 3:
                ordenarPorSexoAsc(lista,T);
                printf("\nEmpleados ordenados por sexo.\n\n");
                break;
            case 4:
                ordenarPorSueldoBruto(lista,T);
                printf("\nEmpleados ordenados por sueldo bruto.\n\n");
                break;
            case 5:
                printf("\nNo se ordenaron los empleados.\n\n");
                break;
            }

            mostrarListaEmpleados(lista,T);
            opcion= 0;
            break;
        case 6:
            printf("\nSaliendo del sistema.\n");
            break;
        }

        printf("\n");
        system("pause");
        system("cls");

    }
    while(opcion!=6);

    return 0;
}
