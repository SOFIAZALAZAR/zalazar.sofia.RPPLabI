#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char normbreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED
void mostrarColor(eColor unColor);
int listarColores(eColor lista[],int tam);
int cargarDescripcionColor(int id, eColor colores[],int tam, char desc[]);
