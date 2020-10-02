#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "AskForData.h"

void inicializarEmpleados(Employee lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = LIBRE;
    }
}

void cargarEmpleado(Employee lista[], int tam)
{
    char respuesta = 's';
    int indice;
    while(respuesta == 's')
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay espacio para ingresar mas empleados! \n");
        }
        else
        {
            lista[indice].id = generarNumeroRandom(lista,tam);
            pedirCadena("Ingrese nombre: ", lista[indice].name, 51);
            pedirCadena("Ingrese apellido: ", lista[indice].lastName, 51);
            lista[indice].salary = pedirFlotante("Ingrese sueldo: ");
            lista[indice].sector = pedirEntero("Ingrese sector: ");
            lista[indice].isEmpty = OCUPADO;
            respuesta = pedirCaracter("Desea cargar mas empleados? s/n: ");
            if(respuesta != 's')
            {
                break;
            }
        }
    }

}

int buscarLibre(Employee lista[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int generarNumeroRandom(Employee lista[], int tam)
{
    int numero;
    srand(time(NULL));
    numero = rand();
    numero = validacionNumeroRandom(lista, tam, numero);
    return numero;
}

int validacionNumeroRandom(Employee lista[], int tam, int num1)
{
    int auxNum = num1;
    int i;
    for(i=0; i<tam; i++)
    {
        while(auxNum == lista[i].id)
        {
            auxNum = generarNumeroRandom(lista, tam);
        }
    }
    return auxNum;
}

void modificarEmpleado(Employee lista[], int tam)
{
    int id = pedirEntero("Ingrese el Id del empleado a buscar: ");
    int indice = buscarId(lista, tam, id);
    char respLista;
    int opcion;
    char respuesta;
    if(indice == -1)
    {
        printf("No se encontro el id solicitado! \n");
        respLista = pedirCaracter("Desea ver los empleados ingresados antes de completar esta operacion? \n");
        if(respLista == 's')
        {
            mostrarListaEmpleados(lista, tam);
        }
    }
    else
    {
        do
        {
            opcion = pedirEntero("1.Modificar nombre\n2.Modificar apellido\n3.Modificar salario\n4.Modificar sector\n5.Salir del menu\nElija una opcion: ");
            switch(opcion)
            {
            case 1:
                pedirCadena("Ingrese el nuevo nombre: ", lista[indice].name, 51);
                break;
            case 2:
                pedirCadena("Ingrese el nuevo apellido: ", lista[indice].lastName, 51);
                break;
            case 3:
                lista[indice].salary = pedirFlotante("Ingrese el nuevo salario: ");
                break;
            case 4:
                lista[indice].sector = pedirEntero("Ingrese el nuevo sector: ");
                break;
            case 5:
                printf("Saliendo de este menu...");
                break;
            default:
                printf("Error! Reingrese una opcion valida!\n");
                break;
            }
            respuesta = pedirCaracter("Desea modificar algun campo? s/n: ");
            system("pause");
            system("cls");
            fflush(stdin);
        }
        while(respuesta == 's');
    }
}

void borrarEmpleado(Employee lista[], int tam)
{
    int id = pedirEntero("Ingrese el Id del empleado a buscar: ");
    int indice = buscarId(lista, tam, id);
    char respuesta;
    if(indice == -1)
    {
        printf("No se encontro el id solicitado! \n");
        respuesta = pedirCaracter("Desea ver los empleados ingresados antes de completar esta operacion? \n");
        if(respuesta == 's')
        {
            mostrarListaEmpleados(lista, tam);
        }
    }
    else
    {
        respuesta = pedirCaracter("Estas seguro que quieres borrar a este empleado? \n");
        if(respuesta=='s')
        {
            lista[indice].isEmpty = LIBRE;
        }

    }
}

int buscarId(Employee lista[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarListaEmpleados(Employee lista[], int tam)
{
    int i;
    utilizandoStrings(lista,tam);

    printf("\n Id - Nombre - Apellido - Salario - Sector\n");
    printf("-------------------------------------------\n");

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {

            mostrarEmpleado(lista[i]);
        }
    }
}

void mostrarEmpleado(Employee unEmpleado)
{
    printf("%d--%s--%s--%.2f--%d \n", unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);
}

void utilizandoStrings(Employee lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        strlwr(lista[i].name);
        strlwr(lista[i].lastName);
    }
    pasarMayusculas(lista, tam);
}

void pasarMayusculas(Employee lista[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(j==0)
            {
                lista[i].name[j] = toupper(lista[i].name[j]);
                lista[i].lastName[j] = toupper(lista[i].lastName[j]);
            }
        }
    }
}

void ordenarListaEmpleados(Employee lista[], int tam)
{
    int i;
    int j;
    char auxCadenaLastName[51];
    int auxEnteroSector;
    int auxEnteroId;
    char auxCadenaName[51];
    float auxFlotanteSalary;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].sector>lista[j].sector && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
            {
                strcpy(auxCadenaLastName, lista[i].lastName);
                strcpy(lista[i].lastName, lista[j].lastName);
                strcpy(lista[j].lastName, auxCadenaLastName);

                auxEnteroSector = lista[i].sector;
                lista[i].sector = lista[j].sector;
                lista[j].sector = auxEnteroSector;

                auxEnteroId = lista[i].id;
                lista[i].id = lista[j].id;
                lista[j].id = auxEnteroId;

                strcpy(auxCadenaName, lista[i].name);
                strcpy(lista[i].name, lista[j].name);
                strcpy(lista[j].name, auxCadenaName);

                auxFlotanteSalary = lista[i].salary;
                lista[i].salary = lista[j].salary;
                lista[j].salary = auxFlotanteSalary;
            }
        }
    }
}

