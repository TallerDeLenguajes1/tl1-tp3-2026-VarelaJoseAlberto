#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100

} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
                                 //  “CantidadProductosAPedir”

} Cliente;

int main(int argc, char const *argv[])
{

    int cantidadClientes; // cantidad de clientes que vamos a tenes
    Cliente *clientes;    // puntero a la estructura del cliente
    char buff[50];        // aux para almacenar temporalmente un nombre

    printf("Ingrese la cantidad de clientes: ");
    while (scanf("%d", &cantidadClientes) != 1 || cantidadClientes <= 0)
    {
        printf("Error. Ingrese solo numeros...\n");
        while (getchar() != '\n')
            ;
    }
    while (getchar() != '\n')
        ; // limpia el ENTER pendiente

    clientes = malloc(sizeof(Cliente) * cantidadClientes);

    printf("Se reservaron %d clientes.\n", cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++)
    {

        printf("Ingrese el nombre del cliente N° %d: ", i + 1);

        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';

        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = malloc(strlen(buff) + 1);

        strcpy(clientes[i].NombreCliente, buff);
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("id: %d - nombre: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);
    }
    free(clientes);

    return 0;
}
