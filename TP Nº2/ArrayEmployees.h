#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/** \brief Inicializa a todos los empleados en estado LIBRE
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void inicializarEmpleados(Employee[], int);
/** \brief Carga secuencial de los empleados
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void cargarEmpleado(Employee[], int);
/** \brief Busca espacio libre donde cargar un empleado
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return int Retorna el indice del espacio libre para cargar un empleado
 *
 */
int buscarLibre(Employee[], int);
/** \brief Genera un entero aleatorio para el Id de los empleados
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return int Retorna un Id aleatorio para un empleado
 *
 */
int generarNumeroRandom(Employee[], int);
/** \brief Valida que el Id de los empleados no se repita
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \param int Id generado anteriormente para comprobar su validacion
 * \return int Retorna el Id validado
 *
 */
int validacionNumeroRandom(Employee[], int, int);
/** \brief Modificar algun campo de un empleado
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void modificarEmpleado(Employee[], int);
/** \brief Elimina la informacion de un empleado y lo coloca en espacio LIBRE
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void borrarEmpleado(Employee[], int);
/** \brief Busca un empleado por su Id
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \param int Id a buscar
 * \return int Indice donde se encuentra almacenado el empleado con el Id ingresado
 *
 */
int buscarId(Employee[], int, int);
/** \brief Muestra la lista de los empleados que estan OCUPADOS
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void mostrarListaEmpleados(Employee[], int);
/** \brief Muestra un solo empleado que este OCUPADO
 *
 * \param Employee Un empleado
 * \return void
 *
 */
void mostrarEmpleado(Employee);
/** \brief Manipulacion de los nombres y apellidos de la estructura
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void utilizandoStrings(Employee[], int);
/** \brief Pasar a mayuscula la primera letra del nombre y apellido de cada empleado
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void pasarMayusculas(Employee[], int);
/** \brief Ordenar los empleados de menor a mayor segun su sector
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void ordenarListaEmpleados(Employee[], int);
/** \brief Ordenar los empleados alfabeticamente segun su apellido
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return void
 *
 */
void ordenarAlfabeticamente(Employee[], int);
/** \brief Suma todos los salarios de los empleados almacenados
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \return float Retorna el resultado de la suma de todos los salarios
 *
 */
float totalSalarios(Employee[], int);
/** \brief Sacar promedio de todos los salarios almacenados y mostrar cuantos empleados sobrepasan el promedio
 *
 * \param Employee[] Array que contiene todos los empleados
 * \param int Tamaño del array
 * \param float Total de los salarios para calcular promedio
 * \return float Retorna el resultado del promedio de todos los empleados
 *
 */
float promedioSalarios(Employee[], int, float);
