#include <stdio.h>
#include <stdlib.h>
//Pido opciones.
int pedirOpciones(char texto[])
{
    int opcion;

    printf("%s" , texto);
    scanf("%d" , &opcion);
    return opcion;
}
//Pido operandos.
float pedirOperandos(char texto[])
{
    float operandos;

    printf("%s" , texto);
    scanf("%f" , &operandos);
    return operandos;
}
//Operacion de suma.
float sumaOperandos(float operando1, float operando2)
{
    float suma;
    suma = operando1 + operando2;
    return suma;
}
//Operacion de resta.
float restaOperandos(float operando1 , float operando2)
{
    float resta;
    resta = operando1 - operando2;
    return resta;
}
//Operacion de Division.
float divisionOperandos(float operando1 , float operando2)
{
    float division;
    division = operando1 / operando2;
    return division;
}
//Operacion de Multiplicacion.
float multiplicacionOperandos(float operando1, float operando2)
{
    float multiplicacion;
    multiplicacion = operando1 * operando2;
    return multiplicacion;
}
//Operacion de Factorizacion.
int factorialOperandos(int numero)
{
    int factorial;
    if(numero == 0 || numero == 1)
    {
    factorial = 1;
    }else
    {
    factorial = numero * factorialOperandos(numero -1);
    }
    return factorial;
}
