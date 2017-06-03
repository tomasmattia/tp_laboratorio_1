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
    char nombreHtml[50]={"listadoPeliculas"};
    int auxContador=0; // PARA CONTAR LAS PELICULAS ACTIVAS ANTES DE GUARDAR
    int* punteroAauxCont=&auxContador; // PARA CONTAR LAS PELICULAS ACTIVAS ANTES DE GUARDAR
    int i;
    EMovie* listaPeliculas;
    listaPeliculas=(EMovie*)malloc(sizeof(EMovie)*50);
    if(listaPeliculas==NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    char seguir='s';
    int opcion=0;

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
                if(contadorPeliculas%100==0)
                {
                    contadorPeliculas++;
                    EMovie* auxPeliculas;
                    auxPeliculas=(EMovie*)realloc(listaPeliculas,(contadorPeliculas*2)*sizeof(EMovie));
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
                else
                {
                    contadorPeliculas++;
                    agregarPelicula(listaPeliculas,contadorPeliculas,punteroAcontador);
                }
                break;
            case 2:
                borrarPelicula(listaPeliculas,contadorPeliculas);
                break;
            case 3:
                modificarPelicula(listaPeliculas,contadorPeliculas);
               break;
            case 4:
                for(i=0;i<contadorPeliculas;i++) // CUENTA LA CANTIDAD DE PELICULAS ACTIVAS QUE SE VAN A GUARDAR
                {
                    if((listaPeliculas+i)->duracion!=0)
                    {
                        *punteroAauxCont+=1;
                    }
                }
                generarPagina(listaPeliculas,contadorPeliculas,nombreHtml);
                printf("Se genero un archivo HTML con el siguiente nombre: %s",nombreHtml);
                if(guardarEnArchivo(listaPeliculas,contadorPeliculas,punteroAauxCont)) // RECIBE LOS DOS CONTADORES PARA GUARDAR UNICAMENTE LAS ACTIVAS Y SU RESPECTIVA CANTIDAD
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
