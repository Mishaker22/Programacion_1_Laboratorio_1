/** \brief Función que solicita un número real
 *
 * \param mensaje[] Lo que representa el número que se solicita
 * \return float Número ingresado.
 *
 */
float pedirFloat(char mensaje[]);


/** \brief Función que solicita un número real dentro de un rango
 *
 * \param mensaje[] Lo que representa el número que se solicita
 * \param minimo float Número menor admitido
 * \param maximo float Número mayor admitido
 * \return float Número ingresado y validado según el rango
 *
 */
float pedirFloatRango(char mensaje[], float minimo, float maximo);


/** \brief Función que solicita un número entero
 *
 * \param mensaje[] Lo que representa el número que se solicita
 * \return int Número ingresado
 *
 */
int pedirEntero(char mensaje[]);


/** \brief Función que solicita un número entero dentro de un rango
 *
 * \param mensaje[] Lo que representa el número que se solicita
 * \param minimo int Número menor admitido
 * \param maximo int Número mayor admitido
 * \return int Número ingresado y validado según el rango
 *
 */
int pedirEnteroRango(char mensaje[], int minimo, int maximo);


/** \brief Función que solicita un caracter
 *
 * \param mensaje[] char Lo que representa el caracter
 * \return char Caracter ingresado
 *
 */
char pedirCaracter(char mensaje[]);


/** \brief Función que solicita un caracter y lo valida (f,F,m,M)
 *
 * \param mensaje[] char Lo que representa el caracter
 * \return char Caracter ingresado
 *
 */
char pedirCaracterSexo(char mensaje[]);


/** \brief Función que valida una cadena según un tamaño
 *
 * \param mensaje[] char Lo que representa la cadena
 * \param cadena[] char Cadena a validar
 * \param tam int Tamaño máximo de caracteres -1
 * \return void
 *
 */
void validarTamCadena(char mensaje[], char cadena[], int tam);

/** \brief Función que solicita una cadena y la valida según un tamaño
 *
 * \param mensaje[] Lo que representa la cadena que se solicita
 * \param cadena[] La cadena validada según el rango
 * \param tam int La cantidad máxima de caracteres -1
 * \return void
 *
 */
void pedirCadena(char mensaje[], char cadena[], int tam);


/** \brief Función que solicita una palabra (sin espacios) y la valida según un tamáño
 *         mediante la utilización de la función validarTamCadena()
 *
 * \param mensaje[] char Lo que representa la palabra
 * \param cadena[] char Palabra validada
 * \param tam int La cantidad máxima de caracteres -1
 * \return void
 *
 */
void pedirPalabra(char mensaje[], char cadena[], int tam);
