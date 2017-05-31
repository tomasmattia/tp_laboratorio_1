#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<limits.h>
#include "funciones.h"

int main()
{
    int contadorPeliculas=0;
    int* punteroAcontador=&contadorPeliculas;
    char nombreHtml[50]={};
    EMovie* listaPeliculas;
    listaPeliculas=(EMovie*)malloc(sizeof(EMovie));
    if(listaPeliculas==NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    char seguir='s';
    int opcion=0;
    int i;

    for(i=0;i<contadorPeliculas;i++)
    {
        listaPeliculas->duracion=0;
        listaPeliculas->puntaje=0;
    }

    if(cargarDesdeArchivo(listaPeliculas,punteroAcontador))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

    system("pause");
	system("cls");

    while(seguir=='s')
    {
        printf("Valor de ContadorPeliculas: %d\n",contadorPeliculas);
        opcion=0;
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web y guardar archivo binario\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(contadorPeliculas==0)
                {
                    contadorPeliculas++;
                    agregarPelicula(listaPeliculas,contadorPeliculas,punteroAcontador);
                }
                else
                {
                    contadorPeliculas++;
                    EMovie* auxPeliculas;
                    auxPeliculas=(EMovie*)realloc(listaPeliculas,contadorPeliculas*sizeof(EMovie));
                    if(auxPeliculas==NULL)
                    {
                        exit(1);
                    }
                    else
                    {
                        listaPeliculas=auxPeliculas;
                        agregarPelicula(listaPeliculas,contadorPeliculas,punteroAcontador);
                    }
                }
                break;
            case 2:
                borrarPelicula(listaPeliculas,contadorPeliculas);
                break;
            case 3:
                modificarPelicula(listaPeliculas,contadorPeliculas);
               break;
            case 4:
                printf("Ingrese el nombre que llevara el HTML: ");
                fflush(stdin);
                gets(nombreHtml);
                validarString(nombreHtml,25);
                generarPagina(listaPeliculas,contadorPeliculas,nombreHtml);
                if(guardarEnArchivo(listaPeliculas,contadorPeliculas))
                {
                    printf("\nNo se pudo abrir el fichero\n");
                }
                else
                {
                    printf("\nSe guardo la informacion con exito\n");
                }
               break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("No es una opcion valida\n");
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
