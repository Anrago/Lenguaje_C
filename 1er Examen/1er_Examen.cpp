#include <stdio.h>
#include <stdlib.h>

int validar(const char msg[]);

int main()
{
    int n, i,opc;
    int acum;
    do
    {
        system("CLS");
        n = validar("Ingrese un numero: ");
        acum = 0;
        printf("Numero:%d\n", n);
        printf("Divisores perfectos: ");
        for (i = n - 1; i > 0; i--)
        {
            if (n % i == 0)
            {
                acum += i;
                printf("%d,", i);
            }
        }
       printf("\n");

        if (acum == n)
        {

            printf("EL NUMERO ES PERFECTO\n");
        }
        else
        {
            system("CLS");
            printf("EL NUMERO NO ES PERFECTO\n");
        }

        system("PAUSE");
        system("CLS");
        printf("desea buscar numeros perfectos en otro rango\n");
        printf("1.-Si\n");
        printf("0.-No\n");
        scanf("%d",&opc);
    } while (opc!=0);
}

int validar(const char msg[])
{
    int n;
    do
    {
        system("CLS");
        printf("%s", msg);
        scanf("%d", &n);
        if (n < 1)
        {

            printf("SOLO NUMEROS POSITIVOS\n");
        }

    } while (n < 1);
    return n;
}