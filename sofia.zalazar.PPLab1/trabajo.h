#include "fecha.h"
#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;


#endif // TRABAJO_H_INCLUDED



int inicializarTrabajos(eTrabajo lista[], int tam);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, int* pId, eCliente clientes[],int tamCli);
void mostrarTrabajo(eTrabajo unTrabajo,eServicio servic[], int tamServ);
int mostrarTrabajos(eTrabajo lista[], int tam,eServicio servic[], int tamServ);


