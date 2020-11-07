/** \brief Solicita el ingreso de un numero entero al usuario
 *
 * \param int* Puntero a la direccion de memoria de la variable donde se guardara el numero ingresado
 * \param char[] Mensaje que le indica al usuario que debe ingresar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int get_Int(int*, char[]);
/** \brief Solicita el ingreso de un numero flotante al usuario
 *
 * \param float* Puntero a la direccion de memoria de la variable donde se guardara el numero ingresado
 * \param char[] Mensaje que le indica al usuario que debe ingresar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int get_Float(float*, char[]);
/** \brief Solicita el ingreso de un caracter al usuario
 *
 * \param char* Puntero a la direccion de memoria de la variable donde se guardara el caracter ingresado
 * \param char[] Mensaje que le indica al usuario que debe ingresar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int get_Char(char*, char[]);
/** \brief Solicita el ingreso de una cadena de caracteres al usuario
 *
 * \param char* Puntero a la direccion de memoria de la variable donde se guardara la cadena ingresada
 * \param char[] Mensaje que le indica al usuario que debe ingresar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contario retornana 0
 *
 */
int get_String(char*, char[]);
/** \brief Funcion que le permite al usuario saber el estado de las funciones que esta ejecutando en el programa en tiempo real
 *
 * \param int Es el entero retornado por cada funcion como status
 * \param char[] Mensaje Nº1 que le indica al usuario el estado de la funcion que intenta ejecutar
 * \param char[] Mensaje Nº2 que le indica al usuario el estado de la funcion que intenta ejecutar
 * \param char[] Mensaje Nº3 que le indica al usuario el estado de la funcion que intenta ejecutar
 * \param char[] Mensaje Nº4 que le indica al usuario el estado de la funcion que intenta ejecutar
 * \return void (Sin retorno)
 *
 */
void pointer_error(int, char[], char[], char[], char[]);
