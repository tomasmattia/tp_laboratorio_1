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

/** \brief Carga desde el archivo binario las peliculas en un array de estructuras recibe el contador de la cantidad de peliculas guardadas
 *
 * \param listaPeliculas EMovie*
 * \return int Devuelve 1 si no se pudo leer o crear el archivo o 0 si se pudo.
 *
 */
int cargarDesdeArchivo(EMovie *listaPeliculas,int*);

/** \brief recibe un string y el maximo de caracteres que debe soportar para validarlo
 *
 * \param stringAValid[] char
 * \param int maximo length
 * \return void
 *
 */
void validarString(char stringAValid[], int);

/** \brief recibe un numero y dos parametros como minimo y maximo, retorna el numero validado
 *
 * \param int numero a checkear
 * \param int minimo
 * \param int maximo
 * \return int
 *
 */
int checkearNumero(int ,int ,int );

/** \brief genera una pelicula nueva en el array, recibe el puntero al array de estructuras, el contador y el puntero al contador
 *
 * \param listaPeliculas EMovie*
 * \param int contador
 * \param int* puntero a contador
 * \return void
 *
 */
void agregarPelicula(EMovie *listaPeliculas,int,int*);

/** \brief busca una pelicula por titulo y luego pasa su duracion a cero si el usuario lo desea, recibe el puntero al array de estructuras y el contador
 *
 * \param listaPeliculas EMovie*
 * \return void
 *
 */
void borrarPelicula(EMovie *listaPeliculas,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param la lista de peliculas a ser agregadas en el archivo.
 *  @param contador
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* listaPeliculas, int , char nombreHtml[]);

/** \brief muestra el listado de peliculas activas(con duracion mayor a 0) y permite modificar cualquiera de sus parametros, recibe el puntero al array de estructuras y el contador
 *
 * \param listaPeliculas EMovie* puntero al array de estructuras
 * \param int contador
 * \return void
 *
 */
void modificarPelicula(EMovie *listaPeliculas,int);

/** \brief guarda todos los datos ingresados en un archivo binario, recibe el puntero al array de estructuras, el contador y el puntero al contador
 *
 * \param listaPeliculas EMovie*
 * \param int contador
 * \param int* puntero al contador
 * \return int
 *
 */
int guardarEnArchivo(EMovie* listaPeliculas,int,int*);

#endif // FUNCIONES_H_INCLUDED
