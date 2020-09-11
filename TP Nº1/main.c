#include <stdio.h>
#include <stdlib.h>
#include "libreriaFunciones.h"
int main()
{
    int operando1;
    int operando2;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int opcion;
    int factorial1;
    int factorial2;
    int flagX = 0;  //Banderas de X
    int flagY = 0;  //  """"   "  Y
    int flagCero = 0;
    int flagMenorCeroOP1 = 0; //Flag de menor a 0
    int flagMenorCeroOP2 = 0;
    int flagPos1 = 0 ;//Posiciones
    int flagPos2 = 0 ;
    char seguir = 's';

    //Reemplazo la X e Y por el numero asignado por el operando
    do{
        if(flagX == 0)
        {
             printf("1.Ingresar 1er operando (A=x)\n");
        }else
        {
            printf("1.Ingresar 1er operando (A=%d)\n" , operando1);
        }
        if(flagY == 0)
        {
            printf("2.Ingresar 2do operando (B=y)\n");
        }else
        {
            printf("2.Ingresar 2do operando (B=%d)\n" , operando2);
        }
        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");

        opcion = pedirOpciones("Ingrese una opcion por favor: ");

        //Menu.
        switch(opcion)
        {
            case 1:
                operando1 = pedirOperandos("1.Ingresar 1er operando: ");
                flagX = 1;
                if(operando1 < 0)
                {
                    flagMenorCeroOP1 = 1;
                }
                break;
            case 2:
                operando2 = pedirOperandos("2.Ingresar 2do operando: ");
                flagY = 1;
                if(operando2 < 0)
                {
                    flagMenorCeroOP2 = 1;
                }
                break;
            case 3:
                printf("Calculando las operaciones solicitadas... \n");
                suma = sumaOperandos(operando1 , operando2);
                resta = restaOperandos(operando1 , operando2);
                if(operando2 == 0)
                {
                    flagCero = 1;
                }else
                {
                    division = divisionOperandos(operando1 , operando2);
                }
                multiplicacion = multiplicacionOperandos(operando1 , operando2);
                if(flagMenorCeroOP1 == 0)
                {
                    factorial1 = factorialOperandos(operando1);
                }
                if(flagMenorCeroOP2 == 0)
                {
                    factorial2 = factorialOperandos(operando2);
                }

                break;
            case 4:
                printf("El resultado de A+B es: %d \n" , suma);
                printf("El resultado de A-B es: %d \n" , resta);
                if(flagCero == 1)
                {
                    printf("No es posible dividir por cero \n");
                }else
                {
                    printf("El resultado de A/B es: %.2f \n" , division);
                }
                printf("El resultado de A*B es: %d \n" , multiplicacion);

                flagPos1 = (int)  (operando1*10)  % 10 ;
                flagPos2 = (int)  (operando1*100) % 100 ;

                if ( flagPos1 == 0 && flagPos2  == 0  && flagMenorCeroOP1 == 0 )
                {
                  printf("El factorial de A es: %d \n" , factorial1);

                }

                else if(flagMenorCeroOP1 == 0)
                {
                    printf("No se puede calcular el factorial de un numero con decimales \n");
                }else
                {
                    printf("No se puede calcular el factorial de un negativo.\n");
                }

                flagPos1 =0;
                flagPos2 = 0 ;

                flagPos1 = (int)  (operando2*10)  % 10 ;
                flagPos2 = (int)  (operando2*100)  % 100 ;

               if ( flagPos1 == 0 && flagPos2  == 0  && flagMenorCeroOP2 == 0 )
                {
                    printf("El factorial de B es: %d \n" , factorial2);
                }else if(flagMenorCeroOP2 == 0)
                {
                    printf("No se puede calcular el factorial de un numero con decimales\n");
                }else
                {
                    printf("No se puede calcular el factorial de un numero negativo\n");
                }

                flagPos1 =0;
                flagPos2 = 0 ;

                break;
            case 5:
                return 0;
                break;
            default:
                printf("Error! No ha ingresado una opcion correcta. \n");
                break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }while(seguir == 's');
    return 0;
}
