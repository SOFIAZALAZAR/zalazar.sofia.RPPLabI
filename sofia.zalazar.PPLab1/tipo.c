#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


/** \brief muestra lo que esta cargado en el array tipos
 *
 * \param lista[] eTipo
 * \param tam int
 * \return int retorna 0 si el array es NULL o tam es <0 y 1 si se puede mostrar
 *
 */
int listarTipos(eTipo lista[],int tam)
{
    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Tipos De Moto   |   \n\n");
        printf("  ID            Tipo \n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarTipo(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;
}



/** \brief muestra los campos de la estructura tipo
 *
 * \param unTipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo unTipo)
{
    printf(" %d\t\t%s\n",unTipo.id,unTipo.descripcion);

}

/** \brief carga la descripcion del id ingresado
 *
 * \param id int
 * \param tipos[] eTipo
 * \param tam int
 * \param desc[] char
 * \return int retorna 0 si no se puede cargar y 1 si se carga de manera exitosa
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 1000 && id <= 1003 && tipos != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
