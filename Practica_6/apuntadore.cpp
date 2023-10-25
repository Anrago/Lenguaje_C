/*
 Practica_6_Apuntadores_RamosGonzalez_Antonio
 Antonio Ramos Gonzalez mt 372576
 9/30/2023
 Descrpcion: Este codigo simula un juego de loteria y un carrera coches
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Prototipos de Funciones
void imprArr(int *arr, int n);
int resultaArr(int *arr, int n);
void copiarArr(int *copia, int *orig, int n);
void concatArr(int *concat, int *arr1, int n, int *arr2, int m);
int comparArr(int *arr1, int *arr2, int n);
int maxArr(int *arr, int n);

int main()
{
    int opc, result;
    int vect1[] = {2, 5, 7, 9, 12};
    int vect2[] = {7, 1, 4, 8, 2};
    int vect3[] = {3, 6, 1, 4, 8};
    int vectCopy[5];
    int vectConcat[10];

    do
    {
        system("CLS");
        printf("MENU\n");
        printf("1.-resulta de elementos en un arreglo \n");
        printf("2.-Copia de arreglos \n");
        printf("3.-Concatenacion de arreglos \n");
        printf("4.-Comparacion de arreglos \n");
        printf("5.-Eencontrar el elemento maximo \n");
        printf("0.-Salir  \n");
        printf("Elije una opcion: ");
        scanf("%d", &opc);
        system("CLS");

        switch (opc)
        {
        case 1:
            result = resultaArr(vect1, 5);

            printf("Arreglo:\n");
            imprArr(vect1, 5);
            printf("\nEl resultado de la resulta de arreglos es: %d\n", result);
            break;

        case 2:
            copiarArr(vectCopy, vect1, 5);

            printf("Arreglo original:\n");
            imprArr(vect1, 5);
            printf("\nArreglo copia:\n");
            imprArr(vectCopy, 5);
            break;

        case 3:
            concatArr(vectConcat, vect1, 5, vect2, 5);

            printf("Arreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 2:\n");
            imprArr(vect2, 5);
            printf("\n\nArreglo Concatenado:\n");
            imprArr(vectConcat, 10);
            break;

        case 4:
            printf("Arreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 2:\n");
            imprArr(vect2, 5);

            if (comparArr(vect1, vect2, 5) == 1)
            {
                printf("\nSon iguales\n");
            }
            else
            {
                printf("\nSon distinitos\n");
            }

            printf("\n\nArreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 3:\n");
            imprArr(vect3, 5);

            if (comparArr(vect1, vect3, 5) == 1)
            {
                printf("\nSon iguales\n");
            }
            else
            {
                printf("\nSon distinitos\n");
            }
            break;

        case 5:
            printf("Arreglo 1:\n");
            imprArr(vect1, 5);

            result = maxArr(vect1, 5);
            printf("\n\nEl elemento maximo es: %d\n", result);
            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (1);
}

/*
    Función: imprArr
    Descripción: Calcula y devuelve la resulta de los elementos en un arreglo.
*/
void imprArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(arr + i));
    }
}

/*
    Función: resultaArr
    Descripción: Calcula y devuelve la resulta de los elementos en un arreglo.
*/
int resultaArr(int *arr, int n)
{
    int i, resulta = 0;

    for (i = 0; i < n; i++)
    {
        resulta += *(arr + i);
    }

    return resulta;
}

/*
    Función: copiarArr
    Descripción: Crea una copia de un arreglo en otro arreglo.
*/
void copiarArr(int *copia, int *orig, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(copia + i) = *(orig + i);
    }
}

/*
    Función: concatArr
    Descripción: Toma dos arreglos de entrada y los concatena en un tercer arreglo.
*/
void concatArr(int *concat, int *arr1, int n, int *arr2, int m)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(concat + i) = *(arr1 + i);
    }

    for (i = 0; i < m; i++)
    {
        *(concat + n + i) = *(arr2 + i);
    }
}

/*
    Función: comparArr
    Descripción: Compara dos arreglos y determina si son iguales.
*/
int comparArr(int *arr1, int *arr2, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (*(arr1 + i) != *(arr2 + i))
        {
            return 0; // No son iguales
        }
    }

    return 1; // Si son iguales
}

/*
    Función: maxArr
    Descripción: Encuentra y devuelva el elemento máximo en el arreglo.
*/
int maxArr(int *arr, int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    return max;
}