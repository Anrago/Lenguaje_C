#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    char especie[30];
    int edad;
    char sexo[10];
    int status = 1;
    int mat;
} TMascota;

int Registar(TMascota reg[], int n);
void Buscar(TMascota reg[], int n);
void imprimir(TMascota reg[], int n);
int Cargar(TMascota reg[], int n);
void Guardar(TMascota reg[], int n);


int main()
{
    int i = 0;
    int opc;
    TMascota reg[100];
    do
    {
        system("CLS");
        printf("menu\n");
        printf("1.-Agregar mascota\n");
        printf("2.-buscar mascota\n");
        printf("3-imprimir\n");
        printf("4.-Cargar archivo\n");
        printf("5.-Guardar archivo\n");
        printf("6.-Salir\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Agregar mascota\n");
            i = Registar(reg, i);
            break;
        case 2:
            printf("buscar mascota\n");
            Buscar(reg, i);
            system("pause");
            break;
        case 3:
            printf("imprimir\n");
            imprimir(reg, i);
            system("pause");
            break;
        case 4:
            printf("Cargar archivo\n");
            i=Cargar(reg, i);
            break;
        case 5:
            printf("Guardar archivo\n");
            Guardar(reg, i);
            break;
        }
    } while (opc != 6);
}

int Registar(TMascota reg[], int n)
{

    printf("Nombre: ");
    scanf("%s", reg[n].nombre);
    printf("Especie: ");
    scanf("%s", reg[n].especie);
    printf("Edad: ");
    scanf("%d", &reg[n].edad);
    printf("Sexo: ");
    scanf("%s", reg[n].sexo);

    reg[n].mat = n;

    return n + 1;
}

void Buscar(TMascota reg[], int n)
{
    int i;
    printf("Matricula: ");
    scanf("%d", &i);

    if (i<=n&&i>=0)
    {
        printf("Matricula: %d\n", reg[i].mat);
        printf("Nombre: %s\n", reg[i].nombre);
        printf("Especie: %s\n", reg[i].especie);
        printf("Edad: %d\n", reg[i].edad);
        printf("Sexo: %s\n", reg[i].sexo);
        
    }
}

void imprimir(TMascota reg[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %s %d %s\n", reg[i].nombre, reg[i].especie, reg[i].edad, reg[i].sexo);
    }
}


int Cargar(TMascota reg[], int n)
{
    FILE *fa;
    fa = fopen("mascotas.txt", "r");
    if (fa == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    else
    {
        while (!feof(fa))
        {
            fscanf(fa, "%s %s %d %s", reg[n].nombre, reg[n].especie, &reg[n].edad, reg[n].sexo);
            reg[n].mat = n;
            n++;
        }
    }
    fclose(fa);
    return n;
}

void Guardar(TMascota reg[], int n)
{
    FILE *fa;
    fa = fopen("mascotas.txt", "a");
    if (fa == NULL)
    {
        printf("Error al abrir el archivo\n");
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fa, "%s %s %d %s\n", reg[i].nombre, reg[i].especie, reg[i].edad, reg[i].sexo);
        }
    }
    fclose(fa);
}