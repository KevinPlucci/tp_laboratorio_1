/** \brief Solicita el ingreso de un numero entero al usuario
 *
 * \param char[] Mensaje que le indica que ingresar al usuario
 * \return int Retorna el numero ingresado por el usuario
 *
 */
int pedirEntero(char[]);
/** \brief Validar el correcto ingreso de un numero entero positivo
 *
 * \param int El numero ingresado previamente por el usuario
 * \return int Retorna el numero entero validado
 *
 */
int validacionDeEnterosPositivos(int);
/** \brief Solicita el ingreso de un numero flotante al usuario
 *
 * \param char[] Mensaje que le indica que ingresar al usuario
 * \return float Retorna el numero ingresado por el usuario
 *
 */
float pedirFlotante(char[]);
/** \brief Validar el correcto ingreso de un numero flotante positivo
 *
 * \param float El numero ingresado previamente por el usuario
 * \return float Retorna el numero flotante validado
 *
 */
float validacionDeFlotantesPositivos(float);
/** \brief Solicita el ingreso de un caracter al usuario
 *
 * \param char[] Mensaje que le indica que ingresar al usuario
 * \return char Retorna el caracter ingresado por el usuario
 *
 */
char pedirCaracter(char[]);
/** \brief Validar el correcto ingreso del caracter
 *
 * \param char El caracter ingresado previamente por el usuario
 * \return char Retorna el caracter validado
 *
 */
char validacionCaracterSN(char);
/** \brief Solicita el ingreso de una cadena de caracteres al usuario
 *
 * \param char[] Mensaje que le indica que ingresar al usuario
 * \param char[] Array de tipo char donde se almacenara la cadena ingresada por el usuario
 * \param int Tamaño del array
 * \return void
 *
 */
void pedirCadena(char[], char[], int);
/** \brief Validar el correcto ingreso del tamaño de la cadena
 *
 * \param char[] Mensaje de error que vuelve a solicitar el ingreso de la cadena de ser necesario
 * \param char[] Array de tipo char ingresado previamente por el usuario
 * \param int Tamaño del array
 * \return void
 *
 */
void validarCadena(char[], char[], int);
