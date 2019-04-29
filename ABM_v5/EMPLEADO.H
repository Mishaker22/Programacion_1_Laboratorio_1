#define LIBRE 0
#define OCUPADO 1
#define TAM_NOMBRE 20

//#include "Entradas.h"

typedef struct{
    int legajo;
    char nombre[TAM_NOMBRE];
    char sexo;
    int idSector;
    int cantHoras;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

typedef struct
{
    int idSector;
    char descripcion[20];
    float valorHora;
} eSector;


typedef struct{
    int idSector;
    int cantEmpleados;
    float acumSueldoBruto;
}eSectorAux;


void hardcodearDatosSectores(eSector[], int);
void mostrarListaSectores(eSector[], int);
int validarSector(int, eSector[], int);
int pedirSector(char[], eSector[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int, eSector[], int);
int buscarLibre(eEmpleado[], int);
void cargarEmpleado(eEmpleado[], int, eSector[], int);
int buscarLegajo(eEmpleado[], int, int);

void mostrarEmpleado(eEmpleado, eSector[], int);

void mostrarListaEmpleados(eEmpleado[], int, eSector[], int);

void bajaEmpleado(eEmpleado[], int, eSector listaSectores[], int, char[]);
void modificarNombre(eEmpleado[], int);
void modificarSexo(eEmpleado[], int);
void actualizarSalario(eEmpleado[], int, eSector[], int);
void modificarSector(eEmpleado[], int, eSector[], int);
void modificarCantHoras(eEmpleado[], int, eSector[], int);
void modificarEmpleado(eEmpleado[], int, eSector[], int, char[]);

void mostrarCantEmpleadosPorSector(eEmpleado[], int, eSector[], int);


void mostrarEmpleadosPorSector(eEmpleado[], int, eSector[], int);


void mostrarSueldosPorSector(eEmpleado[], int, eSector[], int);
int contarEmpleadosPorSector(eEmpleado[], int, eSector);
//void modificar(eEmpleado[], int, int);



int buscarLegajo(eEmpleado[], int, int);
float buscarSueldoMaximo(eEmpleado[],int);
void mostrarEmpleadosSueldoMaximo(eEmpleado[],int);
int contarCarlos(eEmpleado[],int);
void mostrarSectorConMasEmpleados(eEmpleado[], int, eSector[], int);
