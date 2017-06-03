#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<limits.h>
#include "funciones.h"

int cargarDesdeArchivo(EMovie *listaPeliculas, int* punteroAcontador)
{
    int flag = 0;
    FILE *f;

    f=fopen("moviesBin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("moviesBin.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag==0)
    {
        fread(punteroAcontador,sizeof(int),1,f);
        if(*punteroAcontador!=0)
        {
            while(!feof(f))
            {
                fread(listaPeliculas,sizeof(EMovie),*punteroAcontador,f);
            }
        }
    }
    fclose(f);
    return 0;
}

void toString(EMovie *listaPeliculas)
{
    printf("TITULO :%s\nGENERO: %s\nDURACION: %d MINUTOS\nDESCRIPCION: %s\nPUNTAJE: %d\nLINK IMAGEN: %s\n", listaPeliculas->titulo, listaPeliculas->genero, listaPeliculas->duracion, listaPeliculas->descripcion, listaPeliculas->puntaje, listaPeliculas->linkImagen);
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

int checkearNumero(int numero,int minimo,int maximo)
{
    int checkNum=numero;
    while(checkNum<minimo || checkNum>maximo)
    {
        printf("Por Favor reingrese: ");
        fflush(stdin);
        scanf("%d", &checkNum);
    }
    return checkNum;
}

void agregarPelicula(EMovie *listaPeliculas,int contadorPeliculas,int* punteroAcontador)
{
    int ubicacion, i;
    char auxTitulo[50];
    char auxGenero[50];
    int duracion;
    char auxDescripcion[100];
    int puntaje;
    char linkImagen[200];
    int largoTitulo;
    int encontro=0;
    ubicacion=contadorPeliculas-1;
    printf("INGRESO DE DATOS\n");
    printf("Ingrese el titulo: ");
    fflush(stdin);
    scanf("%s", auxTitulo);
    validarString(auxTitulo,20);
    largoTitulo=strlen(auxTitulo);
    for(i=0; i<largoTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    /*Buscamos si el titulo ya existe*/
    for(i=0; i<contadorPeliculas; i++)
    {
        if(strcmp(auxTitulo,(listaPeliculas+i)->titulo)==0 && (listaPeliculas+i)->duracion!=0)
        {
            encontro=1;
            break;
        }
    }
    if(!encontro)//entra si encontro==0
    {
        strcpy((listaPeliculas+ubicacion)->titulo,auxTitulo);
        printf("Ingrese genero: ");
        fflush(stdin);
        gets(auxGenero);
        validarString(auxGenero,20);
        strcpy((listaPeliculas+ubicacion)->genero,auxGenero);
        printf("Ingrese duracion en minutos: ");
        fflush(stdin);
        scanf("%d",&duracion);
        duracion=checkearNumero(duracion,0,400);
        (listaPeliculas+ubicacion)->duracion=duracion;
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);
        validarString(auxDescripcion,50);
        strcpy((listaPeliculas+ubicacion)->descripcion,auxDescripcion);
        printf("Ingrese puntaje: ");
        fflush(stdin);
        scanf("%d",&puntaje);
        puntaje=checkearNumero(puntaje,1,10);
        (listaPeliculas+ubicacion)->puntaje=puntaje;
        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(linkImagen);
        validarString(linkImagen,150);
        strcpy((listaPeliculas+ubicacion)->linkImagen,linkImagen);
    }
    else
    {
        printf("El titulo ingresado ya existe!\n");
        *punteroAcontador-=1;
    }
}

void borrarPelicula(EMovie *listaPeliculas,int contadorPeliculas)
{
    int flag=0,i;
    char titulo[50];
    char opcion;
    int largoTitulo;
    printf("LISTA DE PELICULAS\n\n");
    for(i=0;i<contadorPeliculas;i++)
    {
        if((listaPeliculas+i)->duracion!=0)
        {
            printf("%s\n",(listaPeliculas+i)->titulo);
        }
    }
    printf("Ingrese el titulo de la pelicula a eliminar: ");
    fflush(stdin);
    scanf("%s", titulo);
    validarString(titulo,20);
    largoTitulo=strlen(titulo);
    for(i=0; i<largoTitulo; i++)
    {
        titulo[i]=toupper(titulo[i]);
    }
    for(i=0; i<contadorPeliculas; i++)
    {
        if(strcmp(titulo,(listaPeliculas+i)->titulo)==0 && (listaPeliculas+i)->duracion!=0)
        {
            printf("Pelicula a eliminar:\n");

            toString((listaPeliculas + i));

            printf("\nPelicula encontrada. Seguro desea borrarla?: ");
            opcion=getche();
            if(opcion=='s')
            {
                (listaPeliculas+i)->duracion=0;
                printf("\nPelicula borrada!\n");
            }
            else
            {
                printf("\nLa pelicula no se borro!\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("La pelicula no se encuentra cargada\n");
    }
}

void modificarPelicula(EMovie *listaPeliculas,int contadorPeliculas)
{
    int flag=0;
    int opcion;
    int ubicacion, i;
    char auxTitulo[50];
    char auxGenero[50];
    int duracion;
    char auxDescripcion[100];
    int puntaje;
    char linkImagen[100];
    int largoTitulo;
    int encontro=0;
    printf("LISTA DE PELICULAS\n\n");
    for(i=0;i<contadorPeliculas;i++)
    {
        if((listaPeliculas+i)->duracion!=0)
        {
            printf("%s\n",(listaPeliculas+i)->titulo);
        }
    }
    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    scanf("%s", auxTitulo);
    validarString(auxTitulo,20);
    largoTitulo=strlen(auxTitulo);
    for(i=0; i<largoTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    for(i=0; i<contadorPeliculas; i++)
    {
        if(strcmp(auxTitulo,(listaPeliculas+i)->titulo)==0 && (listaPeliculas+i)->duracion!=0)
        {
            printf("Pelicula a modificar:\n");

            toString((listaPeliculas + i));
            ubicacion=i;
            printf("\nPelicula encontrada. Que parametro desea modificar?\n");
            printf("1- Titulo\n");
            printf("2- Genero\n");
            printf("3- Duracion\n");
            printf("4- Descripcion\n");
            printf("5- Puntaje\n");
            printf("6- Link a imagen\n");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("INGRESO DE DATOS\n");
                printf("Ingrese el titulo: ");
                fflush(stdin);
                scanf("%s", auxTitulo);
                validarString(auxTitulo,20);
                largoTitulo=strlen(auxTitulo);
                for(i=0; i<largoTitulo; i++)
                {
                    auxTitulo[i]=toupper(auxTitulo[i]);
                }
                /*Buscamos si el titulo ya existe*/
                for(i=0; i<contadorPeliculas; i++)
                {
                    if(strcmp(auxTitulo,(listaPeliculas+i)->titulo)==0 && (listaPeliculas+i)->duracion!=0)
                    {
                        encontro=1;
                        break;
                    }
                }
                if(!encontro)//entra si encontro==0
                {
                    strcpy((listaPeliculas+ubicacion)->titulo,auxTitulo);
                    printf("El titulo ha sido modificado!\n");
                }
                else
                {
                    printf("El titulo ingresado ya existe!\n");
                }
                break;
            case 2:
                printf("Ingrese el nuevo genero: ");
                fflush(stdin);
                gets(auxGenero);
                validarString(auxGenero,20);
                strcpy((listaPeliculas+ubicacion)->genero,auxGenero);
                printf("\nParametro modificado con exito!\n");
                break;
            case 3:
                printf("Ingrese la nueva duracion en minutos: ");
                fflush(stdin);
                scanf("%d",&duracion);
                duracion=checkearNumero(duracion,0,400);
                (listaPeliculas+ubicacion)->duracion=duracion;
                printf("\nParametro modificado con exito!\n");
                break;
            case 4:
                printf("Ingrese la nueva descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);
                validarString(auxDescripcion,50);
                strcpy((listaPeliculas+ubicacion)->descripcion,auxDescripcion);
                printf("\nParametro modificado con exito!\n");
                break;
            case 5:
                printf("Ingrese el nuevo puntaje: ");
                fflush(stdin);
                scanf("%d",&puntaje);
                puntaje=checkearNumero(puntaje,1,10);
                (listaPeliculas+ubicacion)->puntaje=puntaje;
                printf("\nParametro modificado con exito!\n");
                break;
            case 6:
                printf("Ingrese el nuevo link de la imagen: ");
                fflush(stdin);
                gets(linkImagen);
                validarString(linkImagen,50);
                strcpy((listaPeliculas+ubicacion)->linkImagen,linkImagen);
                printf("\nParametro modificado con exito!\n");
                break;
            default:
                printf("No es una opcion valida\n");
                break;
            }

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("La pelicula no se encuentra cargada\n");
    }
}

int guardarEnArchivo(EMovie* listaPeliculas,int contadorPeliculas,int* punteroAcontador)
{
    int i;
	FILE *f;
		f=fopen("moviesBin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}
    fwrite(punteroAcontador,sizeof(int),1,f);
    for(i=0;i<contadorPeliculas;i++)
    {
        if((listaPeliculas+i)->duracion!=0)
        {
            fwrite(listaPeliculas,sizeof(EMovie),1,f);
        }
    }

	fclose(f);

	return 0;
}

void generarPagina(EMovie* listaPeliculas, int contadorPeliculas, char nombreHtml[])
{
    FILE *f;
    int i;
    strcat(nombreHtml,".html");
    f=fopen(nombreHtml,"w");
    if(f == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for(i=0;i<contadorPeliculas;i++)
    {
        if((listaPeliculas+i)->duracion!=0)
        {
            fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(listaPeliculas+i)->linkImagen);
            fprintf(f,"<h3><a href='#'>%s</a></h3>\n",(listaPeliculas+i)->titulo);
            fprintf(f,"<ul><li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li></ul>\n",(listaPeliculas+i)->genero,(listaPeliculas+i)->puntaje,(listaPeliculas+i)->duracion);
            fprintf(f,"<p>%s</p></article>",(listaPeliculas+i)->descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
}
