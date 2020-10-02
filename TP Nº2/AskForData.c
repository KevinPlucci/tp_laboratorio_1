#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "AskForData.h"

int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s", mensaje);
    scanf("%d", &numeroEntero);
    numeroEntero = validacionDeEnterosPositivos(numeroEntero);
    return numeroEntero;
}

int validacionDeEnterosPositivos(int num1)
{
    int auxNum = num1;
    while(auxNum < 0)
    {
        auxNum = pedirEntero("Error! Reingrese un valor positivo: ");
    }
    return auxNum;
}

float pedirFlotante(char mensaje[])
{
    float numeroFlotante;
    printf("%s", mensaje);
    scanf("%f", &numeroFlotante);
    numeroFlotante = validacionDeFlotantesPositivos(numeroFlotante);
    return numeroFlotante;
}

float validacionDeFlotantesPositivos(float num1)
{
    float auxNum = num1;
    while(auxNum < 0)
    {
        auxNum = pedirFlotante("Error! Reingrese un valor positivo: ");
    }
    return auxNum;
}

char pedirCaracter(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = validacionCaracterSN(respuesta);
    return respuesta;
}

char validacionCaracterSN(char caracter)
{
    char auxCaracter = caracter;
    auxCaracter = tolower(auxCaracter);
    while(auxCaracter != 's' && auxCaracter != 'n')
    {
        auxCaracter = pedirCaracter("Error! Reingrese una opcion valida: ");
    }
    return auxCaracter;
}

void pedirCadena(char mensaje[], char cadena[], int tamCadena)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarCadena("cadena: ", cadena, tamCadena);
}

void validarCadena(char mensajeError[], char cadena[], int tamCadena)
{
    char auxCadena[100];
    strcpy(auxCadena, cadena);
    while(strlen(auxCadena)>tamCadena)
    {
        fflush(stdin);
        pedirCadena("Reingrese: ", auxCadena, 21);
    }
    strcpy(cadena, auxCadena);
}
