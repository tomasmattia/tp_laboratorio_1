#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Busca el dni y obtiene el indice correspondiente.
 * @param lista el array se pasa como parametro.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[]);

/** \brief Se ejecuta obtenerEspacioLibre, si hay espacio toma los datos y los guarda, caso contrario avisa falta de espacio
 *
 * \param recibe la estructura "lista"
 * \return void guarda un registro o avisa falta de espacio
 *
 */
void agregarPersona(EPersona lista[]);

/** \brief Recibe la estructura, la ordena alfabeticamente y la muestra en pantalla.
 *
 * \param recibe la estructura "lista"
 * \return void muestra y guarda la estructura ordenada alfabeticamente
 *
 */
void mostrarOrdenado(EPersona lista[]);

/** \brief Recibe la estructura, ejecuta buscarPorDni, si el dni existe se muestra y pregunta si se quiere eliminar o no, caso afirmativo el estado pasa a 0, si no existe dni sale una advertencia,
 *
 * \param recibe la estructura "lista"
 * \return
 *
 */
void eliminarPersona(EPersona lista[]);

/** \brief
 *
 * \param recibe la estructura "lista"
 * \return void
 *
 */
void mostrarGrafico(EPersona lista[]);
#endif // FUNCIONES_H_INCLUDED
