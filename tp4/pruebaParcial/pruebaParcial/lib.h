#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    int dni;
    int tipoTramite;
    int numeroTurno;
}eCliente;

void menu(void);

void validarString(char[], int);

int validarDigitoRango(char*,int,int);

eCliente* newCliente(int,int,int);

void ingresoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular,int*);

int checkearDni(ArrayList* listaUrgentes, ArrayList* listaRegular,int);

void mostrarUnCliente(eCliente* unCliente);

void proximoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular, ArrayList* totalPacientes);

void clientesEnEspera(ArrayList* listaUrgentes, ArrayList* listaRegular);

void clientesAtendidos(ArrayList* totalPacientes);
