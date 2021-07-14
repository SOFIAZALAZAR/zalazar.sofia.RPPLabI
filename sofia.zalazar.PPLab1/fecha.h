#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;



#endif // FECHA_H_INCLUDED
int getFecha(eFecha* unaFecha);
int validarFecha(int dia, int mes, int anio);
