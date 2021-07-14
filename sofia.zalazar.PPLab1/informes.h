#include "moto.h"
#include "trabajo.h"
#include "tipo.h"
#include "servicio.h"
#include "color.h"
#include "cliente.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();


int mostrarMotosPorColor(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int mostrarMotosPorTipo(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int mayorCilindrada(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int listarPorTipo(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int contarTipoYColor(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
int colorMayor(eMoto lista[],int tam,eColor colores[], int tamColor);
int mostrarTrabajosMoto(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli);
int mostrarSumaServicios(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli);
int mostrarMotosPorServicio(eTrabajo lista[],int tam,eMoto motos[],int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli);
int serviciosPorFecha(eTrabajo lista[],int tam,eServicio servicios[],int tamSer);

int mostrarMotosLocalidad(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int listarMotosLocalida(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int mostrarClientesLocalidad(eCliente lista[],int tam);
int mostrarMotosPorCliente(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eCliente clientes[],int tamCli);
int mostrarTrabajosPorCliente(eTrabajo lista[],int tam,eMoto motos[],int tamMotos,eServicio servicios[],int tamSer, eCliente clientes[],int tamCli);
int informarTotalServiciosPorFecha(eTrabajo lista[],int tam,eServicio servicios[],int tamSer);
