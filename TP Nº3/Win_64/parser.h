/** \brief Parsea los datos que estan en modo texto de un archivo .csv a cada tipo de dato del array de estructuras
 *
 * \param pFile FILE* Puntero al archivo donde se encuentra contenida la data
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados donde se cargaran los datos del archivo .csv
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
/** \brief Parsea los datos que estan en modo binario de un archivo .dat a cada tipo de dato del array de estructuras
 *
 * \param pFile FILE* Puntero al archivo donde se encuentra contenida la data
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados donde se cargaran los datos del archivo .dat
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);
