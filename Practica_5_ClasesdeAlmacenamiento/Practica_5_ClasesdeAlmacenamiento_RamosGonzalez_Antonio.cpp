//  Practica_5_ClasesdeAlmacenamiento_RamosGonzalez_Antonio
//  Antonio Ramos Gonzalez mt 372576
//  9/30/2023
//  Descrpcion: Este codigo simula un juego de loteria y un carrera coches

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//variable estatica para funcion numero_loteria
static int numero_ganador = 0;

int msg(); //imprime un menu de opciones
int numero_loteria();//genera un numero random deo 1 al 100
void iniciar_carrera();//simula una carrera de coches
int velocidad();//genera una velocidad para cadad coche(100-200)
float tiempo(int vel);//tiempo en el que llegaron a la meta

int main()
{
    int opc;//variable de eleccion del menu
    int numero_usuario;//numero de loteria para el usuario
    srand(time(NULL));
    do// controla el menu
    {

        opc = msg();
        switch (opc)
        {
        case 1:

            if (numero_ganador == 0)//valida que numero ganador sea igual a 0
            {
                numero_ganador = numero_loteria();//llama a la funcion para asignar valor
            }
            numero_usuario = numero_loteria();//llama a la funcion para asignar valor

            system("CLS");
            //compara si el numero del usuario y el numero ganador son iguales
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
            iniciar_carrera();
            break;
        }
    } while (opc != 0);
    return 0;
}

int msg()
{
    int opc;//variable de eleccion del menu
    system("CLS");
    printf("MENU\n");
    printf("1.-Juego de la loteria\n");
    printf("2.-Carrera de coches\n");
    printf("0.-Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opc);//opcion elegida por el usuario
    return opc;//variable retornada a int main
}

int numero_loteria()
{
    return rand() % 100 + 1;//numero random entre el 1 y el 100
}

void iniciar_carrera()
{
    register int coche1, coche2, coche3;//variables de registro para carrera
    coche1 = velocidad();//obtiene velocidad random
    coche2 = velocidad();//obtiene velocidad random
    coche3 = velocidad();//obtiene velocidad random
    system("CLS");
    printf("\t TIEMPOS\n");
    printf("----------COCHE 1-----------\n");
    printf(" velocidad: %dk/h\n", coche1);
    printf(" tiempo: %.2fs\n", tiempo(coche1));//tiempo en llegar a la meta
    printf("----------------------------\n");
    printf("----------COCHE 2-----------\n");
    printf(" velocidad: %dk/h\n", coche2);
    printf(" tiempo: %.2fs\n", tiempo(coche2));//tiempo en llegar a la meta
    printf("----------------------------\n");
    printf("----------COCHE 3-----------\n");
    printf(" velocidad: %dk/h\n", coche3);
    printf(" tiempo: %.2fs\n", tiempo(coche3));//tiempo en llegar a la meta
    printf("----------------------------\n");
    system("PAUSE");
    system("CLS");
    //compara el tiempo de los coches para decidir al ganador
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

int velocidad()
{
    return rand() % 101 + 100;//genera numero random simulando velocidad del 100 al 200
}

float tiempo(int vel)
{
    float tiempo, met;//variables del tiempo
    met = (vel * 1000) / 3200;//obtiene los m/s

    tiempo = 1000 / met;//calcula el tiempo total en llegar a la meta
    return tiempo;// retorna el tiempo
}