void ordenarAlfabeticamente(Employee lista[], int tam)
{
    int i,j;
    int auxEnteroId;
    int auxEnteroSector;
    float auxFlotanteSalary;
    char auxCadenaLastName[100];
    char auxCadenaName[100];
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO && lista[i].sector == lista[j].sector)
            {
                if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                {
                    strcpy(auxCadenaLastName, lista[i].lastName);
                    strcpy(lista[i].lastName, lista[j].lastName);
                    strcpy(lista[j].lastName, auxCadenaLastName);

                    strcpy(auxCadenaName, lista[i].name);
                    strcpy(lista[i].name, lista[j].name);
                    strcpy(lista[j].name, auxCadenaName);

                    auxEnteroSector = lista[i].sector;
                    lista[i].sector = lista[j].sector;
                    lista[j].sector = auxEnteroSector;

                    auxEnteroId = lista[i].id;
                    lista[i].id = lista[j].id;
                    lista[j].id = auxEnteroId;

                    auxFlotanteSalary = lista[i].salary;
                    lista[i].salary = lista[j].salary;
                    lista[j].salary = auxFlotanteSalary;
                    ordenarListaEmpleados(lista, tam);
                }
            }
        }
    }
}

float totalSalarios(Employee lista[], int tam)
{
    float totalSalarios = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            totalSalarios = totalSalarios + lista[i].salary;
        }
    }
    return totalSalarios;
}

float promedioSalarios(Employee lista[], int tam, float totalSalario)
{
    float promedioSalario = 0;
    int contadorEmpleados = 0;
    int cantidadEmpleadosMayorPromedio = 0;
    int i,j;
    totalSalario = totalSalarios(lista, tam);
    for(i=0; i<tam; i++)
    {
        contadorEmpleados++;
        if(lista[i].isEmpty == OCUPADO)
        {
            promedioSalario = totalSalario / contadorEmpleados;
        }
    }
    for(j=0; j<tam; j++)
    {
        if(lista[j].isEmpty == OCUPADO)
        {
            if(lista[j].salary > promedioSalario)
            {
                cantidadEmpleadosMayorPromedio++;
            }
        }
    }
    printf("\n La cantidad de empleados que superan el promedio de salario son: %d \n", cantidadEmpleadosMayorPromedio);
    return promedioSalario;
}
