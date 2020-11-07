/** \brief Controla la carga del archivo en modo texto
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
/** \brief Controla la carga del archivo en modo binario
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornata 0
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);
/** \brief Controla la carga de un empleado a la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Controla la edicion de los datos de un empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, si no se encuentra al empleado retornara 2 y retornara 0 si es NULL el puntero a la lista
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Controla la baja de un empleado en la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, si se cancela la operacion retornara 2, si el id no existe en la lista retornara 3 y retornara 0 si es NULL el puntero a la lista
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Controla el listado de los empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Controla el ordenamiento de los empleados por orden alfabetico
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Controla el guardado en modo texto de la lista de empleados tras los cambios hechos por el usuario
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0PREGUNTAR SI DESEA GUARDAR POSTA O CANCELAR
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
/** \brief Controla el guardado en modo binario de la lista de empleados tras los cambios hechos por el usuario
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Punterio a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0PREGUNTAR SI DESEA GUARDAR POSTA O CANCELAR
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
