#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moto.h"


char menu()
{
    char opcion;
    printf("\t\t***Menu Empleados***\n\n");
    printf("A.	ALTA MOTO\n");
    printf("B.	MODIFICAR MOTO\n");
    printf("C.	BAJA MOTO\n");
    printf("D.	LISTAR MOTOS\n");
    printf("E.	LISTAR TIPOS\n");
    printf("F.	LISTAR COLORES\n");
    printf("G.	LISTAR SERVICIOS\n");
    printf("H.	ALTA TRABAJO\n");
    printf("I.	LISTAR TRABAJOS\n");
    printf("J.\tINFORMES\n");
    printf("K.	ALTA CLIENTE\n");
    printf("L.	SALIR\n");
    utn_getCaracter(&opcion,"Ingrese Opcion: ","Opcion invalida, ",'A','l',10);
    opcion= toupper(opcion);
    printf("\n\n");
    return opcion;
    return opcion;
}



/** \brief muestra lo que esta cargado en los campos de una estructura
 *
 * \param unaMoto eMoto
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0 si el array es NULL o tam es <0 y 1 si se puede mostrar
 *
 */
int mostrarMoto(eMoto unaMoto,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char nombre[20];
    char loc[20];
    int todoOk = 0;
    if( tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0)
    {
        if (cargarDescripcionTipo(unaMoto.idTipo,tipos,tamTipos,descripcionTipo)
            && cargarDescripcionColor(unaMoto.idColor,colores,tamColor,descripcionColor)
            &&cargarNombreCliente(unaMoto.idCliente,clientes,tamCli,nombre)
            &&cargarLocalidadCliente(unaMoto.idCliente,clientes,tamCli,loc))
        {
            printf("%3d\t%10s\t%10s    %10s\t%3d\t%10s    %10s\n"
                   ,unaMoto.id
                   ,unaMoto.marca
                   ,descripcionTipo
                   ,descripcionColor
                   ,unaMoto.cilindrada
                   ,nombre
                   ,loc
                  );
        }
        todoOk = 1;
    }
    return todoOk;

}


/** \brief muestra lo que esta cargado en el array
 *
 * \param motos[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0 si no hay nada cargado o si el array es NULL o el tam <0 y retorna 1 si se puede mostrar
 *
 */
int mostrarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int sinMotos = 1;
    int todoOk = 0;
    printf("                  |Lista de Motos|\n\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("  ID   |     Marca    |    Tipo     |    Color  |   Cilindrada  |  Cliente  |  Localidad\n\n");
    printf("-----------------------------------------------------------------------------------------\n");
    if(motos!=NULL&&tam>0 && tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0)
    {

        for(int i=0; i<tam; i++)
        {
            if(!motos[i].isEmpty)
            {
                mostrarMoto(motos[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
                sinMotos = 0;
                todoOk=1;
            }
        }
        if(sinMotos)
        {
            printf("No hay Motos que mostrar.");
        }
        printf("\n\n");
    }
    return todoOk;
}

/** \brief lista las motos cargadas y las ordena por tipo y por id
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamaño del array de motos
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0 si no las pudo listar y 1 si las lista de manera exitosa
 *
 */
int listarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    char descripcion1[20];
    char descripcion2[20];
    eMoto auxMoto;
    if(motos!=NULL&&tam>0 && tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0 && clientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                cargarDescripcionTipo(motos[i].idTipo,tipos,tamTipos,descripcion1);
                cargarDescripcionTipo(motos[j].idTipo,tipos,tamTipos,descripcion2);
                if((strcmp(descripcion1,descripcion2)>0)|| (motos[i].id > motos[j].id && strcmp(descripcion1,descripcion2)==0))
                {
                    auxMoto = motos[i];
                    motos[i] = motos [j];
                    motos[j] = auxMoto;
                }
            }
        }
        todoOk = 1;
        mostrarMotos(motos,tam,tipos,tamTipos,colores,tamColor,clientes,tamCli);
    }
    return todoOk;

}

/** \brief inicializa todo el array como isEmpty
 *
 * \param lista[] eMoto
 * \param tam int
 * \return int retorna 1 si se hizo de manera exitosa o 0 si no lo hizo
 *
 */
int inicializarMotos(eMoto lista[], int tam)
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



/** \brief busca una moto en el listado por el ID
 *
 * \param [] eMoto lista array
 * \param tam int tamaño del array
 * \param id int ID a buscar
 * \return int retorna indice del array o -1 si no encuentra el id en el array
 *
 */
int buscarMotoById(eMoto lista [],int tam, int id)
{
    int indice = -1;

    if(lista!= NULL && tam > 0 && id>=100)
    {
        for(int i =0; i<tam; i++)
        {
            if(lista[i].id == id && !lista[i].isEmpty)
            {
                indice = i;
                break;
            }

        }
    }
    return indice;
}

/** \brief busca una moto en el listado ya cargado y realiza la baja logica
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0 si no se pude realizar y 1 si se puede generar la baja
 *
 */
