#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"


int menuInformes()
{
    int opcion;
    printf("\t\t***INFORMES***\n\n");
    printf("1. Mostrar las motos del color seleccionado\n");
    printf("2. Mostrar las motos de un tipo seleccionado\n");
    printf("3. Informar la o las motos de mayor cilindrada\n");
    printf("4. Mostrar un listado de las motos separadas por tipo\n");
    printf("5. Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.\n");
    printf("6. Mostrar el o los colores más elegidos por los clientes.\n");
    printf("7. Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("8. Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la misma\n");
    printf("9. Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.\n");
    printf("10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("11. Mostrar todas las motos de una localidad\n");
    printf("12. Listar motos por localidad\n");
    printf("13. Mostrar clientes por localidad\n");
    printf("14. Mostrar motos por cliente\n");
    printf("15. Mostar servicios por cliente\n");
    printf("16. Total por fecha\n");
    printf("17. Salir\n");
    //printf("18. Salir\n");
   // printf("19. Salir\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    while(opcion<0 || opcion>19)
    {
        fflush(stdin);
        printf("Opcion invalida: ");
        scanf("%d", &opcion);
    }
    printf("\n\n");
    return opcion;
}

/** \brief Mostrar las motos del color seleccionado por el usuario
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0  si no las puede mostrar y 1 si las puede mostrar
 *
 */
int mostrarMotosPorColor(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int id;
    char descripcion[20];
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        listarColores(colores,tamColor);
        printf("Ingres el ID del color: ");
        fflush(stdin);
        if (getInt(&id) && id>= 10000 && id<=10004)
        {
            cargarDescripcionColor(id,colores,tamColor,descripcion);
            printf("MOTOS DE COLOR: %s\n",descripcion);
            printf("----------------------------------------------------------------------------------------\n");
            printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
            printf("-----------------------------------------------------------------------------------------\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idColor == id)
                {
                    mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
                }


            }
            todoOk = 1;
        }

    }

    return todoOk;

}



/** \brief Mostrar las motos de un tipo seleccionado.
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0  si no las puede mostrar y 1 si las puede mostrar
 *
 *
 */
int mostrarMotosPorTipo(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int id;
    char descripcion[20];
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        listarTipos(tipos,tamTipos);
        printf("Ingres el ID del tipo que quiere seleccionar: ");
        if(getInt(&id) && id>= 1000 && id<=1003)
        {
            cargarDescripcionTipo(id,tipos,tamTipos,descripcion);
            printf("MOTOS DEL TIPO: %s\n",descripcion);
 printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idTipo == id)
                {
                    mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
                }


            }
            todoOk = 1;
        }

    }
    return todoOk;
}

/** \brief Informar la o las motos de mayor cilindrada.
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0  si no las puede mostrar y 1 si las puede mostrar
 *
 *
 */
int mayorCilindrada(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{

    int todoOk=0;
    int mayor = 0;
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        for(int i =0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].cilindrada>mayor)
            {
                mayor = lista[i].cilindrada;
            }
        }

        printf("MAYOR CILINDRADA: %d\n",mayor);
 printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
        for(int i =0; i<tam; i++)
        {
            if(lista[i].cilindrada == mayor)
            {
                mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
            }

        }
        todoOk = 1;

    }
    return todoOk;
}


/** \brief Mostrar un listado de las motos separadas por tipo.
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0  si no las puede mostrar y 1 si las puede mostrar
 *
 */
int listarPorTipo(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)

{

    int todoOk=0;
    int id;
    char descripcion[20];
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        for(int j =0; j<tamTipos; j++)
        {
            id = tipos[j].id;
            cargarDescripcionTipo(id,tipos,tamTipos,descripcion);
            printf("---------------------------------------------------------------------------\n\n");
            printf("\n MOTOS DEL TIPO: %s\n",descripcion);
 printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idTipo == id)
                {
                    mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
                }


            }
            todoOk = 1;
        }

    }
    return todoOk;

}


/** \brief Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0  si no las puede mostrar y 1 si las puede mostrar
 *
 */
