#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declaracion de funcion para mostrar nombres
void MostrarPersonas(char *nombres[]);
// funcion para buscar nombre por palabra clave
int BuscarNombrePorPalabra(char *nombre[], char palabra[]);

int main(int argc, char const *argv[])
{
    char *nombreDeAlumnos[5]; // vector de 5 punteros a char (nota: cada uno almacenara un nombre)

    char buff[50]; // buffer aux para guardar temporalmente los nombres

    int cantLetraNomb; // variable que contendra la cantidad de letra del nombre

    char palabra[50]; // idem al buff
    int posicion; // variable donde contendra la posicion encontrada de la funcion buscarpornombre

    // bucle para ingresar los nombres de los alumnos
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del Alumno N°%d: ", i + 1);
        // scanf("%s", buff);                                             // se guarda temporalmento el nombre en el buffer (nota: solo se puede guardar un solo nombre)
        fgets(buff, sizeof(buff), stdin);                                // fgets para guardar mas de un nombre
        buff[strcspn(buff, "\n")] = '\0';                                // elimino el enter al final de cargar los nombres
        cantLetraNomb = strlen(buff);                                    // calcula la longitud del nombre ingresado
        nombreDeAlumnos[i] = malloc(sizeof(char) * (cantLetraNomb + 1)); // reservo memoria dinamica y el +1 es para cararter nulo '\0' que indica el fin de la cadena
        strcpy(nombreDeAlumnos[i], buff);                                // copia el contenido del buffer a la memoria reservada
        // nota si cuando me pida un nombre y solo precione ENTER dicho
        // ENTER se guardara como un nombre mas
    }

    MostrarPersonas(nombreDeAlumnos);

    printf("Ingrese palabra clave: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';

    posicion=BuscarNombrePorPalabra(nombreDeAlumnos,palabra);

    if (posicion!=1)
    {
        printf("nombre encontrado: %s\n",nombreDeAlumnos[posicion]);
    }
    else
    {
        printf("no se encontro coincidencia.\n");
    }
    

    // for para liberar la memoria dinamica reservada
    for (int i = 0; i < 5; i++)
    {
        free(nombreDeAlumnos[i]);
    }
    return 0;
}

void MostrarPersonas(char *nombres[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre del alumno N°%d: %s\n", i + 1, nombres[i]);
    }
}

//el metodo funciona hasta que encuentra la primera coinsidencia
// si hay mas de un nombre similar solo tomara el primero que encuentre
int BuscarNombrePorPalabra(char *nombre[], char palabra[])
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
