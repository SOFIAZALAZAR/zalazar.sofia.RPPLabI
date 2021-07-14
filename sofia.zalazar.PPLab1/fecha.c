#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "utn.h"


/** \brief pide al usuario que ingrese una fecha y la valida
 *
 * \param unaFecha eFecha* puntero a la fecha
 * \return int retorna 1 si la fecha es valida
 *                     0 si la fecha es invalida
 *
 */
int getFecha(eFecha* unaFecha)
{
   int todoOk =0;
   eFecha auxFecha;
   if(unaFecha!=NULL){
       printf("Ingrese Fecha(dd/mm/aaaa): ");
       fflush(stdin);
   if(scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio)==3)
    {
     if(validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio))
     {
        *unaFecha = auxFecha;
        todoOk = 1;
     }
    }

   }
   return todoOk;
}

int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if( mes >= 1 && mes <= 12 )
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia >= 1 && dia <= 31)
            {
                todoOk = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia >= 1 && dia <= 30)
            {
                todoOk = 1;
            }
            break;
        case 2:
            if((anio%4 == 0 && anio%100 != 0) || anio%400 == 0)
            {
                if(dia >= 1 && dia <= 29)
                {
                    todoOk = 1;
                }
            }
            else
            {
                if(dia >= 1 && dia <= 28)
                {
                    todoOk = 1;
                }
            }
            break;
        }
    }
    return todoOk;
}
