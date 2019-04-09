/** \brief Función que concatena dos cadenas (eliminando el
           caracter '\n' previo al caracter '\0') y separándolas
           por ", "
 *
 * \param char[] Cadena resultante
 * \param char[] Primera cadena
 * \param char[] Segunda cadena
 * \return void
 *
 */
void concatenar(char[], char[], char[]);

/** \brief Función que reemplaza el caracter '\n'
           con el caracter '\0' de una cadena
 *
 * \param char[] Cadena a editar por la función
 * \return void
 *
 */
void eliminarEnter(char[]);

/** \brief Función que formatea la cadena: la pasa a minúsculas
           y luego la primer letra de cada palabra (separada por
           espacios) a mayúscula
 *
 * \param char[] Cadena a editar
 * \return void
 *
 */
void formatear(char[]);
