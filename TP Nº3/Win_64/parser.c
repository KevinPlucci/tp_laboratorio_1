#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define PATHT "data.csv"
#define PATHB "data.dat"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int status = 0;
    char id[100], nombre[100], horasTrabajadas[100], sueldo[100];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        while(!feof(pFile))
        {
            Employee* aux = employee_new();
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, aux);
        }
        status = 1;
    }
    return status;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int status = 0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile)-1)
        {
            Employee* aux = employee_new();
            fread(aux, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, aux);
        }
        status = 1;
    }
    return status;
}

