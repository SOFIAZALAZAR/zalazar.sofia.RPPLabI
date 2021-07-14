#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicio(eServicio unServicio);
int listarServicios(eServicio lista[],int tam);
int cargarServicio(int id, eServicio servicios[],int tam, char desc[], float* precio);
