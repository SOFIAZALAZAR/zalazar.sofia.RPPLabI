#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "utn.h"
#include "fecha.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"
#include "informes.h"

#define TAM  100
#define TAM_TRABAJO  500
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMSERV 4
#define TAM_CLI 100

int hardcodearTrabajos(eTrabajo lista[], int tam,int cant,int* id);
int hardcodearMotos(eMoto lista[], int tam,int cant,int* id);



int main()
{
    int flag = 1;
    int idCliente = 500;
    int idTrabajo = 1;//autoincremental
    int idMoto = 100;//autoincremental
    eTipo tipos[TAMTIPO]= {{1000,"Enduro"},{1001,"Chopera"},{1002,"Scooter"},{1003,"Ciclomotor"}};
    eColor colores[TAMCOLOR]= {{10000,"Gris"},{10001,"Negro"},{10002,"Blanco"},{10003,"Azul"},{10004,"Rojo"}};
    eServicio servicios[TAMSERV]= {{2000,"Limpieza",250},{2001,"Ajuste",300},{2002,"Balanceo",17},{2003,"Cadena",190}};
    eCliente clientes[TAM_CLI];
    inicializarClientes(clientes,TAM_CLI);
    hardcodearClientes(clientes,TAM_CLI,10,&idCliente);
    eMoto motos[TAM];
    inicializarMotos(motos,TAM);
    if(hardcodearMotos(motos,TAM,10,&idMoto)!=0)
    {
        flag = 0;
    }
    eTrabajo trabajos[TAM_TRABAJO];
    inicializarTrabajos(trabajos,TAM_TRABAJO);
    if(!flag)
    {
        hardcodearTrabajos(trabajos,TAM_TRABAJO,10,&idTrabajo);
    }
    char salir = 'n';


    do
    {

        switch (menu())
        {
        case 'A':
            if(altaMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,&idMoto,clientes,TAM_CLI))
            {
                printf("Alta exitosa!\n");
                flag = 0;
            }else{
                printf("Error. No se pudo dar de alta\n");
            }

            break;
        case 'B':
            if(flag)
            {
                printf("Primero tiene que dar de alta una moto!");
            }
            else
            {
                if(modificarMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("Modificacion Exitosa!!\n");
                }
                else
                {
                    printf("Hubo un problema en la modificacion\n");
                }
            }
            break;
        case 'C':
            if(flag)
            {
                printf("Primero tiene que dar de alta una moto!");
            }
            else
            {
                if(bajaMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("Baja exitosa!!\n");
                }
                else
                {

                    printf("Hubo un problema en la Baja\n");
                }
            }
            break;
        case 'D':
            listarMotos(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI);
            break;
        case 'E':
            listarTipos(tipos,TAMTIPO);
            break;
        case 'F':
            listarColores(colores,TAMCOLOR);
            break;
        case 'G':
            listarServicios(servicios,TAMSERV);

            break;
        case 'H':
            if(flag)
            {
                printf("Primero tiene que dar de alta una moto!");
            }
            else
            {
                if(altaTrabajo(trabajos,TAM_TRABAJO,motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,servicios,TAMSERV,&idTrabajo,clientes,TAM_CLI))
                {
                    printf("Alta exitosa!!!\n");
                }
                else
                {
                    printf("Hubo un problema en el alta.\n");
                }
            }
            break;
        case 'I':
            mostrarTrabajos(trabajos,TAM_TRABAJO,servicios,TAMSERV);
            break;
        case 'J':
            switch(menuInformes())
            {
            case 1:
                if(!mostrarMotosPorColor(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("No se pueden mostrar las motos para el ID ingresado!\n");

                }
                break;
            case 2:
                if(!mostrarMotosPorTipo(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("No se pueden mostrar las motos para el ID ingresado!\n");

                }
                break;
            case 3:
                if(!mayorCilindrada(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("Hubo un problema. No se pueden mostrar las motos!\n");

                }
                break;
            case 4:
                if(!listarPorTipo(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("Hubo un problema. No se pueden mostrar las motos!\n");

                }
                break;
            case 5:
                if(!contarTipoYColor(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR))
                {
                    printf("Hubo un problema. No se pueden mostrar las motos!\n");

                }
                break;
            case 6:
                if(!colorMayor(motos,TAM,colores,TAMCOLOR))
                {
                    printf("Hubo un problema. No se pueden mostrar las motos!\n");

                }
                break;
            case 7:
                if(!mostrarTrabajosMoto(trabajos,TAM_TRABAJO,motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,servicios,TAMSERV,clientes,TAM_CLI))
                {
                    printf("No se pueden mostrar los trabajos para el ID ingresado!\n");

                }
                break;
            case 8:
                if(!mostrarSumaServicios(trabajos,TAM_TRABAJO,motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,servicios,TAMSERV,clientes,TAM_CLI))
                {
                    printf("Hubo un error, no se puede mostrar el total!\n");

                }
                break;
            case 9:
                if(!mostrarMotosPorServicio(trabajos,TAM_TRABAJO,motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,servicios,TAMSERV,clientes,TAM_CLI))
                {
                    printf("No se pueden mostrar las motos para el ID ingresado!\n");

                }

                break;
            case 10:
                if(!serviciosPorFecha(trabajos,TAM_TRABAJO,servicios,TAMSERV))
                {
                    printf("No se pueden mostrar los servicios para la fecha indicada!\n");

                }
                break;
            case 11:
                if(!mostrarMotosLocalidad(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                {
                    printf("No se pueden mostrar las motos para la localidad ingresada!\n");

                }
                break;
                case 12:
                    if(!listarMotosLocalida(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                    {
                        printf("No se pueden mostrar la lista de motos!\n");
                    }
                break;
                case 13:
                    if(!mostrarClientesLocalidad(clientes,TAM_CLI))
                {
                    printf("No hay clientes para la localidad ingresada!\n");

                }
                break;
                case 14:
                    if(!mostrarMotosPorCliente(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAM_CLI))
                    {
                        printf("No hay motos para el cliente ingresado!\n");
                    }

                break;
                case 15:
                    if(!mostrarTrabajosPorCliente(trabajos,TAM_TRABAJO,motos,TAM,servicios,TAMSERV,clientes,TAM_CLI))
                    {
                        printf("No hay trabajos para el cliente ingresado!\n");
                    }

                break;
                case 16:
                    if(!informarTotalServiciosPorFecha(trabajos,TAM_TRABAJO,servicios,TAMSERV))
                {
                    printf("No se pueden mostrar los servicios para la fecha indicada!\n");

                }
                break;
                case 17:
                break;
               /* case 18:
                break;
                case 19:
                break;*/
            }

            break;
        case 'K':
            if(altaCliente(clientes,TAM_CLI,&idCliente))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("No se pudo hacer el alta\n");
            }
            break;
        case 'L':
            printf("Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            while(salir!= 'n' && salir!= 's')
            {
                printf("Confirma salida?: ");
                fflush(stdin);
                salir = getchar();
            }
            printf("\n\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(salir == 'n');



    return 0;
}




int hardcodearMotos(eMoto lista[], int tam,int cant,int* id)
{
    int cantidad = 0;
    char mMarca[10][20]= {"zanella","gilera","bmw","yamaha","gilera","corven","motomel","bmw","yamaha","honda"};
    int clilindradas[10] = {50,125,500,600,750,50,125,500,600,250};
    int tipo[10]= {1000,1002,1000,1003,1001,1001,1001,1003,1002,1000};
    int color[10]= {10000,10001,10003,10002,10003,10004,10002,10003,10002,10003};
    int clientes[10]= {500,505,503,507,506,506,504,505,507,503};

    if(lista!=NULL && tam>0 && cant >= 0 && cant <= tam && id!= NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *id;
            (*id)++;
            strcpy(lista[i].marca, mMarca[i]);
            lista[i].idTipo = tipo[i];
            lista[i].idColor = color[i];
            lista[i].cilindrada = clilindradas[i];
            lista[i].idCliente = clientes[i];
            lista[i].isEmpty = 0;
            cantidad ++;
        }
    }
    return cantidad;
}


int hardcodearTrabajos(eTrabajo lista[], int tam,int cant,int* id)
{
    int idServicios[10]= {2000,2003,2001,2002,2001,2001,2003,2001,2003,2000};
    int Mot[10] = {100,102,102,103,104,109,106,107,108,109};
    int dia[10] = {06,06,07,06,10,11,11,14,30,25};
    int mes[10] = {11,12,10,07,06,05,05,06,06,11};
    int anio[10]= {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021};
    int todoOk=0;
    if(lista!=NULL && tam>0 && cant>0 && cant<=tam && id!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i].id = *id;
            (*id)++;
            lista[i].idMoto = Mot[i];
            lista[i].idServicio = idServicios[i];
            lista[i].fecha.dia = dia[i];
            lista[i].fecha.mes = mes[i];
            lista[i].fecha.anio = anio[i];
            lista[i].isEmpty = 0;
        }
        todoOk=1;
    }
    return todoOk;
}

