#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int idCategoria;

}eProgramador;


/** \brief
 *
 * \param void
 * \return void
 *
 */
void menu(void);

void validarString(char[], int);

int validarDigitoRango(char*,int,int);

void altaProgramador(ArrayList* listaProgramadores);

void eliminarProgramador(ArrayList* listaProgramadores);

eProgramador* newProgramador(int,char[],char[],int);

int checkearId(ArrayList* listaProgramadores,int);

int buscarProgramadorPorId(ArrayList* listaProgramadores,int);

void mostrarUnProgramador(eProgramador* unProgramador);

void mostrarListaProgramadores(ArrayList* listaProgramadores);


