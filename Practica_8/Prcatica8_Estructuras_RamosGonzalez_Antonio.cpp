#include "Babilonia.h"
#define N 100
//Estructura de producto
typedef struct _producto
{
    char nombre[50];
    int cantidad;
    float precio;
} Tproducto;

int msg();
void menu();
int agregar(Tproducto producto[], int n);
void retirar(Tproducto producto[], int n);
void mostrar(Tproducto producto[], int n);
void cargar(Tproducto producto[], int n);

int main()
{
    fflush(stdin);
    menu();
    return 0;
}
//funcion qe muestra el mensaje de menu y lee la eleccion del usuario
int msg()
{
    system("cls");
    printf("Menu\n");
    printf("1.-Agregar inventario\n");
    printf("2.-Retirar de inventario\n");
    printf("3.-Mostrar inventario\n");
    printf("4.-Cargar inventario\n");
    printf("0.-Salir\n");
    return valid("Opcion: ", 0, 4);
}
//funcion de control de menu
void menu()
{
    int opc, i = 0;
    Tproducto producto[100];

    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            if (i <= 100)
            {
                printf("Agregar\n");
                i = agregar(producto, i);
            }
            else
            {
                printf("No hay espacio en inventario\n");
            }

            break;
        case 2:
            if (i > 0)
            {
                printf("Retirar\n");
                retirar(producto, i);
            }
            else
            {
                printf("No hay productos en inventario\n");
            }
            break;
        case 3:
            printf("Mostrar\n");
            mostrar(producto, i);
            break;
        case 4:
            printf("Cargar\n");
            cargar(producto, i);
            break;
        }
    } while (opc != 0);
}
//funcion que agrega productos al inventario
int agregar(Tproducto producto[], int n)
{
    int opc;
    do
    {
        if (n < N)
        {
            system("cls");
            validCad("Nombre producto: ", producto[n].nombre);
            producto[n].cantidad = valid("Cantidad: ", 0, 100);
            producto[n].precio = valid("Precio: ", 0, 1000);
            
            
            n++;
            opc = valid("Desea agregar otro producto? (1.-si/0.-no)", 0, 1);
        }
    } while (opc);
    return n;
}
//funcion que retira productos del inventario
void retirar(Tproducto producto[], int n)
{
    int i, opc, cant;
    char nombre[50];
    do
    {
        system("cls");
        validCad("Nombre producto: ", nombre);
        for (i = 0; i < n; i++)
        {
            if (strcmp(nombre, producto[i].nombre) == 0)
            {
                cant = valid("Cantidad: ", 0, 100);
                if (cant <= producto[i].cantidad)
                {
                    producto[i].cantidad -= cant;
                }
                else
                {
                    printf("No hay suficiente producto\n");
                }
            }
            else
            {
                printf("No se encontro el producto\n");
            }
        }
        opc = valid("Desea retirar otro producto? (1.-si/0.-no)", 0, 1);
    } while (opc);
}
//funcion que muestra el inventario
void mostrar(Tproducto producto[], int n)
{
    system("cls");
    int i;
    printf("nombre cantidad precio\n");
    for (i = 0; i < n; i++)
    {
        printf("%s %d %.2f\n", producto[i].nombre, producto[i].cantidad, producto[i].precio);
    }
    system("pause");
}
//Funcion que carga el inventario en un archivo
void cargar(Tproducto producto[], int n)
{
    FILE *arch;
    int i;
    arch = fopen("inventario.txt", "w");
    if (arch == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            fprintf(arch, "%s %d %.2f\n", producto[i].nombre, producto[i].cantidad, producto[i].precio);
        }
        fclose(arch);
    }
}