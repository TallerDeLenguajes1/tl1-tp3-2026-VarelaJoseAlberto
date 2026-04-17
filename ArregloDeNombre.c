#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// funcion para mostrar nombres
void MostrarPersonas(char *nombres[]);

// funcion para buscar nombre por palabra clave
int BuscaNombrePorPalabra(char *nombre[], char palabra[]);

// funcion para buscar nombre por id(indice)
void BuscaNombrePorId(char *nombre[], int id);

int main(int argc, char const *argv[])
{
    char *nombreDeAlumnos[5]; // vector de 5 punteros a char (nota: cada uno almacenara un nombre)
    char buff[50];            // buffer aux para guardar temporalmente los nombres
    int cantLetraNomb;        // variable que contendra la cantidad de letra del nombre

    int id;           // variable para buscar por id
    char palabra[50]; // idem al buff
    int posicion;     // variable donde contendra la posicion encontrada de la funcion buscarpornombre
    int opcion;

    // bucle para ingresar los nombres de los alumnos
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del Alumno N°%d: ", i + 1);

        // se guarda temporalmento el nombre en el buffer (nota: solo se puede guardar un solo nombre)
        // scanf("%s", buff);

        // fgets para guardar mas de un nombre (guarnar nombres seraprados por espacio (barra espaciadora))
        fgets(buff, sizeof(buff), stdin);

        // elimino el salto de linea (ENTER) que guarda el fgets
        buff[strcspn(buff, "\n")] = '\0';

        // calcula la cantidad de caracteres del nombre ingresado
        cantLetraNomb = strlen(buff);

        // reservo memoria dinamica y el +1 es para cararter nulo '\0' que indica el fin de la cadena
        nombreDeAlumnos[i] = malloc(sizeof(char) * (cantLetraNomb + 1));

        // copia el contenido del buffer a la memoria reservada
        strcpy(nombreDeAlumnos[i], buff);

        // nota si cuando me pida un nombre y solo precione ENTER dicho
        // ENTER se guardara como un nombre mas
    }

    // menu
    do
    {
        printf("\n===== MENU =====\n");
        printf("1 - Buscar por ID\n");
        printf("2 - Buscar por nombre\n");
        printf("0 - Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion)
        {
        case 1:
            printf("Ingrese ID (1-5): ");
            scanf("%d", &id);
            getchar();
            // se resta 1 porque el usuario usa 1-5
            // pero el vector usa los indices del 0-4
            BuscaNombrePorId(nombreDeAlumnos, id - 1);
            break;

        case 2:
            printf("Ingrese palabra clave: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = '\0';

            posicion = BuscaNombrePorPalabra(nombreDeAlumnos, palabra);

            if (posicion != -1)
            {
                printf("Nombre encontrado: %s\n", nombreDeAlumnos[posicion]);
            }
            else
            {
                printf("No se encontro coincidencia.\n");
            }
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    // for para liberar la memoria dinamica reservada
    for (int i = 0; i < 5; i++)
    {
        free(nombreDeAlumnos[i]);
    }

    return 0;
}

void MostrarPersonas(char *nombres[])
{
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre del alumno N°%d: %s\n", i + 1, nombres[i]);
    }
}

void BuscaNombrePorId(char *nombre[], int id)
{
    // validacion que el indice existe
    if (id >= 0 && id < 5)
    {
        // si es valido, mostramos el nombre en esa posicion (id)
        printf("\nNombre encontrado: %s\n", nombre[id]);
    }
    else
    {
        // si no es valido, mostramos mensaje de error
        printf("\nNo se encontro el id buscado\n");
    }
}

// el metodo funciona hasta que encuentra la primera coinsidencia
//  si hay mas de un nombre similar solo tomara el primero que encuentre
int BuscaNombrePorPalabra(char *nombre[], char palabra[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strstr(nombre[i], palabra) != NULL)
        {
            return i; // devuelde la posicion encontrada
        }
    }

    return -1; // no encontro coincidencia
}
