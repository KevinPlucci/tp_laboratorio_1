#include <stdio.h>
#include <stdlib.h>
int pedirOpciones(char texto[])
{
    int opcion;

    printf("%s" , texto);
    scanf("%d" , &opcion);
    return opcion;
}
float pedirOperandos(char texto[])
{
    float operandos;

    printf("%s" , texto);
    scanf("%f" , &operandos);
    return operandos;
}
float sumaOperandos(float operando1, float operando2)
{
    float suma;
    suma = operando1 + operando2;
    return suma;
}
float restaOperandos(float operando1 , float operando2)
{
    float resta;
    resta = operando1 - operando2;
    return resta;
}
float divisionOperandos(float operando1 , float operando2)
{
    float division;
    division = operando1 / operando2;
    return division;
}
float multiplicacionOperandos(float operando1, float operando2)
{
    float multiplicacion;
    multiplicacion = operando1 * operando2;
    return multiplicacion;
}
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
