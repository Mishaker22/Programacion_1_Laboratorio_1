//#include <stdio.h>
//#include <stdlib.h>
#include "Empleado.h"
//#include "Entradas.h"
//#include "Menu.h"
#include "MenuEmpleados.h"

#define T 10

int main()
{

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);
    hardcodearDatosEmpleados(lista,4);
    menuEmpleados(lista,T);


    return 0;
}
