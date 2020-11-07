#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor en memoria dinamica de un empleado
 *
 * \return Employee* Retorna el puntero a la direccion de memoria con espacio para almacenar un empleado
 *
 */
Employee* employee_new();
/** \brief Carga los datos de los empleados que estan en modo texto al tipo de dato correspondiente
 *
 * \param idStr char* Recibe el id como cadena
 * \param nombreStr char* Recibe el nombre como una cadena
 * \param horasTrabajadasStr char* Recibe las horas trabajadas como una cadena
 * \param sueldoStr char* Recibe el sueldo como una cadena
 * \return Employee* Retorna el puntero al tipo de dato Employee con los datos cargados correctamente seteados
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
/** \brief Setea el Id de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int Id a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setId(Employee* this, int id);
/** \brief Trae el Id de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al Id
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getId(Employee* this, int* id);
/** \brief Setea el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero del nombre a cargar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setNombre(Employee* this, char* nombre);
/** \brief Trae el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getNombre(Employee* this, char* nombre);
/** \brief Setea la cantidad de horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int Cantidad de horas trabajadas a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
/** \brief Trae la cantidad de horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero a la cantidad de horas trabajadas
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
/** \brief Setea el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo int Sueldo a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setSueldo(Employee* this, int sueldo);
/** \brief Trae el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo int* Puntero al sueldo
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);
/** \brief Compara los empleados por orden alfabetico
 *
 * \param Employee* Puntero a un empleado
 * \param Employee* Puntero a otro empleado
 * \return int Retorna el entero en base a la comparacion realizada de los empleados
 *
 */
int employee_compareByName(Employee*, Employee*);
#endif // employee_H_INCLUDED
