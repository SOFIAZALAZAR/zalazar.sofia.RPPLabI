#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"



/** \brief muestra los campos de la estructura color
 *
 * \param unColor eColor
 * \return void
 *
 */
void mostrarColor(eColor unColor)
{
    printf(" %d\t\t%s\n",unColor.id,unColor.normbreColor);
}


/** \brief muestra lo que esta cargado en el array colores
 *
 * \param lista[] eColor
 * \param tam int
 * \return int retorna 0 si el array es NULL o tam es <0 y 1 si se puede mostrar
 *
 */
int listarColores(eColor lista[],int tam)
{

    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Colores De Moto   |   \n\n");
        printf("  ID            Color \n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarColor(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;

}

/** \brief carga la descripcion del id ingresado
 *
 * \param id int
 * \param colores[] eColor
 * \param tam int
 * \param desc[] char
 * \return int retorna 0 si no se puede cargar y 1 si se carga de manera exitosa
 *
 */
int cargarDescripcionColor(int id, eColor colores[],int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 10000 && id <= 10004 && colores != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(desc, colores[i].normbreColor);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

