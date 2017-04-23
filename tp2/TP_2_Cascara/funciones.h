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

/** \brief
 *
 * \param EPersona
 * \return void
 *
 */
void agregarPersona(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void mostrarOrdenado(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void eliminarPersona(EPersona lista[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void mostrarGrafico(EPersona lista[]);
#endif // FUNCIONES_H_INCLUDED
