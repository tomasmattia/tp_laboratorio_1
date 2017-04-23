#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

#define MAX 20

int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<MAX; i++)
    {
        if(lista[i].estado==0)
        {
            resultado=i;
            flagEspacio=1;
        }
    }
    if(flagEspacio==0)
    {
        resultado=-1;
    }
    return resultado;
}

void agregarPersona(EPersona lista[])
{
    int x=obtenerEspacioLibre(lista);
    if(x==-1)
    {
        printf("Se completo el espacio, necesita borrar una persona\n");
    }
    else
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(lista[x].nombre);
        printf("Ingresar edad: ");
        scanf("%d",&lista[x].edad);
        printf("Ingresar DNI: ");
        scanf("%d",&lista[x].dni);
        lista[x].estado=1;
    }

}

int buscarPorDni(EPersona lista[])
{
    int i;
    int resultado;
    int flagDni=0;
    int dni;
    printf("Ingrese el dni a buscar: ");
    scanf("%d",&dni);
    for(i=0; i<MAX; i++)
    {
        if(dni==lista[i].dni)
        {
            resultado=i;
            flagDni=1;
        }
    }
    if(flagDni==0)
    {
        resultado=-1;
    }
    return resultado;
}

void mostrarOrdenado(EPersona lista[])
{
    int i,j;
    EPersona aux= {};
    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0; i<MAX; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\nDNI: %d\tNOMBRE: %s\t EDAD: %d",lista[i].dni,lista[i].nombre,lista[i].edad);
        }
    }
    printf("\n");
}

void eliminarPersona(EPersona lista[])
{
    int x=buscarPorDni(lista);
    char respuesta='n';
    if(x==-1)
    {
        printf("El dni ingresado es erroneo\n");
    }
    else
    {
        printf("\nDNI: %d\tNOMBRE: %s\t EDAD: %d",lista[x].dni,lista[x].nombre,lista[x].edad);
        printf("\nDesea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista[x].estado=0;
            printf("Persona eliminada de la lista\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void mostrarGrafico(EPersona lista[])
{
    int i,j;
    int menores18=0;
    int entre18y35=0;
    int mayores35=0;
    char grafico[MAX][3]= {};
    char asterisco='*';
    for(i=0; i<MAX; i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].edad<18)
            {
                menores18+=1;
            }
            else
            {
                if(lista[i].edad>18 && lista[i].edad<35)
                {
                    entre18y35+=1;
                }
                else
                {
                    mayores35+=1;
                }
            }
        }
    }
    for(i=0; i<menores18; i++)
    {
        grafico[i][0]=asterisco;
    }
    for(i=0; i<entre18y35; i++)
    {
        grafico[i][1]=asterisco;
    }
    for(i=0; i<mayores35; i++)
    {
        grafico[i][2]=asterisco;
    }
    // IMPRIMIR FUNCION

    for(i=0;i<MAX;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grafico[i][0]=='*' || grafico[i][1]=='*' || grafico[i][2]=='*')
            {
                printf("%c\t",grafico[i][j]);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }

    /*printf("Menores de 18: ");
    for(i=0;i<MAX;i++)
    {
        printf("%c",grafico[i][0]);
    }
    printf("\nEntre 18 y 35: ");
    for(i=0;i<MAX;i++)
    {
        printf("%c",grafico[i][1]);
    }
    printf("\nMayores de 35: ");
    for(i=0;i<MAX;i++)
    {
        printf("%c",grafico[i][2]);
    }
    printf("\n");*/
}
