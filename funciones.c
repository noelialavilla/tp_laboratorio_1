#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "funciones.h"

void inicioCalculadora()
{
    int opcion;
    int primerOperando;
    int segundoOperando;
    int resSuma;
    int resResta;
    float resDiv;
    int resMultiplicacion;
    int resFactorialX;
    int resFactorialY;

    int triggerPrimerOperando =0;
    int triggerSegundoOperando =0;
    int triggerOperacionesRealizadas = 0;

    opcion = imprimirMenuPrincipal();
    do
    {
        switch(opcion)
        {
        case 1:
            primerOperando = ingresarOperando();
            triggerPrimerOperando = 1;
            opcion = imprimirSubmenuPrimerOperando(primerOperando);
            break;

        case 2:
            if (triggerPrimerOperando)
            {
                segundoOperando = ingresarOperando();
                triggerSegundoOperando = 1;
                opcion = imprimirSubmenuAmbosOperandos(primerOperando,segundoOperando);
            }
            else
            {
                printf("\n  Primero debe ingresar el 1\247 operando! \n");
                system("pause");
                opcion = imprimirMenuPrincipal();
            }

            break;

        case 3:

            if (triggerPrimerOperando && triggerSegundoOperando)
            {
                resSuma =sumar(primerOperando,segundoOperando);
                resResta = restar(primerOperando,segundoOperando);
                resDiv = dividir(primerOperando,segundoOperando);
                resMultiplicacion = multiplicar(primerOperando,segundoOperando);
                resFactorialX = factorial(primerOperando);
                resFactorialY = factorial(segundoOperando);
                triggerOperacionesRealizadas = 1;
                Sleep(1000);
                printf(" Realizando operaciones...\n\n");
                Sleep(1500);
                printf(" Operaciones realizadas con exito! \n");
                opcion = imprimirSubmenuAmbosOperandos(primerOperando,segundoOperando);
            }
            else
            {
                printf("\n  No puede realizar las operaciones si aun no ha ingresado los dos numeros! \n  Por favor, elija otra opcion.\n");
                if (triggerPrimerOperando)
                {
                    opcion = imprimirSubmenuPrimerOperando(primerOperando);
                }
                else
                {
                    system("pause");
                    opcion = imprimirMenuPrincipal();
                }

            }
            break;

        case 4:
            if (triggerPrimerOperando && triggerSegundoOperando)
            {
                if (triggerOperacionesRealizadas)
                {
                    mostrarResultados(primerOperando,segundoOperando,resSuma,resResta,resDiv,resMultiplicacion,resFactorialX,resFactorialY);
                    opcion = imprimirSubmenuAmbosOperandos(primerOperando,segundoOperando);
                }
                else
                {
                    printf("\n  Para mostrar los resultados de las operaciones, primero debe realizarlas. (Opcion 3) \n");
                    opcion = imprimirSubmenuAmbosOperandos(primerOperando,segundoOperando);
                }
            }
            else
            {
                printf("\n  No pueden mostrar los resultados si aun no ha ingresado los dos numeros! \n  Por favor, elija otra opcion.\n");
                system("pause");
                opcion = imprimirMenuPrincipal();
            }
            break;

        case 5:
            break;

        case 6:
            resetTrigger(&triggerPrimerOperando);
            resetTrigger(&triggerSegundoOperando);
            resetTrigger(&triggerOperacionesRealizadas);
            system("pause");
            opcion = imprimirMenuPrincipal();
            break;

        default:
            printf("\n Dato ingresado erroneo, por favor, elija una opcion valida. \n\n");
            if (triggerPrimerOperando)
            {
                if (triggerSegundoOperando)
                {
                    opcion = imprimirSubmenuAmbosOperandos(primerOperando,segundoOperando);
                }
                else
                {
                    opcion = imprimirSubmenuPrimerOperando(primerOperando);
                }

            }
            else
            {
                system("pause");
                opcion = imprimirMenuPrincipal();
            }
            break;

        }

    }
    while(opcion!=5);
}

