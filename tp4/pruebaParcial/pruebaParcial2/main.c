#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    int opcion;
    char* nombreArchivo=(char*)malloc(sizeof(char)*50);
    ArrayList* listaDestinatarios=al_newArrayList();
    ArrayList* blackList=al_newArrayList();
    ArrayList* listaDepurada=al_newArrayList();
    char respuesta='s';
    do
    {
        opcion=0;
        menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                strcpy(nombreArchivo,"destinatarios.csv");


                if(cargarListaDestinatarios(nombreArchivo,listaDestinatarios)==0)
                {
                    printf("La lista de destinatarios se cargo con exito\n");
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                mostrarListaDestinatarios(listaDestinatarios);
                break;
            case 5:
                respuesta='n';
                break;
            default:
                break;
        }
        system("pause");
        system("cls");
    }
    while(respuesta!='n');
    return 0;
}
