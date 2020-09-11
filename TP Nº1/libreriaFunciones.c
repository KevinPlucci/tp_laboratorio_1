#include <stdio.h>
#include <stdlib.h>

//Pedir Operaciones.
int pedirOpciones(char texto[])
{
    int opcion;

    printf("%s" , texto);
    scanf("%d" , &opcion);
    return opcion;
}
//Pedir Operando.
int pedirOperandos(char texto[])
{
    float operandos;

    printf("%s" , texto);
    scanf("%f" , &operandos);
    return operandos;
}
//Operaciones de suma.
int sumaOperandos(int operando1, int operando2)
{
    int suma;
    suma = operando1 + operando2;
    return suma;
}
//Operacion de resta.
int restaOperandos(int operando1 , int operando2)
{
    int resta;
    resta = operando1 - operando2;
    return resta;
}
//Operacion de division.
float divisionOperandos(int operando1 , int operando2)
{
    float division;
    division  = (float)operando1 / operando2;
    return division;
}
//Operacion de multiplicacion.
int multiplicacionOperandos(int operando1, int operando2)
{
    int multiplicacion;
    multiplicacion = operando1 * operando2;
    return multiplicacion;
}
//Operacion del Factorial.
long int factorialOperandos(int numero)
{
    long int factorial;
    if(numero == 0 || numero == 1)
    {
    factorial = 1;
    }else
    {
    factorial = numero * factorialOperandos(numero -1);
    }
    return factorial;
}
