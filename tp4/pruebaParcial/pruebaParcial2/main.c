#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    int opcion;
    char* nombreArchivo=(char*)malloc(sizeof(char*));
    ArrayList* listaDestinatarios=al_newArrayList();
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

                break;
            case 2:
                break;
            case 3:

                break;
            case 4:

                break;
            case 7:
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
