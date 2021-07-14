#include "cliente.h"
#include "tipo.h"
#include "color.h"
#include "utn.h"
#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED



typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
    int idCliente;
} eMoto;



#endif // MOTO_H_INCLUDED


int mostrarMoto(eMoto unaMoto,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int mostrarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int listarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int inicializarMotos(eMoto lista[], int tam);
int buscarLibreMoto(eMoto lista[], int tam);
int altaMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor, int* pId, eCliente clientes[],int tamCli);



char menu();



int buscarMotoById(eMoto lista [],int tam, int id);


int bajaMoto(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);

int modificarMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);

int menuModificar();


