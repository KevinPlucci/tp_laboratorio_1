/** \brief Pide un numero para seleccionar una opcion
 *
 * \param texto[] char Texto que guia al usuario
 * \return int La opcion que ingresa el usuario
 *
 */
int pedirOpciones(char texto[]);
/** \brief Pide al usuario un operando
 *
 * \param texto[] char Texto que indica al usuario que debe ingresar
 * \return float El numero ingresado por el usuario
 *
 */
int pedirOperandos(char texto[]);
/** \brief Suma de los operandos
 *
 * \param int El primer operando
 * \param int El segundo operando
 * \return int Resultado de la suma
 *
 */
int sumaOperandos(int, int);
/** \brief Resta de los operandos
 *
 * \param int El primer operando
 * \param int El segundo operando
 * \return int El resultado de la resta
 *
 */
int restaOperandos(int, int );
/** \brief Division de los operandos
 *
 * \param int Primer operando/dividendo
 * \param int Segundo operando/divisor
 * \return float El resultado de la division
 *
 */
float divisionOperandos(int, int);
/** \brief Multiplicacion de los operandos
 *
 * \param int El primer operando
 * \param int El segundo operando
 * \return int El resultado de la multiplicacion
 *
 */
int multiplicacionOperandos(int, int);
/** \brief El factorial de un numero
 *
 * \param int Un operando
 * \return int El resultado del factorial
 *
 */
long factorialOperandos(int);