int contarTipoYColor(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{

    int todoOk=0;
    int contador = 0;
    int id;
    int idColor;
    char descripcion[20];
    char color[20];
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0)
    {
        listarColores(colores,tamColor);
        printf("Ingresar el ID del color: ");
        if(getInt(&idColor) && idColor>= 10000 && idColor<=10004)
        {
            listarTipos(tipos,tamTipos);
            printf("Ingresar el ID del tipo de moto: ");
            if(getInt(&id) && id>= 1000 && id<=1003)
            {
                cargarDescripcionTipo(id,tipos,tamTipos,descripcion);
                cargarDescripcionColor(idColor,colores,tamColor,color);
                printf("MOTOS %s DE COLOR %s:\n",descripcion,color);
                for(int i =0; i<tam; i++)
                {
                    if(lista[i].idTipo == id && lista[i].idColor == idColor)
                    {
                        contador ++;
                    }

                }
                printf("CANTIDAD: %d\n\n",contador);
                todoOk = 1;
            }
        }

    }
    return todoOk;


}



/** \brief Mostrar el o los colores más elegidos por los clientes
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int colorMayor(eMoto lista[],int tam, eColor colores[], int tamColor)
{

    int todoOk=0;
    int contador[5] = {0,0,0,0,0};
    int mayor=0;
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0)
    {
        printf("Colores mas elegidos por los clientes:\n");
        printf("---------------------------------------\n");
        for(int j =0; j<tamColor; j++)
        {
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idColor == colores[j].id)
                {
                    contador[j]++;
                }

            }
            todoOk = 1;
        }
        for(int i =0; i<tamColor; i++)
        {
            if(contador[i]>mayor)
            {
                mayor = contador[i];
            }
        }
        for(int i =0; i<tamColor; i++)
        {
            if(contador[i]==mayor)
            {
                printf("%s\n",colores[i].normbreColor);
            }
        }

    }

    return todoOk;


}

/** \brief Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param motos[] eMoto
 * \param tamMotos int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int mostrarTrabajosMoto(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int id;
    if(lista!=NULL && tam>0 && motos!=NULL && tamMotos>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && servicios!=NULL && tamSer>0 && clientes!=NULL && tamCli>0)
    {
        mostrarMotos(motos,tamMotos,tipos,tamTipos,colores,tamColor,clientes,tamCli);
        printf("Ingres el ID de la moto: ");
        fflush(stdin);
        if (getInt(&id) && buscarMotoById(motos,tamMotos,id)!=-1)
        {
            printf("\n                     |   TRABAJOS   |   \n\n");
            printf("  ID            SERVICIO        PRECIO         FECHA     ID MOTO \n\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idMoto == id)
                {
                    mostrarTrabajo(lista[i],servicios, tamSer);
                }


            }
            todoOk = 1;
        }

    }
    return todoOk;

}

/** \brief Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la misma.
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param motos[] eMoto
 * \param tamMotos int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int mostrarSumaServicios(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli)
{


    int todoOk=0;
    int id;
    float total=0;
    if(lista!=NULL && tam>0 && motos!=NULL && tamMotos>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && servicios!=NULL && tamSer>0 && clientes!=NULL && tamCli>0)
    {

        mostrarMotos(motos,tamMotos,tipos,tamTipos,colores,tamColor,clientes,tamCli);
        printf("Ingres el ID de la moto: ");
        fflush(stdin);
        if (getInt(&id) && buscarMotoById(motos,tamMotos,id)!=-1)
        {
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idMoto == id)
                {
                    for(int j =0; j<tamSer; j++)
                    {
                        if(lista[i].idServicio == servicios[j].id)
                        {
                            total += servicios[j].precio;
                        }

                    }
                }
            }
            printf("\nTotal por los trabajos realizados: %.2f\n\n",total);
            todoOk = 1;
        }

    }
    return todoOk;

}

/** \brief Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param motos[] eMoto
 * \param tamMotos int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int mostrarMotosPorServicio(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli)
{

    int todoOk=0;
    int id;
    char descripcion[20];
    float precio;
    int j = -1;
    if(lista!=NULL && tam>0 && motos!=NULL && tamMotos>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && servicios!=NULL && tamSer>0)
    {
        listarServicios(servicios,tamSer);
        printf("Ingres el ID del servicio: ");
        fflush(stdin);
        if (getInt(&id)&& id>=2000 && id<=2003)
        {
            cargarServicio(id,servicios,tamSer,descripcion,&precio);
            printf("Lista de motos a las que se les realizo el servicio: %s\n",descripcion);
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("  FECHA            ID MOTO |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  | Localidad\n\n");
            printf("------------------------------------------------------------------------------------------------------------\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].idServicio == id)
                {
                    printf("%2d/%2d/%d\t",lista[i].fecha.dia,lista[i].fecha.mes,lista[i].fecha.anio);
                    j = buscarMotoById(motos,tamMotos, lista[i].idMoto);
                    mostrarMoto(motos[j],tipos,tamTipos,colores,tamColor,clientes,tamCli);

                }

            }
            todoOk = 1;
        }

    }
    return todoOk;


}

/** \brief Pedir una fecha y mostrar todos los servicios realizados en la misma.
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param motos[] eMoto
 * \param tamMotos int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int serviciosPorFecha(eTrabajo lista[],int tam,eServicio servicios[],int tamSer)
{
    int todoOk=0;
    eFecha fecha;
    char descripcion[20];
    float precio;
    int flag=1;
    if(lista!=NULL && tam>0 && servicios!=NULL && tamSer>0)
    {
        mostrarTrabajos(lista,tam,servicios,tamSer);
        if (getFecha(&fecha))
        {
            system("cls");
            printf("SERVICIOS EN LA FECHA: %2d/%2d/%d\n",fecha.dia,fecha.mes,fecha.anio);
            printf(" ID          DESCRIPCION          PRECIO\n\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].fecha.dia == fecha.dia && lista[i].fecha.mes== fecha.mes && lista[i].fecha.anio== fecha.anio)
                {
                    cargarServicio(lista[i].idServicio,servicios,tamSer,descripcion,&precio);
                    printf(" %d\t\%10s\t\t%.2f\n",lista[i].idServicio,descripcion,precio);
                    flag = 0;
                }

            }
            if(flag)
            {
                printf("No hay servicios para la fecha ingresada!\n\n");
            }
            todoOk = 1;
        }

    }
    return todoOk;

}
int mostrarMotosLocalidad(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk=0;
    int id;
    char descripcion[20];
    char localidad[20];
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        mostrarClientes(clientes,tamCli);
          printf("Ingrese Localidad: ");
            fflush(stdin);
            gets(localidad);
            system("cls");
            printf("MOTOS DE LOCALIDAD: %s\n",localidad);
    printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
     for(int i =0; i<tamCli ; i++)
     {
         if(stricmp(localidad,clientes[i].localidad)==0)
         {
            for(int j=0; j<tam; j++)
            {
                cargarLocalidadCliente(lista[j].idCliente,clientes,tamCli,descripcion);
                if(stricmp(localidad,descripcion)==0)
                {
                    mostrarMoto(lista[j],tipos,tamTipos,colores,tamColor,clientes,tamCli);

                }
            }
            todoOk = 1;
            break;
         }
     }

    }
    return todoOk;
}

int listarMotosLocalida(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    char descripcion1[20];
    char descripcion2[20];
    eMoto auxMoto;
    if(lista!=NULL&&tam>0 && tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0 && clientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                cargarLocalidadCliente(lista[i].idCliente,clientes,tamCli,descripcion1);
                cargarLocalidadCliente(lista[j].idCliente,clientes,tamCli,descripcion2);
                if(strcmp(descripcion1,descripcion2)>0)
                {
                    auxMoto = lista[i];
                    lista[i] = lista [j];
                    lista[j] = auxMoto;
                }
            }
        }
        todoOk = 1;
        mostrarMotos(lista,tam,tipos,tamTipos,colores,tamColor,clientes,tamCli);
    }
    return todoOk;

}

int mostrarClientesLocalidad(eCliente lista[],int tam)
{
     int todoOk=0;
    int id;
    char localidad[20];
    if(lista!=NULL && tam>0)
    {
          printf("Ingrese Localidad: ");
            fflush(stdin);
            gets(localidad);
            system("cls");
            printf("CLIENTES DE LOCALIDAD: %s\n",localidad);
     printf("-------------------------------------------------\n");
    printf("  ID   |     NOMBRE   |    SEXO   | LOCALIDAD\n\n");
    printf("-------------------------------------------------\n");
     for(int i =0; i<tam ; i++)
     {
         if(stricmp(localidad,lista[i].localidad)==0)
         {
            mostrarCliente(lista[i]);
            todoOk = 1;
         }
     }

    }
    return todoOk;

}
int mostrarMotosPorCliente(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{

    int todoOk=0;
    int id;
    int i;
    if(lista!=NULL && tam>0 && colores!=NULL&& tamColor>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamCli>0)
    {
        mostrarClientes(clientes,tamCli);
        printf("Ingres el ID del cliente: ");
        fflush(stdin);
        if (getInt(&id))
        {
            i=buscarClienteById(clientes,tamCli,id);
            if(i!=-1)
            {
               printf("MOTOS DEL CLIENTE: %s\n",clientes[i].nombre);
    printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
     for(int j =0; j<tam ; j++)
     {
         if(lista[j].idCliente == id)
         {
            mostrarMoto(lista[j],tipos,tamTipos,colores,tamColor,clientes,tamCli);
            todoOk = 1;
         }
     }

            }


        }

    }
    return todoOk;
}

int mostrarTrabajosPorCliente(eTrabajo lista[],int tam,eMoto motos[],int tamMotos,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli)
{

int todoOk=0;
    int id;
    int indice;
    if(lista!=NULL && tam>0&& motos!=NULL && tamMotos>0 &&servicios!=NULL &&tamSer>0&& clientes!=NULL && tamCli>0)
    {
        mostrarClientes(clientes,tamCli);
        printf("Ingres el ID del cliente: ");
        fflush(stdin);
        if (getInt(&id))
        {
            indice=buscarClienteById(clientes,tamCli,id);
            if(indice!=-1)
            {
               printf("TRABAJOS DEL CLIENTE: %s\n",clientes[indice].nombre);
        printf("----------------------------------------------------------------------------------------\n");
        printf("  ID         SERVICIO   PRECIO        FECHA      ID MOTO    \n\n");
        printf("-----------------------------------------------------------------------------------------\n");
     for(int j =0; j<tamMotos ; j++)
     {
         if(motos[j].idCliente == id)
         {
            for(int i = 0;i<tam;i++)
            {
                mostrarTrabajo(lista[i],servicios,tamSer);
            }
            todoOk = 1;

         }
     }

            }


        }

    }
    return todoOk;
}
int informarTotalServiciosPorFecha(eTrabajo lista[],int tam,eServicio servicios[],int tamSer)
{
 int todoOk=0;
    eFecha fecha;
    char descripcion[20];
    float precio;
    float total=0;
    int flag=1;
    if(lista!=NULL && tam>0 && servicios!=NULL && tamSer>0)
    {
        mostrarTrabajos(lista,tam,servicios,tamSer);
        if (getFecha(&fecha))
        {
            system("cls");
            printf("SERVICIOS EN LA FECHA: %2d/%2d/%d\n",fecha.dia,fecha.mes,fecha.anio);
            printf(" ID          DESCRIPCION          PRECIO\n\n");
            for(int i =0; i<tam; i++)
            {
                if(lista[i].fecha.dia == fecha.dia && lista[i].fecha.mes== fecha.mes && lista[i].fecha.anio== fecha.anio)
                {
                    cargarServicio(lista[i].idServicio,servicios,tamSer,descripcion,&precio);
                    printf(" %d\t\%10s\t\t%.2f\n",lista[i].idServicio,descripcion,precio);
                    total+=precio;
                    flag = 0;
                }

            }
            if(flag)
            {
                printf("No hay servicios para la fecha ingresada!\n\n");
            }else
            {
                printf("TOTAL: %.2f\n",total);
            }
            todoOk = 1;
        }

    }
    return todoOk;
}
