#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    float numeroA=0;
    float numeroB=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numeroA);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numeroB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresar 1er operando: ");
                scanf("%f",&numeroA);
                break;
            case 2:
                printf("Ingresar 2er operando: ");
                scanf("%f",&numeroB);
                break;
            case 3:+
                printf("Suma: %f\n",suma(numeroA,numeroB));
                break;
            case 4:
                printf("Resta: %f\n",resta(numeroA,numeroB));
                break;
            case 5:
                if(numeroB==0){
                    printf("Syntax Error\n");
                }
                else{
                printf("Division: %.2f\n",division(numeroA,numeroB));
                }
                break;
            case 6:
                printf("Multiplicacion: %f\n",multiplicacion(numeroA,numeroB));
                break;
            case 7:
                if(numeroA<0)
                {
                    printf("No hay factoriales de negativos\n");
                }
                else{
                    if(factorial(numeroA)==0)
                    {
                        printf("No hay factoriales de numeros con decimales");
                    }
                    else{
                        printf("Factorial de %f: %.0f\n",numeroA,factorial(numeroA));
                    }
                }
                break;
            case 8:
                printf("Suma: %f\n",suma(numeroA,numeroB));
                printf("Resta: %f\n",resta(numeroA,numeroB));
                if(numeroB==0){
                    printf("Syntax Error\n");
                }
                else{
                printf("Division: %.2f\n",division(numeroA,numeroB));
                }
                printf("Multiplicacion: %f\n",multiplicacion(numeroA,numeroB));
                if(numeroA<0){
                    printf("No hay factoriales de negativos\n");
                }
                else{
                    if(factorial(numeroA)==0)
                    {
                        printf("No hay factoriales de numeros con decimales");
                    }
                    else{
                        printf("Factorial de %f: %.0f\n",numeroA,factorial(numeroA));
                    }
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
        if(seguir=='n'){
            break;
        }
        printf("\n");
    }
    return 0;
}
