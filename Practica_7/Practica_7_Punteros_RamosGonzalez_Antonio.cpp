#include "Babilonia.h"


int msg();
void menu();


int main()
{
    fflush(stdin);
    void menu();
    return 0;
}

int msg()
{
    printf("MENU\n");
    printf("1.-Argumentos en la linea de comandos\n");
    printf("\n");
    return valid("ELIJE UNA OPCION: ",0,3);
}

void menu()
{
    int opc;

    do
    {
        opc=msg();
        switch (opc)
        {
        case 1:

            break;

        
        }



    } while (opc!=0);
    
}