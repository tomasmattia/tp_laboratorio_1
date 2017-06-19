#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    char* nombre;
    char* mail;
}eDestinatario;

void menu(void);

int cargarListaDestinatarios(char*,ArrayList* listaDestinatarios);

void mostrarUnDestinatario(eDestinatario* unDestinatario);

void mostrarListaDestinatarios(ArrayList* listaDestinatarios);
