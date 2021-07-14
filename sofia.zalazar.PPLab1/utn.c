#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief indica si la cadena de caracteres es numerica
 *
 * \param cadena char*
 * \return int retorna 1 si es numerica y 0 si algun caracter no es un numero
 *
 */
int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
            {
                if(cadena[i] < '0' || cadena[i] > '9')
                {
                    retorno = 0;
                    break;
                }
                i++;
            }
    }
    return retorno;
}
/** \brief convierte la cadena de caractertes a entero
 *
 * \param pResultado int*
 * \return int retorna retorna -1 si no se puede convertir y 1 si se puede convertir
 *
 */
int getInt(int* pResultado)
{
    int ret = -1;
    char buffer[256];
    if(pResultado!=NULL)
    {
    scanf("%s", buffer);
    if(esNumerica(buffer))
    {
      *pResultado = atoi(buffer);
      ret = 1;
    }

    }

    return ret;
}
/** \brief solicita un numero al usuario lo valida entre un maximo y minimo y le da una cantidad de reintentos
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int retorna 0 si es un entero valido y -1 si no cumple las validaciones
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret = -1;
    int num;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       if(getInt(&num)== 1)
        {
       if(num <=maximo && num >= minimo)
       {
         ret = 0;
        *pResultado = num;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}

/** \brief solicita al usuario un caracter, lo valida y le da una cantidad de reintentos
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo char
 * \param maximo char
 * \param reintentos int
 * \return int retorna -1 si no se pudo tomar el caracter y 0 si se pudo tomar de manera exitosa
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int ret = -1;
    char bufferChar;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       fflush(stdin);
       if(scanf("%c", &bufferChar)== 1)
        {
       if(bufferChar <=maximo && bufferChar >= minimo)
       {
        *pResultado = bufferChar;
         ret = 0;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}


/** \brief pide al usuario que ingrese una cadena de caracteres no numericos
 *
 * \param texto char*
 * \param tam int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int retorna -1 si no se pudo tomar lo que ingresa el usuario o 0 si se puedo tomar
 *
 */
int utn_getTexto(char* texto, int tam, char* mensaje, char* mensajeError, int reintentos)
{
    int ret = -1;
    char buffer[tam];
    if(texto!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0 && reintentos>=0)
    {
        for(int i = 0; i<reintentos; i++)
        {
           printf("%s",mensaje);
           fflush(stdin);
           if(getString(buffer,tam))
           {
             strcpy(texto,buffer);
             ret = 0;
             break;
           }
           printf("%s", mensajeError);

        }
    }



    return ret;
}

/** \brief verifica que la cadena de caracteres no sea numerica
 *
 * \param texto char*
 * \param tam int
 * \return int retorna 1 si no es numerica y 0 si contiene numeros
 *
 */
int getString(char* texto, int tam)
{
    int ret = 0;
    char buffer[tam];
    scanf("%s", buffer);
    if(!esNumerica(buffer))
    {
      strcpy(texto, buffer);
      ret = 1;
    }

    return ret;
}


/** \brief toma una cadena numerica y la convierte a flotante
 *
 * \param pResultado float*
 * \return int retorna -1 si no se puede convertir y 1 si se convierte de manera exitosa
 *
 */
int getFloat(float* pResultado)
{
    int ret = -1;
    char buffer[256];
    scanf("%s", buffer);
    if(esNumericaFlotante(buffer))
    {
      *pResultado = atof(buffer);
      ret = 1;
    }

    return ret;
}

/** \brief pide al usuario que ingrese un numero flotante, lo valida y le da una cantidad de reintentos
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int retorna -1 si es invalido y 0 si es valido
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret = -1;
    float num;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       if(getFloat(&num)== 1)
        {
       if(num <=maximo && num >= minimo)
       {
         ret = 0;
        *pResultado = num;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}

/** \brief verifica que la cadena de caracteres sea numerica y que pueda contener '.'
 *
 * \param cadena char*
 * \return int retorna 0 si no es numerica y 1 si lo es
 *
 */
int esNumericaFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
            {
                if((cadena[i] < '0' || cadena[i] > '9')&& cadena[i]!= '.')
                {

                        retorno = 0;
                        break;

                }
                i++;
            }
    }
    return retorno;
}

