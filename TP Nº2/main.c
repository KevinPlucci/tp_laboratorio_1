#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "AskForData.h"
#define T 1000

int main()
{
    int opcion;
    int flag = 0;
    char seguir = 's';
    char mensaje[] = "Error! Para acceder a esta funcion debe cargar un empleado! \n";
    Employee lista[T];
    inicializarEmpleados(lista, T);
    do
    {
        opcion = pedirEntero("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\nElija una opcion: \n");
        switch(opcion)
        {
        case 1:
            printf("ALTAS\n");
            cargarEmpleado(lista,T);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                printf("MODIFICAR\n");
                modificarEmpleado(lista,T);
                break;
            }
            else
            {
                printf("%s", mensaje);
                break;
            }
        case 3:
            if(flag == 1)
            {
                printf("BAJA\n");
                borrarEmpleado(lista,T);
                break;
            }
            else
            {
                printf("%s", mensaje);
                break;
            }
        case 4:
            if(flag == 1)
            {
                printf("INFORMAR\n");
                ordenarListaEmpleados(lista,T);
                ordenarAlfabeticamente(lista,T);
                mostrarListaEmpleados(lista,T);
                printf("\n El total de los salarios es de: %.2f \n", totalSalarios(lista,T));
                printf("\n El promedio de los salarios es de: %.2f \n", promedioSalarios(lista,T,totalSalarios(lista,T)));
                break;
            }
            else
            {
                printf("%s", mensaje);
                break;
            }
        case 5:
            printf("Saliendo....");
            return 0;
            break;
        default:
            printf("Error! Reingrese una opcion valida!\n");
            break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }
    while(seguir == 's');
    return 0;
}
