#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "pInput.h"
#define PATHT "data.csv"
#define PATHB "data.dat"

int main()
{
    int option;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        get_Int(&option, "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario)\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario)\n10. Salir\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                pointer_error(controller_loadFromText(PATHT, listaEmpleados), "\nNo se ha podido completar la operacion solicitada\n", "\nDatos cargados correctamente\n", "", "");
                break;
            case 2:
                pointer_error(controller_loadFromBinary(PATHB, listaEmpleados), "\nNo se ha podido completar la operacion solicitada\n", "\nDatos cargados correctamente\n", "", "");
                break;
            case 3:
                pointer_error(controller_addEmployee(listaEmpleados), "\nNo se ha podido dar de alta al empleado solicitado\n", "\nEmpleado correctamente ingresado\n", "", "");
                break;
            case 4:
                pointer_error(controller_editEmployee(listaEmpleados), "\nNo se ha podido modificar el empleado correctamente\n", "\nSe ha modificado el empleado correctamente\n", "\nEl id ingresado no corresponde a ningun empleado en el sistema\n", "");
                break;
            case 5:
                pointer_error(controller_removeEmployee(listaEmpleados), "\nNo se ha podido dar de baja al empleado correctamente\n", "\nSe ha dado de baja al empleado correctamente\n", "\nOperacion de baja cancelada correctamente\n", "\nEl id ingresado no corresponde a ningun empleado en el sistema\n");
                break;
            case 6:
                pointer_error(controller_ListEmployee(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 7:
                pointer_error(controller_sortEmployee(listaEmpleados), "\nNo se ha podido ordenar los empleados correctamente\n", "\nOrdenamiento alfabetico de empleados correctamente ejecutado\n", "", "");
                break;
            case 8:
                pointer_error(controller_saveAsText(PATHT, listaEmpleados), "\nNo se ha podido guardar los cambios en el archivo data.csv (modo texto)\n", "\nSe han guardado correctamente todos los cambios en el archivo data.csv (modo texto)\n", "", "\nSe ha cancelado el guardado de los cambios\n");
                break;
            case 9:
                pointer_error(controller_saveAsBinary(PATHB, listaEmpleados), "\nNo se ha podido guardar los cambios en el archivo data.dat (modo binario)\n", "\nSe han guardado correctamente todos los cambios en el archivo data.dat (modo binario)\n", "", "\nSe ha cancelado el guardado de los cambios\n");
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                puts("\nLa lista de empleados ha sido eliminada correctamente...saliendo del programa!\n");
                system("pause");
                return 0;
                break;
            default:
                puts("\nError! No ha ingresado una opcion correcta. Por favor reingrese...\n");
                break;
        system("pause");
        system("cls");
        fflush(stdin);
        }
    }while(seguir == 's');
    return 0;
}

