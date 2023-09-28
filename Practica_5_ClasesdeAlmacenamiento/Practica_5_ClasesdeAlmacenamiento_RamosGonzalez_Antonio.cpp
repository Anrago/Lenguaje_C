//  Practica_4_Funcionesconretornoysinretorno_RamosGonzalez_Antonio
//  Antonio Ramos Gonzalez mt 372576
//  9/21/2023
//  Descrpcion: Este codigo imprimira la serie de fibonacci en funciones con y sin recursion, asi como el triangulo de pascal
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int numero_ganador = 0;

int msg();
int numero_loteria();

int main()
{
    
    int numero_usuario, opc;
    srand(time(NULL));
    do
    {

        opc = msg();
        switch (opc)
        {
        case 1:
            if (numero_ganador == 0)
            {
                numero_ganador = numero_loteria();
            }
            numero_usuario = numero_loteria();

            system("CLS");
            if (numero_usuario == numero_ganador)
            {
                printf("FELICIDADES GANASTE LA LOTERIA\n");
                printf("Tu numero: %d\n", numero_usuario);
                printf("Numero ganador: %d\n", numero_ganador);
            }
            else
            {
                printf("Lo siento, no has ganado\n");
                printf("Tu numero: %d\n", numero_usuario);
                printf("Numero ganador: %d\n", numero_ganador);
            }
            system("PAUSE");
            break;
        }
    } while (opc!=0);
    return 0;
}

int msg()
{
    int opc;
    system("CLS");
    printf("MENU\n");
    printf("1.-Juego de la loteria\n");
    printf("2.-Carrera de coches\n");
    printf("0.-Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int numero_loteria()
{
    static int numero_generado;
    numero_generado = rand() % 100 + 1;
    return numero_generado;
}