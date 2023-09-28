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
int iniciar_carrera();
int tiempo(int vel);

int main()
{
    register int coche1, coche2, coche3;
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
                printf("***************************************\n");
                printf("FELICIDADES GANASTE LA LOTERIA\n");
                printf("Tu numero: %d\n", numero_usuario);
                printf("Numero ganador: %d\n", numero_ganador);
                printf("***************************************\n");
            }
            else
            {
                printf("***************************************\n");
                printf("Lo siento, no has ganado\n");
                printf("Tu numero: %d\n", numero_usuario);
                printf("Numero ganador: %d\n", numero_ganador);
                printf("***************************************\n");
            }
            system("PAUSE");
            break;
        case 2:
            coche1 = iniciar_carrera();
            coche2 = iniciar_carrera();
            coche3 = iniciar_carrera();
            system("CLS");
            printf("\t TIEMPOS\n");
            printf("----------------------------\n");
            printf("COCHE 1 velocidad: %dk/h\n", coche1);
            printf("COCHE 1 tiempo: %ds\n", tiempo(coche1));
            printf("----------------------------\n");
            printf("COCHE 2 velocidad: %dk/h\n", coche2);
            printf("COCHE 2 tiempo: %ds\n", tiempo(coche2));
            printf("----------------------------\n");
            printf("COCHE 3 velocidad: %dk/h\n", coche3);
            printf("COCHE 3 tiempo: %ds\n", tiempo(coche3));
            printf("----------------------------\n");
            system("PAUSE");
            system("CLS");
            if (coche1 > coche2 && coche1 > coche3)
            {
                printf("***************************************\n");
                printf("EL GANADOR ES SERGIO PEREZ(coche 1)\n");
                printf("***************************************\n");
            }
            else
            {
                if (coche2 > coche1 && coche2 > coche3)
                {   
                    printf("***************************************\n");
                    printf("EL GANADOR ES FRANCESCO VIRGOLINI(coche 2)\n");
                    printf("***************************************\n");
                }
                else 
                {
                    printf("***************************************\n");
                    printf("LA GANADORA ES DALIA RAMOS(coche 3)\n");
                    printf("***************************************\n");
                }
            }
            system("PAUSE");
        }
    } while (opc != 0);
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

int iniciar_carrera()
{
    int velocidad;
    velocidad = rand() % 101 + 100;
    return velocidad;
}

int tiempo(int vel)
{
    int tiempo, met;
    met = (vel * 1000) / 3200;

    tiempo = 1000 / met;
    return tiempo;
}
