//  Practica_4_Funcionesconretornoysinretorno_RamosGonzalez_Antonio
//  Antonio Ramos Gonzalez mt 372576
//  9/21/2023
//  Descrpcion: Este codigo imprimira la serie de fibonacci en funciones con y sin recursion, asi como el triangulo de pascal
#include <stdio.h>
#include <stdlib.h>


int msg();
void fib_s(int n);
int fib_r(int n);
int triangulo_pascal(long long int n);

int main()
{
    int n, f, opc;
    do
    {
        system("CLS");
        opc = msg();
        switch (opc)
        {
        case 1://Fibonacci sin recursion
            system("CLS");
            printf("Cuantos numeros de fibonacci quieres: ");
            scanf("%d", &n);
            fib_s(n);
            break;
        case 2://Fibonacci con recursion
            system("CLS");
            printf("Cuantos numeros de fibonacci quieres: ");
            scanf("%d", &n);
            for (int i = 0; i <= n - 1; i++)
            {
                f = fib_r(i);
                printf("%d,", f);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 3:     // tiangulo de pascal
            system("CLS");
            printf("Cuantas filas del triangulo de pascal quieres: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)// Imprime el tiangulo de pascal
            {
                for (int j = 1; j < n - i; j++)
                    printf("   ");
                for (int k = 0; k <= i; k++)
                    printf("%6d", (triangulo_pascal(i)) / (triangulo_pascal(k) * (triangulo_pascal(i - k))));
                printf("\n");
            }
            system("PAUSE");


            break;
        }
    }while(opc!=0);
    return 0;
}

// Muestra al usuario el menu de eleccion
int msg()
{
    short int opc;
    printf("Menu\n");
    printf("1.-Fibonacci sin recursion\n");
    printf("2.-Fibonacci con recursion\n");
    printf("3.-Triangulo de pascal\n");
    printf("0.-Salir\n");
    printf("Elige una opcion: ");
    scanf("%hd", &opc);
    return opc;
}

// Imprime la serie fibonacci sin recurcion
void fib_s(int n)
{
    int i, ant, act, res;
    act = 1;
    ant = -1;
    system("CLS");
    printf("Numeros de fibonacci: ");
    for (i = 0; i < n; i++)
    {
        res = ant + act;
        printf("%d,", res);
        ant = act;
        act = res;
    }
    printf("\n");
    system("PAUSE");
}

// Imprime la serie fibonacci con recurcion
int fib_r(int n)
{

    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {
        return fib_r(n - 1) + fib_r(n - 2);
    }
}

// imprime el triangulo de pascal
int triangulo_pascal(long long int n)
{
    int i = n;
    long long fact = 1;
    for (i = n; i > 1; i--)
    {
        fact *= i;
    }
    return fact;
}