int bajaMoto(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int id;
    int i = -1;
    char confirmacion = 'n';
    system("cls");
    printf("              Baja Moto\n\n");
    if(mostrarMotos(lista,tam,tipos,tamTipos,colores,tamColor,clientes,tamCli))
    {
        printf("Ingrese el ID de la moto que quiere dar de baja: ");
        fflush(stdin);
        if(getInt(&id)==1)
        {
            i = buscarMotoById(lista,tam,id);
        }
        if(i == -1)
        {
            printf("No hay ninguna moto registrado con el ID: %d\n",id);
        }
        else
        {
            mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
            printf("Confirma baja?: ");
            fflush(stdin);
            confirmacion = getchar();
            if(confirmacion == 's')
            {
                lista[i].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}



/** \brief muestra las opciones para modificar
 *
 * \return int retorna la opcion elegida
 *
 */
int menuModificar()
{
    int opcion;
    printf("  Modificar Moto\n\n");
    printf("1 Color\n");
    printf("2 Cilindrada\n");
    printf("3 Salir\n");
    utn_getNumero(&opcion,"Ingrese Opcion: ","ERROR, ",1,3,10);
    printf("\n\n");
    return opcion;

}

/** \brief busca una moto en el listado ya cargado y permite modificar el color y tipo
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \return int retorna 0 si no se pude realizar y 1 si se pudo modificar
 *
 */
int modificarMoto(eMoto lista[],int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int id;
    int i;

    char confirmacion = 'n';
    char salir = 'n';

    eMoto auxMoto;
    system("cls");

    if(mostrarMotos(lista,tam,tipos,tamTipos,colores,tamColor,clientes,tamCli))
    {

        printf("Ingrese el ID de la moto que quiere modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        system("cls");

        if(getInt(&id))
        {
            i = buscarMotoById(lista,tam,id);
                if(i!=-1)
            {
                auxMoto = lista[i];
                do
                {
                    printf("\n\n");
                    mostrarMoto(auxMoto,tipos,tamTipos,colores,tamColor,clientes,tamCli);
                    printf("\n\n");
                    switch(menuModificar())
                    {
                    case 1:
                        listarColores(colores,tamColor);
                        printf("Ingrese ID color: ");
                        fflush(stdin);
                        getInt(&auxMoto.idColor);
                        while(auxMoto.idColor>=10000 && auxMoto.idColor<=10004)
                        {
                            printf("Ingrese ID color valido: ");
                            fflush(stdin);
                            getInt(&auxMoto.idColor);
                        }
                        break;
                    case 2:
                        printf("Ingrese cilindrada (50, 125, 500, 600, 750): ");
                        fflush(stdin);
                        getInt(&auxMoto.cilindrada);
                        while(auxMoto.cilindrada==50||auxMoto.cilindrada==125||auxMoto.cilindrada==500||auxMoto.cilindrada==600||auxMoto.cilindrada==750)
                        {
                            printf("Dato invalido. Ingrese cilindrada (50, 125, 500, 600, 750): ");
                            fflush(stdin);
                            getInt(&auxMoto.cilindrada);
                        }
                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                }
                while(salir == 'n');
                system("cls");
                printf("\n\n");
                mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor,clientes,tamCli);
                printf("\nModificacion: \n\n");
                mostrarMoto(auxMoto,tipos,tamTipos,colores,tamColor,clientes,tamCli);
                printf("Confirma modificacion?: ");
                fflush(stdin);
                confirmacion = getchar();
                if(confirmacion == 's')
                {
                    lista[i] = auxMoto;
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("No se encontro el ID ingresado!\n");
        }
    }
    return todoOk;
}




/** \brief busca si hay un lugar vacio en un array de motos
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamaño del array
 * \return int retorna el indice del primer lugar vacio o -1 si el array esta completo
 *
 */
int buscarLibreMoto(eMoto lista[], int tam)
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

/** \brief agrega una moto a la lista de trabajos
 *
 * \param lista[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTipos int
 * \param colores[] eColor
 * \param tamColor int
 * \param pId int*
 * \return int retorna 0 si no se hace el alta o 1 si se pudo
 *
 */
int altaMoto(eMoto lista[],int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, int* pId, eCliente clientes[],int tamCli)
{
    int ok = 0;
    eMoto auxMoto;
    int i;
    system("cls");
    printf("   Alta Moto\n\n");
    printf("ID Moto: %d\n", *pId);
    if(lista!= NULL && tam > 0 && pId!=NULL)
    {
        i = buscarLibreMoto(lista,tam);
        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese la marca: ");
            fflush(stdin);
            gets(auxMoto.marca);
            listarTipos(tipos,tamTipos);
            printf("Ingrese el ID del tipo de moto: ");
            fflush(stdin);
            if (getInt(&auxMoto.idTipo) && auxMoto.idTipo>=1000 && auxMoto.idTipo<= 1003)
            {
                listarColores(colores,tamColor);
                printf("Ingrese ID del color: ");
                if(getInt(&auxMoto.idColor)&& auxMoto.idColor>=10000 && auxMoto.idColor<=10004)
                {
                    printf("Ingrese cilindrada (50, 125, 500, 600, 750): ");
                    if(getInt(&auxMoto.cilindrada) && (auxMoto.cilindrada==50||auxMoto.cilindrada==125||auxMoto.cilindrada==500||auxMoto.cilindrada==600||auxMoto.cilindrada==750))
                    {
                        mostrarClientes(clientes,tamCli);
                        printf("Ingrese el ID del cliente: ");
                        if(getInt(&auxMoto.idCliente)&& buscarClienteById(clientes,tamCli,auxMoto.idCliente))
                        {
                            auxMoto.isEmpty = 0;
                            auxMoto.id = *pId;
                            lista[i] = auxMoto;
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
