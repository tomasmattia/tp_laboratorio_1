#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("1- CARGAR DESTINATARIOS\n");
    printf("2- CARGAR LISTA NEGRA\n");
    printf("3- DEPURAR\n");
    printf("4- LISTA\n");
    printf("5- SALIR\n");
}

int cargarListaDestinatarios(char* nombreArchivo,ArrayList* listaDestinatarios)
{
    FILE *fp;
    int returnAux=-1;
    char nombre[50]="";
    char mail[150]="";
    fp = fopen(nombreArchivo,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            eDestinatario* unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario*));

            fscanf(fp,"%[^,],%[^\n]\n",nombre,mail);

            strcpy(unDestinatario->nombre,nombre);
            strcpy(unDestinatario->mail,mail);
            if(unDestinatario!=NULL)
            {
                listaDestinatarios->add(listaDestinatarios,unDestinatario);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
};

void mostrarUnDestinatario(eDestinatario* unDestinatario)
{
    printf("NOMBRE: %s / MAIL: %s\n",unDestinatario->nombre,unDestinatario->mail);
}

void mostrarListaDestinatarios(ArrayList* listaDestinatarios)
{
    int i;
    for(i=0;i<listaDestinatarios->size;i++)
    {
        mostrarUnDestinatario(listaDestinatarios->pElements[i]);
    }
}
