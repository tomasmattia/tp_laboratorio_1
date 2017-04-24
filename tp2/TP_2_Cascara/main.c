#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 20

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    EPersona lista[MAX];
    for(i=0;i<MAX;i++)
    {
        strcpy(lista[i].nombre," ");
        lista[i].edad=0;
        lista[i].estado=0;
        lista[i].dni=0;
    }
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista);
                break;
            case 2:
                eliminarPersona(lista);
                break;
            case 3:
                mostrarOrdenado(lista);
                break;
            case 4:
                mostrarGrafico(lista);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("No es una opcion valida\n");
                break;
        }
    }

    return 0;
}