// Impresión de menu principal
int imprimirMenuPrincipal()
{
    int opcion;

    system("cls");
    printf("  __________________________________________________________ \n");
    printf(" |                                                          |\n");
    printf(" |                       Bienvenido!                        |\n");
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf(" |                       CALCULADORA                        |\n");
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf(" |                    MENU DE OPCIONES                      |\n");
    printf(" |                                                          |\n");
    printf(" |          1 - Ingreso de 1\247 operando.    A=X              |\n");
    printf(" |          2 - Ingreso de 2\247 operando.    B=Y              |\n");
    printf(" |          3 - Realizar operaciones matematicas:           |\n");
    printf(" |                                                          |\n");
    printf(" |                      SUMA  --->  A+B                     |\n");
    printf(" |                     RESTA  --->  A-B                     |\n");
    printf(" |            MULTIPLICACION  --->  A*B                     |\n");
    printf(" |                  DIVISION  --->  A/B                     |\n");
    printf(" |                 FACTORIAL  --->  A!|B!                   |\n");
    printf(" |                                                          |\n");
    printf(" |          4 - Mostrar resultados de las operaciones.      |\n");
    printf(" |          5 - Salir.                                      |\n");
    printf(" |          6 - Realizar un nuevo ingreso.                  |\n");
    printf(" |__________________________________________________________|\n");
    printf("                Ingrese opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

// Impresión Submenu cuando tenemos el primer operando ingresado
int imprimirSubmenuPrimerOperando(int primerOperando)
{
    int opcion;

    system("pause");
    system("cls");

    printf("  __________________________________________________________ \n");
    printf(" |                                                          |\n");
    printf(" |                       CALCULADORA                        |\n");
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf("                Primer operando:     A=%d                    \n",primerOperando);
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf(" |                    MENU DE OPCIONES                      |\n");
    printf(" |                                                          |\n");
    printf(" |          2 - Ingreso de 2\247 operando.    B=Y              |\n");
    printf(" |          3 - Realizar operaciones matematicas:           |\n");
    printf(" |                                                          |\n");
    printf(" |                      SUMA  --->  A+B                     |\n");
    printf(" |                     RESTA  --->  A-B                     |\n");
    printf(" |            MULTIPLICACION  --->  A*B                     |\n");
    printf(" |                  DIVISION  --->  A/B                     |\n");
    printf(" |                 FACTORIAL  --->  A!|B!                   |\n");
    printf(" |                                                          |\n");
    printf(" |          4 - Mostrar resultados de las operaciones.      |\n");
    printf(" |          5 - Salir.                                      |\n");
    printf(" |          6 - Realizar un nuevo ingreso.                  |\n");
    printf(" |__________________________________________________________|\n");
    printf("                Ingrese opcion deseada: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

// Impresión Submenu cuando tenemos los dos operandos ingresados
int imprimirSubmenuAmbosOperandos(int primerOperando, int segundoOperando)
{
    int opcion;

    system("pause");
    system("cls");

    printf("  __________________________________________________________ \n");
    printf(" |                                                          |\n");
    printf(" |                       CALCULADORA                        |\n");
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf("                A=%d                  B=%d                   \n",primerOperando,segundoOperando);
    printf(" |__________________________________________________________|\n");
    printf(" |                                                          |\n");
    printf(" |                    MENU DE OPCIONES                      |\n");
    printf(" |                                                          |\n");
    printf(" |          3 - Realizar operaciones matematicas:           |\n");
    printf(" |                                                          |\n");
    printf(" |                      SUMA  --->  A+B                     |\n");
    printf(" |                     RESTA  --->  A-B                     |\n");
    printf(" |            MULTIPLICACION  --->  A*B                     |\n");
    printf(" |                  DIVISION  --->  A/B                     |\n");
    printf(" |                 FACTORIAL  --->  A!|B!                   |\n");
    printf(" |                                                          |\n");
    printf(" |          4 - Mostrar resultados de las operaciones.      |\n");
    printf(" |          5 - Salir.                                      |\n");
    printf(" |          6 - Realizar un nuevo ingreso.                  |\n");
    printf(" |__________________________________________________________|\n");
    printf("                Ingrese opcion deseada: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}
//*******************************************************************************/
// Ingreso de operandos
int ingresarOperando()
{
    char operando[9];
    fflush(stdin);
    printf("                Ingrese operando: ");
    scanf("%s",operando);

    while (esNumerico(operando)!=1 || strlen(operando)>9)
    {
        printf("            Error. El dato ingresado es incorrecto.\n                Por favor, ingrese un numero: ");
        scanf("%s",operando);
    }

    return atoi(operando);
}

//*******************************************************************************/
// Valida que el dato ingresado sea un número
int esNumerico(char dato[])
{
    for (int i=0; i<strlen(dato); i++)
    {
        if(isdigit(dato[i])!=1 && dato[i]!='-' && dato[i]!='+')
        {
            return 0;
        }
    }
    return 1;

}
//*******************************************************************************/
// Muestra resultados por pantalla
void mostrarResultados(int a, int b, int resSuma, int resResta, float resDiv,int resMultiplicacion,int resFactorialA,int resFactorialB)
{
    printf("------------------------------------------------------------\n");
    printf("|                       RESULTADOS                         |\n");
    printf("------------------------------------------------------------\n");
    printf("  El resultado de %d + %d es %d\n",a,b,resSuma);
    printf("  El resultado de %d - %d es %d\n",a,b,resResta);

    if (resDiv == 0)
    {
        printf("  La division entre %d y %d no se realizo ya que no es posible dividir por cero.\n",a,b);
    }
    else
    {
        printf("  El resultado de %d / %d es %.2f \n",a,b,resDiv);
    }
    printf("  El resultado de %d * %d es %d \n",a,b,resMultiplicacion);
    mostrarResultadosFactoreo(a,resFactorialA);
    mostrarResultadosFactoreo(b,resFactorialB);



}

//*******************************************************************************/
// Muestra resultados de factoreo
void mostrarResultadosFactoreo(int numero, int factorial)
{
    switch(factorial)
    {
    case 0:
        printf("  No se pudo realizar el factorial del numero ingresado (%d) \n  ya que se trata de un numero negativo. \n",numero);
        break;
    case -1:
        printf("  No se puede mostrar el factorial de %d ya que su longitud \n  es mayor a la que se puede mostrar en esta calculadora.\n",numero);
        printf("  Esta calculadora solo puede mostrar el factorial de \n  numeros menores a 13.\n\n");
        break;
    default:
        printf("  El factorial de %d es: %d. \n",numero,factorial);
        break;
    }

}

//*******************************************************************************/
// Suma de numeros

int sumar(int primerSumando, int segundoSumando)
{
    int resultado;
    resultado = primerSumando + segundoSumando;
    return resultado;
}

//*******************************************************************************/
// Resta de numeros

int restar(int minuendo, int sustraendo)
{
    int resultado;
    resultado = minuendo - sustraendo;
    return resultado;
}

//*******************************************************************************/
// Multiplicacion entre numeros

int multiplicar(int primerFactor, int segundoFactor)
{
    int resultado;
    resultado = primerFactor * segundoFactor;
    return resultado;
}
//*******************************************************************************/
// Division entre numeros

float dividir(int dividendo, int divisor)
{
    float resultado;
    if (divisor!=0)
    {
        resultado = (float) dividendo/divisor;
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}
//*******************************************************************************/
// Factorial

int factorial (int numero)
{
    int resultado=1;

    if (numero<0)
    {
        resultado =0;
    }
    else if(numero>12)
    {
        resultado=-1;
    }
    else
    {
        while (numero>=1)
        {
            resultado *= numero;
            numero --;
        }
    }

    return resultado;

}
//*******************************************************************************/
// Resetea triggers
void resetTrigger(int* p)
{
    *p=0;
}
