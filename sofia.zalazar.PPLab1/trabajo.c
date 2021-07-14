#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "utn.h"

/** \brief inicializa todo el array como isEmpty
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return int retorna 1 si se hizo de manera exitosa o 0 si no lo hizo
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tam)
{
    int todoOk = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}



/** \brief busca si hay un lugar vacio en un array de trabajos
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \return int retorna el indice del primer lugar vacio o -1 si el array esta completo
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief agrega un trabajo a la lista de trabajos
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int tamaño del array de trabajos
 * \param motos[] eMoto array de motos
 * \param tamMotos int tamaño del array de motos
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamaño del array de tipos
 * \param colores[] eColor array de colores
 * \param tamColor int tamaño del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamSer int tamaño del array de servicios
 * \param pId int* puntero al id de trabajos
 * \return int Retorna 1 si se pudo dar de alta
 *                     0 si alguno de los Arrays es nulo, los tamaños de los arrays son negativos o algun datos ingresado no pasa las validaciones
 *
 */
int altaTrabajo(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, int* pId, eCliente clientes[],int tamCli)
{
    int ok = 0;
    eTrabajo auxTrabajo;
    int i;
    system("cls");
    if(lista!= NULL && tam > 0 && pId!=NULL)
    {
        i = buscarLibreTrabajo(lista,tam);
        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("   Alta Trabajo\n\n");
            printf("ID Trabajo: %d\n", *pId);

            if (mostrarMotos(motos,tamMotos,tipos,tamTipos,colores,tamColor,clientes,tamCli))
            {
                printf("Ingrese ID de la moto: ");
                getInt(&auxTrabajo.idMoto);
                if(buscarMotoById(motos,tamMotos,auxTrabajo.idMoto)!=-1)
                {
                    listarServicios(servicios,tamSer);
                    printf("Ingrese ID del servicio: ");
                    getInt(&auxTrabajo.idServicio);
                    if(auxTrabajo.idServicio>=2000 && auxTrabajo.idServicio<=2003)
                    {
                        if(getFecha(&auxTrabajo.fecha))
                        {
                             auxTrabajo.isEmpty = 0;
                            auxTrabajo.id = *pId;
                            lista[i] = auxTrabajo;
                            (*pId)++;
                            ok = 1;

                        }

                    }
                }
            }
        }

    }
    return ok;
}


/** \brief muestra lo que esta cargado en los campos de una estructura
 *
 * \param unTrabajo eTrabajo
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo,eServicio servic[], int tamServ)
{
    char descripcion[20];
    float precio;
    if(servic!=NULL && tamServ>0)
    {
        cargarServicio(unTrabajo.idServicio,servic,tamServ,descripcion,&precio);
        printf("%3d\t%10s\t%.2f\t    %2d/%2d/%d\t   %d\n"
               ,unTrabajo.id
               ,descripcion
               ,precio
               ,unTrabajo.fecha.dia
               ,unTrabajo.fecha.mes
               ,unTrabajo.fecha.anio
               ,unTrabajo.idMoto
              );

    }

}

/** \brief muestra lo que esta cargado en el array de trabajos
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return int retorna 0 si no hay nada cargado o si el array es NULL o el tam <0 y retorna 1 si se puede mostrar
 *
 */
int mostrarTrabajos(eTrabajo lista[], int tam,eServicio servic[], int tamServ)
{

    int todoOk = 0;
    int sinTrabajos= 1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   TRABAJOS   |   \n\n");
        printf("  ID         SERVICIO   PRECIO        FECHA      ID MOTO    \n\n");


        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarTrabajo(lista[i],servic,tamServ);
                sinTrabajos = 0;
                todoOk=1;
            }
        }
        if(sinTrabajos)
        {
            printf("No hay Trabajos que mostrar.");
        }
        printf("\n\n");

    }

    return todoOk;

}

