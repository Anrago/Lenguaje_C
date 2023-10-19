/*Antonio Ramos Gonzalez mt:372576
  18/10/2023
  Punteros
  Taller 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busqSeqVect(int vect[], int n, int num);
void multiplicarPorDos(int *a);
int numbRandom(int ri, int rf);
void sumarAElementos(int *arr, int n, int val);

int main()
{
    srand(time(NULL));
    int opc, *ptr, x, y, *ptrY;
    int array[7], array2[10], num;
    int *arr, *arr2, i;
    do
    {
        system("CLS");
        printf("MENU\n");
        printf("1.-Apuntadores basicos\n");
        printf("2.-Pasar Apuntadores a una Funcion\n");
        printf("3.-Arreglos\n");
        printf("4.-Modificar Elementos de un Arreglo\n");
        printf("0.-SALIR\n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &opc);
        system("CLS");
        switch (opc)
        {
        case 1:
            ptr = &x;

            x = 10;

            printf("x:%d \nptr:%d\n", x, *ptr);
            system("PAUSE");
            break;

        case 2:
            ptrY = &y;
            y = 10;
            printf("\"Y\" antes de multiplicar: %d\n", y);
            multiplicarPorDos(ptrY);
            printf("\"Y\" despues de multiplicar: %d\n", y);
            system("PAUSE");
            break;

        case 3:
            for (i = 0; i < 7; i++)
            {
                do
                {
                    num = numbRandom(0, 50);
                } while (busqSeqVect(array, 7, num) != -1);

                array[i] = num;
            }

            arr = array;

            for (i = 0; i < 7; i++)
            {
                printf("%d, ", *arr);
                arr++;
            }
            system("PAUSE");
            break;
        case 4:
            for (i = 0; i < 10; i++)
            {
                do
                {
                    num = numbRandom(0, 50);
                } while (busqSeqVect(arr2, 10, num) != -1);

                arr2[i] = num;
            }

            arr2 = array2;
            printf("Arreglo original:   ");
            for (i = 0; i < 10; i++)
            {
                printf("%d, ", *arr2);
                arr2++;
            }

            arr2 = array2;
            sumarAElementos(arr2, 10, 5);

            arr2 = array2;
            printf("\nArreglo modificado: ");
            for (i = 0; i < 10; i++)
            {
                printf("%d, ", *arr2);
                arr2++;
            }
            system("PAUSE");
            break;
        }

    } while (opc != 0);
}

void multiplicarPorDos(int *a)
{
    *a = (*a) * 2;
}

int busqSeqVect(int vect[], int n, int num)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i; // Retorna índice
        }
    }

    return -1; // No se encontró
}

int numbRandom(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

void sumarAElementos(int *arr, int n, int val)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *arr += val;
        arr++;
    }
}