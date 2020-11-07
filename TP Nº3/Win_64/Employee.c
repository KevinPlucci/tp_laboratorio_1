#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado = (Employee*)malloc(sizeof(Employee));
    return empleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empleado = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && empleado != NULL)
    {
        empleado->id = atoi(idStr);
        strcpy(empleado->nombre, nombreStr);
        empleado->horasTrabajadas = atoi(horasTrabajadasStr);
        empleado->sueldo = atoi(sueldoStr);
        return empleado;
    }else
    {
        return NULL;
    }
}

int employee_setId(Employee* this, int id)
{
    int status = 0;
    if(this != NULL)
    {
        this->id = id;
        status = 1;
    }
    return status;
}

int employee_getId(Employee* this, int* id)
{
    int status = 0;
    if(this != NULL && id != NULL)
    {
        id = &(this->id);
        status = 1;
    }
    return status;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int status = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        status = 1;
    }
    return status;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int status = 0;
    if(this != NULL && nombre != NULL)
    {
        nombre=this->nombre;
        status = 1;
    }
    return status;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int status = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        status = 1;
    }
    return status;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int status = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        horasTrabajadas = &(this->horasTrabajadas);
        status = 1;
    }
    return status;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int status = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        status = 1;
    }
    return status;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int status = 0;
    if(this != NULL && sueldo != NULL)
    {
        sueldo = &(this->sueldo);
        status = 1;
    }
    return status;
}

int employee_compareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}

