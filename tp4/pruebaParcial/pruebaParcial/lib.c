#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("1- Ingresar un cliente\n");
    printf("2- Proximo cliente\n");
    printf("3- Clientes pendientes\n");
    printf("4- Lista de clientes atendidos\n");
    printf("5- Salir\n");
}


void validarString(char stringAValid[], int maximo)
{
    int largo=strlen(stringAValid);
    while(largo>maximo)
    {
        printf("Se excedio del tamano reingrese: ");
        stringAValid=gets(stringAValid);
        largo=strlen(stringAValid);
    }
}

int validarDigitoRango(char* numero,int minimo,int maximo)
{
    int i;
    int largo=strlen(numero);
    int flag;
    int numCheck;
    do
    {
        do
        {
            flag=0;
            for(i=0; i<largo; i++)
            {
                if(!isdigit(numero[i]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=0)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
            numCheck=atoi(numero);
            if(numCheck<minimo || numCheck>maximo)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
        }while(flag!=0);
    }while(numCheck<minimo || numCheck>maximo);
    return numCheck;
}

int checkearDni(ArrayList* listaUrgentes, ArrayList* listaRegular,int dni)
{
    int i;
    int returnAux=0;
    eCliente* clienteAux;
    if(dni>0)
    {
        for(i=0; i<listaUrgentes->size; i++)
        {
            clienteAux=listaUrgentes->get(listaUrgentes,i);
            if(clienteAux->dni==dni)
            {
                returnAux=1;
                break;
            }
        }
        if(returnAux!=1)
        {
            for(i=0; i<listaRegular->size; i++)
            {
                clienteAux=listaRegular->get(listaRegular,i);
                if(clienteAux->dni==dni)
                {
                    returnAux=1;
                    break;
                }
            }
        }
    }
    return returnAux;
}

eCliente* newCliente(int dni,int tipoTramite,int turno)
{
    eCliente* returnAux=NULL;
    eCliente* nuevoCliente=(eCliente*)malloc(sizeof(eCliente));
    if(nuevoCliente!=NULL)
    {
        nuevoCliente->dni=dni;
        nuevoCliente->tipoTramite=tipoTramite;
        nuevoCliente->numeroTurno=turno;
        returnAux=nuevoCliente;
    }
    return returnAux;
}

void ingresoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular,int* punteroTurno)
{
    eCliente* nuevoCliente;
    int max=INT_MAX;
    char* dni=(char*)malloc(sizeof(char)*10);
    char* tipoTramite=(char*)malloc(sizeof(char)*10);
    int dniNum;
    int tramiteNum;
    printf("Ingrese su DNI: ");
    fflush(stdin);
    gets(dni);
    dniNum=validarDigitoRango(dni,100000,max);
    while(checkearDni(listaUrgentes,listaRegular,dniNum)==1)
    {
        printf("Error, el DNI ya se encuentra ingresado, reingrese: ");
        fflush(stdin);
        gets(dni);
        dniNum=validarDigitoRango(dni,100000,max);
    }
    printf("Ingrese el tipo de tramite a realizar\n");
    printf("1- TRAMITE URGENTE\n");
    printf("2- TRAMITE REGULAR\n");
    fflush(stdin);
    gets(tipoTramite);
    tramiteNum=validarDigitoRango(tipoTramite,1,2);
    *punteroTurno+=1;
    nuevoCliente=newCliente(dniNum,tramiteNum,*punteroTurno);
    if(nuevoCliente!=NULL)
    {
        if(tramiteNum==1)
        {
            if(listaUrgentes->add(listaUrgentes,nuevoCliente)==0)
            {
                printf("DNI: %d.Su numero de turno es %d, aguarde en unos momentos sera atendido\n",dniNum,*punteroTurno);
            }
        }
        else
        {
            if(listaRegular->add(listaRegular,nuevoCliente)==0)
            {
                printf("DNI: %d.Su numero de turno es %d, aguarde en unos momentos sera atendido\n",dniNum,*punteroTurno);
            }
        }
    }
    mostrarUnCliente(nuevoCliente);
}

void proximoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular, ArrayList* totalPacientes)
{
    eCliente* proximoCliente=NULL;
    if(listaUrgentes->size>0)
    {
        proximoCliente=listaUrgentes->pop(listaUrgentes,0);
    }
    else
    {
        if(listaRegular->size>0)
        {
            proximoCliente=listaRegular->pop(listaRegular,0);
        }
    }
    if(proximoCliente!=NULL)
    {
        totalPacientes->add(totalPacientes,proximoCliente);
        mostrarUnCliente(proximoCliente);
    }
    else
    {
        printf("No hay clientes en espera\n");
    }
}

void mostrarUnCliente(eCliente* unCliente)
{
    char tipoTramite[]="";
    switch(unCliente->tipoTramite)
    {
        case 1:
            strcpy(tipoTramite,"URGENTE");
            break;
        case 2:
            strcpy(tipoTramite,"REGULAR");
            break;
    }
    printf("DNI: %d / TIPO DE TRAMITE: %s / TURNO: %d\n",unCliente->dni,tipoTramite,unCliente->numeroTurno);
}

void clientesEnEspera(ArrayList* listaUrgentes, ArrayList* listaRegular)
{
    int i;
    if(listaUrgentes->size>0)
    {
        printf("Clientes urgentes que estan en espera: \n");
        for(i=0;i<listaUrgentes->size;i++)
        {
            mostrarUnCliente(listaUrgentes->pElements[i]);
        }
    }
    else
    {
        printf("No hay clientes urgentes en espera\n");
    }
    if(listaRegular->size>0)
    {
        printf("Clientes regulares que estan en espera: \n");
        for(i=0;i<listaRegular->size;i++)
        {
            mostrarUnCliente(listaRegular->pElements[i]);
        }
    }
    else
    {
        printf("No hay clientes regulares en espera\n");
    }
}

void clientesAtendidos(ArrayList* totalPacientes)
{
    int i;
    if(totalPacientes->size>0)
    {
        printf("Lista de clientes atendidos: \n");
        for(i=0;i<totalPacientes->size;i++)
        {
            mostrarUnCliente(totalPacientes->pElements[i]);
        }
    }
    else
    {
        printf("Todavia no se atendieron pacientes\n");
    }
}

int compararClientes(void* clienteA,void* clienteB)
{

    if(((eCliente*)clienteA)->dni > ((eCliente*)clienteB)->dni)
    {
        return 1;
    }
    if(((eCliente*)clienteA)->dni < ((eCliente*)clienteB)->dni)
    {
        return -1;
    }
    return 0;


}

