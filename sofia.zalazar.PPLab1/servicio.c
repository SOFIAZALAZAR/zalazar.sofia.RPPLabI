#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/** \brief muestra los campos de la estructura servicio
 *
 * \param unServicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServicio)
{

    printf(" %d\t\t%10s\t\t%.2f\n",unServicio.id,unServicio.descripcion,unServicio.precio);

}



/** \brief muestra lo que esta cargado en el array servicios
 *
 * \param lista[] eServicio
 * \param tam int
 * \return int retorna 0 si el array es NULL o tam es <0 y 1 si se puede mostrar
 *
 */
int listarServicios(eServicio lista[],int tam)
{

    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Servicios   |   \n\n");
        printf("  ID            Descripcion           Precio\n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarServicio(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;


}

/** \brief recibe un id y carga lo que hay en los campos de descripcion y precio
 *
 * \param id int
 * \param servicios[] eServicio
 * \param tam int
 * \param desc[] char
 * \param precio float*
 * \return int retorna 1 si se pudo cargar y 0 si no se pudo cargar
 *
 */
int cargarServicio(int id, eServicio servicios[],int tam, char desc[], float* precio)
{
    int todoOk = 0;
    if(id >= 2000 && id <= 2003 && servicios != NULL && tam > 0 && desc != NULL && precio!=NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(desc, servicios[i].descripcion);
                *precio = servicios[i].precio;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
