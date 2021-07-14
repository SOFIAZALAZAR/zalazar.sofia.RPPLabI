#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
} eTipo;



#endif // TIPO_H_INCLUDED

void mostrarTipo(eTipo unTipo);
int listarTipos(eTipo lista[],int tam);
int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[]);
