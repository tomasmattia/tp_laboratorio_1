#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    char nombre[50];
    char mail[100];
}eDestinatario;

void menu(void);
