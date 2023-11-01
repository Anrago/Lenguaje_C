/*
Antonio Ramos Gonzalez mt:372576
25/10/2023
Descripcion:Usar apuntanodres y funciones para imprimir, leer invertir y ordenar cadenas
Taller_7ApuntadoresYCaracteres
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int msg();
void menu();
void imprimir(char *nombre[], int n);
void invertirCadena(char *nombre);
void ordenar(char *lista[], int n);
int main()
{

    menu();
    return 0;
}

int msg()
{
    system("CLS");
    int opc;
    printf("MENU\n");
    printf("1.-print Nombres\n");
    printf("2.-Dar nombres\n");
    printf("3.-Invertir\n");
    printf("4.-Lista\n");
    printf("0.-Salir\n");
    printf("Elije una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void menu()
{
    int opc, i;
    char *nombres[3];
    char *lista[5];
    nombres[0] = strdup("Alejandra");
    nombres[1] = strdup("Javier");
    nombres[2] = strdup("Julieta");

    for (i = 0; i < 5; i++)
    {
        lista[i] = strdup("");
    }

    i = 0;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:

            imprimir(nombres, 3);
            system("PAUSE");
            break;

        case 2:
            for (i = 0; i < 3; i++)
            {
                printf("Ingresa el nombre %d: ", i + 1);
                fflush(stdin);
                gets(nombres[i]);
            }
            imprimir(nombres, 3);
            system("PAUSE");
            break;

        case 3:
            while (i < 3)
            {
                invertirCadena(nombres[i]);
                i++;
            }
            imprimir(nombres, 3);
            system("PAUSE");
            break;
        case 4:
            for (i = 0; i < 5; i++)
            {
                printf("Ingresa palabra %d: ", i + 1);
                fflush(stdin);
                gets(lista[i]);
            }
            ordenar(lista, 5);
            imprimir(lista, 5);
            system("PAUSE");
            break;
        }

    } while (opc != 0);
}

void imprimir(char *nombre[], int n)
{
    system("CLS");
    for (int i = 0; i < n; i++)
    {
        printf("El nombre %d es: %s\n", i + 1, nombre[i]);
    }
}

void invertirCadena(char *nombre)
{
    int len, i = 0;
    char temp;
    len = strlen(nombre) - 1;
    while (i < len)
    {
        temp = nombre[i];
        nombre[i] = nombre[len];
        nombre[len] = temp;
        i++;
        len--;
    }
}

void ordenar(char *lista[], int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(lista[i], lista[j]) > 0)
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}
