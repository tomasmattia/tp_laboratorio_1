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

int cargarLista(char* nombreArchivo,ArrayList* listaParaCargar)
{
    FILE *fp;
    int returnAux=-1;
    char nombre[50]="";
    char mail[150]="";
    fp = fopen(nombreArchivo,"r");
    eDestinatario* unDestinatario;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario));
            if(unDestinatario!=NULL)
            {
                fscanf(fp,"%[^,],%[^\n]\n",nombre,mail);

                strcpy(unDestinatario->nombre,nombre);
                strcpy(unDestinatario->mail,mail);

                listaParaCargar->add(listaParaCargar,unDestinatario);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
}

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

void depurarLista(ArrayList* listaDestinatarios, ArrayList* blackList, ArrayList* listaDepurada)
{
    int i,j;
    int flagAdd=0;
    eDestinatario* destinatarioA;
    eDestinatario* destinatarioBlack;
    for(i=0;i<listaDestinatarios->size;i++)
    {
        for(j=0;j<blackList->size;j++)
        {
            destinatarioA=listaDestinatarios->get(listaDestinatarios,i);
            destinatarioBlack=blackList->get(blackList,j);
            if(destinatarioA->nombre==destinatarioBlack->nombre && destinatarioA->mail==destinatarioBlack->mail)
            {
                flagAdd=1;
                break;
            }
        }
        if(flagAdd==0)
        {
            listaDepurada->add(listaDepurada,destinatarioA);
        }
    }
}

void eliminarRepetidos(ArrayList* listaDepurada)
{
    int i,j;
    eDestinatario* destinatarioA;
    eDestinatario* destinatarioB;
    for(i=0;i<(listaDepurada->size-1);i++)
    {
        for(j=i+1;j<listaDepurada->size;j++)
        {
            destinatarioA=listaDepurada->get(listaDepurada,i);
            destinatarioB=listaDepurada->get(listaDepurada,j);
            if(destinatarioA->nombre==destinatarioB->nombre && destinatarioA->mail==destinatarioB->mail)
            {
                listaDepurada->remove(listaDepurada,j);
            }
        }
    }
}
