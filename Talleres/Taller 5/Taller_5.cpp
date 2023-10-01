//  Practica_5_ClasesdeAlmacenamiento_RamosGonzalez_Antonio
//  Antonio Ramos Gonzalez mt 372576
//  9/30/2023
//  Descrpcion: Este codigo simula un juego de loteria y un carrera coches

// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "otroarchivo.h"
const float pi = 3.14159;

void automatica();
void estatica();
void registro();
void global();

int main()
{
    system("CLS");
    //********************INCISO 1 VARIABLE AUTOMATICA********************
    printf("Variable Automatica\n");
    for (int i = 0; i < 10; i++)
    {
        automatica();
    }
    system("PAUSE");

    system("CLS");

    //********************INCISO 2 VARIABLE EXTERNA********************
    printf("Variables externas\n");
    extern int saldo;
    printf("valor de variable en otroarchivo:  %d\n", saldo);
    saldo -= 150;
    printf("valor de variable en este archivo: %d\n", saldo);
    system("PAUSE");

    system("CLS");
    //********************INCISO 3 VARIABLE ESTATICA********************
    printf("Variable estatica\n");
    for (int i = 0; i < 10; i++)
    {
        estatica();
    }
    system("PAUSE");

    system("CLS");
    //********************INCISO 4 VARIABLE DE REGISTRO********************
    printf("Variable de registro/n");
    registro();
    system("PAUSE");

    system("CLS");
    //********************INCISO 5 VARIABLE GLOBAL********************
    printf("Vriable global/n");
    printf("DENTRO DE LA FUNCION\n");
    global();
    printf("FUERA DE LA FUNCION\n");
    printf("%f", pi);
    system("PAUSE");
}

void automatica()
{
    int contador = 0;
    contador++;
    printf("%d\n", contador);
}

void estatica()
{
    static int contador = 0;

    contador++;
    printf("%d\n", contador);
}

void registro()
{
    register int temp;
    int valor;
    temp = 40;
    valor = 35;
    printf("Variable de registro: %d\n", temp);
    printf("Variable automatica: %d\n", valor);
}

void global()
{
    const float pi = 3.19;

    printf("%f\n", pi);
}
