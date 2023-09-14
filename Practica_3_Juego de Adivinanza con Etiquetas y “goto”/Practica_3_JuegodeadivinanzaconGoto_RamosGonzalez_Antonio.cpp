//  Practica_3_JuegodeadivinanzaconGoto_RamosGonzalez_Antonio
//  Antonio Ramos Gonzalez mt 372576
//  9/6/2023
//  Descrpcion: Este codigo se presenta un juego de adivinar un numero usando sentencias goto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    // Generamos la semilla del random y declaro variables
    srand(time(NULL));
    int y = 1, x, n;
    int tent = 0;

// Goto que se encarga de presentar al jugador el juego
inicio:

    system("CLS");
    n = rand() % 100 + 1; // Genera numeros del 1 al 100

    printf("\nse ha generado un numero del 1 al 100. intenta adivinarlo\n");
    system("PAUSE");
    system("CLS");

// Goto que se encarga de recibir y comparar el dato recibido para var si el usuario te esta acercando al numero secreto
adivinanza:
    printf("Ingresa un numero\n");
    tent = 0;
    while (x != n)
    {

        scanf("\n%d", &x);
        if (x == n) // si x==n el jugador gana
        {
            tent++;
            printf("Felicidades ganaste\n");
            printf("Intentos:%d\t\n", tent);
        }
        if (x < n) // si x<n envia mensaje de que el numero esta mas arriba
        {
            printf("mas arriba\n");
        }
        else
        {
            if (x > n) // si x<n envia mensaje de que el numero esta mas abajo
            {
                printf("mas abajo\n");
            }
        }
        tent++;
    }

// Goto que se encarga de  preguntarle al jugador si desea jugar de nuevo
reinicio:
    system("PAUSE");
    system("CLS");
    printf("Desea Jugar de nuevo?\n");
    printf("1.-si\t2,-no\n");
    scanf("%d", &y);
    if (y == 2)
    {
        system("CLS");
        printf("Hasta luego!!");
    }
    if (y != 1 && y != 2)
    {
        system("CLS");
        printf("error\n");
        goto reinicio;
    }
    // en este while se mandan llamar los gotos anteriores y sirve para reiniciar el "juego"
    while (y != 2)
    {

        goto inicio;

        goto adivinanza;

        goto reinicio;

        system("CLS");
    }
    return 0;
}
