/*
 Practica_7_Punteros_RamosGonzalez_Antonio
 Antonio Ramos Gonzalez mt 372576
 9/30/2023
 Descrpcion: Se pediran Argumentos en la funcion main.
*/
#include "Babilonia.h"
#define Num_argum  5

void Argumen(char *argv[]);
void orderPal();
void MatMulti();

//Pide argumentos que seran dados por el susuarioen la consola
int main(int argc, char *argv[])
{
    int opc;
    do
    {
        system("CLS");
        printf("MENU\n");
        printf("1.-Argumentos En la linea de comandos \n");
        printf("2.-Ordenacion de palabras \n");
        printf("3.-Matriz multidimensional \n");
        printf("0.-Salir  \n");
        opc=valid("Elije una opcion: ", 0, 3);
        system("CLS");
        switch (opc)
        {
        case 1:

            Argumen(argv);
            system("PAUSE");
            break;
        case 2:
            orderPal();
            system("PAUSE");
            break;
        case 3:
            MatMulti();
            system("PAUSE");
            break;       
        
        }
    } while (opc != 0);

    return 0;
}

//recivira datos mediante la consola  y realizara las operaciones basicas
//Practica_7_Punteros_RamosGonzalez_Antonio num1 num2
void Argumen(char *argv[])
{
    int num1=atoi(argv[1]);
    int num2=atoi(argv[2]);

    printf("TUS NUMEROS FUERON: %d y %d\n",num1,num2);
    printf("LA SUMA ES: %d\n",num1+num2);
    printf("LA RESTA ES: %d\n",num1-num2);
    printf("LA MULTIPLICACION ES: %d\n",num1*num2);
    printf("LA DIVISION ES: %d\n",num1/num2);

}

//Funcion que ordenara distintas palbaras
void orderPal()
{
    char *palabras[Num_argum] = {"manzana", "banana", "cereza", "uva", "naranja"};
    char *temp;
    int i, j;

    for (i = 0; i < Num_argum - 1; i++)
    {
        for (j = i + 1; j < Num_argum; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    for (i = 0; i < Num_argum; i++)
    {
        printf("%s\n", palabras[i]);
    }
}

//Realiza la suma de todos los elementos de la matriz
//Asi como el numero mas grande y su poscicion actual
void MatMulti()
{
    int matriz[3][3] = {{2, 2, 5}, {6, 2, 10}, {4, 9, 5}};
    int max = 0, fila = 0, col = 0, suma = 0;
    int *ptr = &matriz[0][0];

    for (int i = 0; i < 3 * 3; i++)
    {
        suma += *ptr;
        if (*ptr > max)
        {
            max = *ptr;
            fila = i / 3;
            col = i % 3;
        }
        ptr++;
    }

    printf("\nSuma de la matriz: %d\n", suma);
    printf("Elemento mas grande: %d\n", max);
    printf("Fila %d\nColumna %d\n", fila, col);
}