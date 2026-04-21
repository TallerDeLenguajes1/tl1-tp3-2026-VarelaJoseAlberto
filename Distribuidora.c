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
    srand(time(NULL)); // inicio una semilla para generar diferentes numeros al alzar

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
        buff[strcspn(buff, "\n")] = '\0'; // quito el salto de linea (ENTER)

        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = malloc(strlen(buff) + 1);
        strcpy(clientes[i].NombreCliente, buff);

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;

            int indiceTipo = rand() % 5;
            clientes[i].Productos[j].TipoProducto = TiposProductos[indiceTipo];

            clientes[i].Productos[j].PrecioUnitario = (float)(rand() % 91 + 10);

        }
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("id: %d\n  nombre: %s\n  cantproductos: %d\n",
               clientes[i].ClienteID, clientes[i].NombreCliente, clientes[i].CantidadProductosAPedir);
    
    for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
    {
        Producto p =clientes[i].Productos[j];
        printf("%s %d $%f\n", 
                   p.TipoProducto, p.Cantidad, p.PrecioUnitario);
    }
    
            }

    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}
