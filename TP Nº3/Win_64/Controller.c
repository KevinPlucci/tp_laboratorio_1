#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pInput.h"
#define PATHT "data.csv"
#define PATHB "data.dat"
#define MAT miArchivoT
#define MAB miArchivoB

//Base de controller
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int status = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* MAT;
        MAT = fopen(path, "r");
        parser_EmployeeFromText(MAT, pArrayListEmployee);
        fclose(MAT);
        status = 1;
    }
    return status;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* MAB;
        FILE* MAT;
        MAT = fopen(PATHT, "r");
        parser_EmployeeFromText(MAT, pArrayListEmployee);
        fclose(MAT);

        MAB = fopen(PATHB, "wb");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            Employee* aux;
            aux = ll_get(pArrayListEmployee, i);
            fwrite(aux, sizeof(Employee),1,miArchivoB);
        }
        fclose(MAB);

        MAB = fopen(PATHB, "rb");
        parser_EmployeeFromBinary(MAB, pArrayListEmployee);
        fclose(MAB);
        status = 1;
    }
    return status;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* e1 = employee_new();
    if(pArrayListEmployee != NULL)
    {
        puts("Id generado correctamente!");
        id = (ll_len(pArrayListEmployee) + 1);
        get_String(nombre, "Ingrese nombre: ");
        get_Int(&horasTrabajadas, "Ingrese cantidad de horas trabajadas: ");
        get_Int(&sueldo, "Ingrese sueldo: ");
        employee_setId(e1, id);
        employee_setNombre(e1, nombre);
        employee_setHorasTrabajadas(e1, horasTrabajadas);
        employee_setSueldo(e1, sueldo);
        ll_add(pArrayListEmployee, e1);
        status = 1;
    }
    return status;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    int option;
    char seguir = 's';
    Employee* aux;
    get_Int(&id, "Ingrese el id del empleado que desea modificar: ");
    aux = ll_get(pArrayListEmployee, (id-1));
    if(aux != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            get_Int(&option, "1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nIngrese una opcion: ");
            switch(option)
            {
            case 1:
                get_String(aux->nombre, "Ingrese el nuevo nombre: ");
                break;
            case 2:
                get_Int(&(aux->horasTrabajadas), "Ingrese la nueva cantidad de horas trabajadas: ");
                break;
            case 3:
                get_Int(&(aux->sueldo), "Ingrese el nuevo sueldo: ");
                break;
            case 4:
                return 1;
                break;
            default:
                puts("Opcion invalida! Reingrese");
                break;
            }
        }
        while(seguir == 's');
        status = 1;
    }
    else{
        status = 2;
    }
    return status;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    char respuesta;
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        get_Int(&id, "Ingrese el id del empleado que desea borrar: ");
        aux = ll_get(pArrayListEmployee, (id-1));
        if(aux != NULL)
        {
            printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
            get_Char(&respuesta, "Desea eliminar el empleado mostrado anteriormente?");
            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee, (id-1));
                status = 1;
            }else
            {
                status = 2;
            }
        }else
        {
            status = 3;
        }

    }
    return status;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
            status = 1;
        }
    }
    return status;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int (*pFunc)(Employee*,Employee*);
    pFunc = employee_compareByName;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, pFunc, 1);
        status = 1;
    }
    return status;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    char respuesta;
    Employee* aux;
    FILE* MAT;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        get_Char(&respuesta, "Desea guardar los cambios realizados?...");
        if(respuesta == 's')
        {
            MAT = fopen(path, "w");
            fprintf(MAT, "id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                fprintf(MAT, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
            }
            fclose(MAT);
            status = 1;
        }else
        {
            status = 3;
        }
    }
    return status;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    char respuesta;
    Employee* aux;
    FILE* MAB;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        get_Char(&respuesta, "Desea guardar los cambios realizados?...");
        if(respuesta == 's')
        {
            MAB = fopen(path, "wb");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                aux = ll_get(pArrayListEmployee, i);
                fwrite(aux, sizeof(Employee), 1, MAB);
            }
            fclose(MAB);
            status = 1;
        }else
        {
            status = 3;
        }
    }
    return status;
}

