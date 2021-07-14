
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    char localidad[20];
    int isEmpty;
} eCliente;

#endif // CLIENTE_H_INCLUDED

int hardcodearClientes(eCliente lista[], int tam, int cant,int* pLegajo);
int inicializarClientes(eCliente lista[], int tam);
int altaCliente(eCliente lista[],int tam, int* pId);
void mostrarCliente(eCliente cliente);
int mostrarClientes(eCliente lista[],int tam);
int cargarNombreCliente(int id, eCliente lista[],int tam, char nombre[]);
int cargarLocalidadCliente(int id,eCliente lista[],int tam, char localidad[]);
int buscarClienteById(eCliente lista[], int tam, int id);
int buscarLibreCliente(eCliente lista[], int tam);
