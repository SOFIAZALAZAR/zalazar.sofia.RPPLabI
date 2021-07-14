#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int inicializarClientes(eCliente lista[], int tam)
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
int buscarLibreCliente(eCliente lista[], int tam)
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
int altaCliente(eCliente lista[],int tam, int* pId)
{
    int todoOk;
    int i;
    eCliente aux;
    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        i = buscarLibreCliente(lista,tam);
        if(i!=-1)
        {
            printf("ID: %d\n",*pId);
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(aux.nombre);
            printf("Ingrese Sexo(f o m): ");
            fflush(stdin);
            aux.sexo = getchar();
            while(aux.sexo!= 'm' && aux.sexo!= 'f')
            {
                printf("Sexo Invalido.Ingrese Sexo(f o m): ");
                fflush(stdin);
                aux.sexo = getchar();
            }
            printf("Ingrese Localidad: ");
            fflush(stdin);
            gets(aux.localidad);
            aux.id = *pId;
            (*pId)++;
            lista[i] = aux;
            todoOk=1;
        }

    }

    return todoOk;

}
void mostrarCliente(eCliente cliente)
{
    printf("%d\t%10s\t%c\t%10s\n",cliente.id,cliente.nombre,cliente.sexo,cliente.localidad);
}
int mostrarClientes(eCliente lista[],int tam)
{
    int sinClientes = 1;
    int todoOk = 0;
    printf("                  |   CLIENTES  |\n\n");
    printf("-------------------------------------------------\n");
    printf("  ID   |     NOMBRE   |    SEXO   | LOCALIDAD\n\n");
    printf("-------------------------------------------------\n");
    if(lista!=NULL && tam>0 )
    {

        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarCliente(lista[i]);
                sinClientes = 0;
                todoOk=1;
            }
        }
        if(sinClientes)
        {
            printf("No hay Clientes Cargados.");
        }
        printf("\n\n");
    }
    return todoOk;
}
int buscarClienteById(eCliente lista[], int tam, int id)
{
    int indice = -1;

    if(lista!= NULL && tam > 0 && id>=500)
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
int cargarNombreCliente(int id,eCliente lista[],int tam, char nombre[])
{
    int todoOk = 0;
    if(buscarClienteById(lista,tam,id)!=-1 && nombre != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(nombre, lista[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;

}
int cargarLocalidadCliente(int id,eCliente lista[],int tam, char localidad[])
{
    int todoOk = 0;
    if(buscarClienteById(lista,tam,id)!=-1 && localidad != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(localidad, lista[i].localidad);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;

}


int hardcodearClientes(eCliente lista[], int tam, int cant,int* id)
{
    int cantidad = 0;
    eCliente clientes[10]=
    {
        {500,"Donato",'m',"azul"}
        ,{501,"Carmen",'f',"avellaneda"}
        ,{502,"Chepi",'f',"bragado"}
        ,{503,"Alex",'m',"bragado"}
        ,{504,"German",'m',"gerli"}
        ,{505,"Maria",'f',"avellaneda"}
        ,{506,"Damian",'m',"lincoln"}
        ,{507,"Daniel",'m',"dolores"}
        ,{508,"Andrea",'f',"avellaneda"}
        ,{509,"Candela",'f',"berazategui"}
    };

    if(lista!=NULL && tam>0 && cant>0 && cant <= tam && id != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *id;
            (*id)++;
            strcpy(lista[i].nombre, clientes[i].nombre);
            lista[i].sexo = clientes[i].sexo;
            strcpy(lista[i].localidad, clientes[i].localidad);
            lista[i].isEmpty = 0;
            cantidad ++;
        }
    }
    return cantidad;
}
