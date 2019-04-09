/** \brief Funci�n que concatena dos cadenas (eliminando el
           caracter '\n' previo al caracter '\0') y separ�ndolas
           por ", "
 *
 * \param char[] Cadena resultante
 * \param char[] Primera cadena
 * \param char[] Segunda cadena
 * \return void
 *
 */
void concatenar(char[], char[], char[]);

/** \brief Funci�n que reemplaza el caracter '\n'
           con el caracter '\0' de una cadena
 *
 * \param char[] Cadena a editar por la funci�n
 * \return void
 *
 */
void eliminarEnter(char[]);

/** \brief Funci�n que formatea la cadena: la pasa a min�sculas
           y luego la primer letra de cada palabra (separada por
           espacios) a may�scula
 *
 * \param char[] Cadena a editar
 * \return void
 *
 */
void formatear(char[]);
