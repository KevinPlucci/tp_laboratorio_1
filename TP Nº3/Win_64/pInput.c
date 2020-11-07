#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pInput.h"

int get_Int(int* pNum, char mUser[])
{
    int status = 0;
    if(pNum != NULL)
    {
        printf("%s", mUser);
        scanf("%d", pNum);
        while(*pNum < 0)
        {
            printf("Error! Reingrese un numero mayor a cero: ");
            scanf("%d", pNum);
        }
        status = 1;
    }
    return status;
}

int get_Float(float* pNum, char mUser[])
{
    int status = 0;
    if(pNum != NULL)
    {
        printf("%s", mUser);
        scanf("%f", pNum);
        status = 1;
    }
    return status;
}

int get_Char(char* pCarac, char mUser[])
{
    int status = 0;
    if(pCarac != NULL)
    {
        printf("%s", mUser);
        fflush(stdin);
        scanf("%c", pCarac);
        *pCarac = tolower(*pCarac);
        while(*pCarac != 's' && *pCarac != 'n')
        {
            printf("Error! Reingrese un caracter valido por favor (s/n): ");
            fflush(stdin);
            scanf("%c", pCarac);
            *pCarac = tolower(*pCarac);
        }
        status = 1;
    }
    return status;
}

int get_String(char* pString, char mUser[])
{
    int status = 0;
    if(pString != NULL)
    {
        printf("%s", mUser);
        fflush(stdin);
        scanf("%s", pString);
        while(strlen(pString) > 128)
        {
            printf("Error! Reingrese un nombre de menor rango de caracteres: ");
            fflush(stdin);
            scanf("%s", pString);
        }
        status = 1;
    }
    return status;
}

void pointer_error(int retorno, char null[], char exito[], char eCondicion[], char mErrorId[])
{
    if(retorno == 0)
    {
        printf("%s\n", null);
    }else if(retorno == 1)
    {
        printf("%s\n", exito);
    }else if(retorno == 2){
        printf("%s\n", eCondicion);
    }else
    {
        printf("%s\n", mErrorId);
    }
}

