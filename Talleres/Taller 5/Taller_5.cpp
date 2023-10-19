//  Taller 5 Clases de almacenamiento
//  Antonio Ramos Gonzalez mt 372576
//  9/30/2023
//  Descrpcion: Este codigo explora las diferentes clases de almacenamiento

// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "otroarchivo.h"
//variable global
const float pi = 3.14159;
extern int saldo;
//definimos nuestras funciones
void automatica();
void estatica();
void registro();
void global();

int main()
{
    system("CLS");
    //********************INCISO 1 VARIABLE AUTOMATICA********************
    printf("Variable Automatica\n");
    for (int i = 0; i < 10; i++)//ciclo para repetir funcion automatica
    {
        automatica();
    }
    system("PAUSE");

    system("CLS");

    //********************INCISO 2 VARIABLE EXTERNA********************
    printf("Variables externas\n");
    printf("valor de variable en otroarchivo:  %d\n", saldo);

    saldo -= 150;//se le resta 150 a nuestra variable externa

    printf("valor de variable en este archivo: %d\n", saldo);
    system("PAUSE");

    system("CLS");
    //********************INCISO 3 VARIABLE ESTATICA********************
    printf("Variable estatica\n");
    for (int i = 0; i < 10; i++)//ciclo para repetir funcion estatica
    {
        estatica();
    }
    system("PAUSE");

    system("CLS");
    //********************INCISO 4 VARIABLE DE REGISTRO********************
    printf("Variable de registro\n");
    registro();//llama a la variable de registro
    system("PAUSE");

    system("CLS");
    //********************INCISO 5 VARIABLE GLOBAL********************
    //compara la variable global y local llamandola en diferentes funciones
    printf("Vriable global/n");
    printf("DENTRO DE LA FUNCION\n");
    global();
    printf("FUERA DE LA FUNCION\n");
    printf("%f\n", pi);
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
    register int temp;//definimos la variable como variable de registro
    int valor;
    temp = 40;
    valor = 35;
    printf("Variable de registro: %d\n", temp);
    printf("Variable automatica: %d\n", valor);
}

void global()
{
    const float pi = 3.19;//variable local qeu se comparara con variable global

    printf("%f\n", pi);//imprime variable local
}
