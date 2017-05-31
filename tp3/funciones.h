#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
}EMovie;

/** \brief Carga desde el archivo binario las peliculas en un array de estructuras
 *
 * \param listaPeliculas EMovie*
 * \return int Devuelve 1 si no se pudo leer o crear el archivo o 0 si se pudo.
 *
 */
int cargarDesdeArchivo(EMovie *listaPeliculas,int*);

/** \brief
 *
 * \param listaPeliculas EMovie*
 * \return int
 *
 */
int buscarLibre(EMovie *listaPeliculas,int);

void validarString(char stringAValid[], int);

int checkearNumero(int ,int ,int );

/** \brief
 *
 * \param listaPeliculas EMovie*
 * \return void
 *
 */
void agregarPelicula(EMovie *listaPeliculas,int,int*);

/** \brief
 *
 * \param listaPeliculas EMovie*
 * \return void
 *
 */
void borrarPelicula(EMovie *listaPeliculas,int,int*);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* listaPeliculas, int , char nombreHtml[]);

void modificarPelicula(EMovie *listaPeliculas,int);

int guardarEnArchivo(EMovie* listaPeliculas,int,int*);

#endif // FUNCIONES_H_INCLUDED
