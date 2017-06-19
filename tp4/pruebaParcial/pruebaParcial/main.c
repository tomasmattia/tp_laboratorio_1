#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    int opcion;
    int contadorTurno=0;
    int* punteroTurno=&contadorTurno;
    char respuesta='s';
    ArrayList* listaUrgentes=al_newArrayList();
    ArrayList* listaRegular=al_newArrayList();
    ArrayList* totalPacientes=al_newArrayList();
    do
    {
        opcion=0;
        menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                ingresoCliente(listaUrgentes,listaRegular,punteroTurno);
                break;
            case 2:
                proximoCliente(listaUrgentes,listaRegular,totalPacientes);
                break;
            case 3:
                clientesEnEspera(listaUrgentes,listaRegular);
                break;
            case 4:
                clientesAtendidos(totalPacientes);
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