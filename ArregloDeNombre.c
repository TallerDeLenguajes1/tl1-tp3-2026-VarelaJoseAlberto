#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declaracion de funcion para mostrar nombres
void MostrarPersonas(char *nombres[]);

int main(int argc, char const *argv[])
{
    char *nombreDeAlumnos[5]; // vector de 5 punteros a char (nota: cada uno almacenara un nombre)

    char buff[50]; // buffer aux para guardar temporalmente los nombres

    int cantLetraNomb; // variable que contendra la cantidad de letra del nombre

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
        //nota si cuando me pida un nombre y solo precione ENTER dicho
        //ENTER se guardara como un nombre mas
    }

    MostrarPersonas(nombreDeAlumnos);

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