#define TAM_NOMBRE 20
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[TAM_NOMBRE];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

void mostrarEmpleado(eEmpleado);
void cargarEmpleado(eEmpleado[], int);
void mostrarListaEmpleados(eEmpleado[], int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int);

int buscarLegajo(eEmpleado[],int, int);
void modificarSueldoBruto(eEmpleado[], int);
void modificarNombre(eEmpleado[], int);
void modificarSexo(eEmpleado[], int);
void bajaEmpleado(eEmpleado[], int);

void ordenarPorLegajoAsc(eEmpleado[], int);
void ordenarPorLegajoDes(eEmpleado[], int);

void ordenarPorSueldoBruto(eEmpleado[], int);
void ordenarPorNombreAsc(eEmpleado[], int);
void ordenarPorNombreDes(eEmpleado[], int);
void ordenarPorSexoAsc(eEmpleado[], int);
void ordenarPorSexoDes(eEmpleado[], int);
