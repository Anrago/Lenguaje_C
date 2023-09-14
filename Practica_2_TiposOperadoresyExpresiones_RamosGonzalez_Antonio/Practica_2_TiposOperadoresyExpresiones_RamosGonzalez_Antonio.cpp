// Antonio Ramos Gonzalez mt 372576
// practica 2
// 8/23/2023  // 9/4/2023
// Practica 2: Tipos de operadores
#include<stdio.h>


int main(){
    char x;                    //decicion del switch
    int cal;                   //Caso 2
    int opc=0,i,e=0,inven[15]; //caso 3
    printf("elige que desea hacer\na)decimal a binario\nb)Calificacion numerica\nc)gestion de inventaro\n");
    scanf(" %c",&x);
    switch (x)
    {
    case 'a':
        {
        int numero_decimal;
        printf("Ingrese un numero en decimal\n");
        scanf("%d",&numero_decimal);

        // validar que el numero sea positivo

        if(numero_decimal<0)
        {
            return 1;
        }

        // Calcular los bits necesarios

        int num_bits=0;
        int temp=numero_decimal;

        while(temp>0)
        {
            temp/=2;
            num_bits++;
        }

        //Creamos el arreglo

        int bits[num_bits];
        int indice;

        while(numero_decimal>0)
        {
            bits[indice]=numero_decimal%2;
            numero_decimal/=2;
            indice++;

        }
        printf("numero en bits\n");
        for(int i=indice-1;i>=0;i--)
        {
            printf("%d",bits[i]);
        }
        printf("\n");

        printf("numero en bits negado\n");
        for(int i=indice-1;i>=0;i--)
        {
            if (bits[i]==1)
            {
                bits[i]-=1;
            }
            else
            {
                bits[i]+=1;
            }

            
            printf("%d",bits[i]);
        }
        printf("\n");

        //Buscar la cantidad de bits encendidos

        int bits_encendidos=-1;
        printf("Los bits encendidos estan en la posicion:\n");
        for(int i=0;i<indice;i++)
        {
            if(bits[i]==1)
            {
                bits_encendidos=i;
                printf("%d,",bits_encendidos+1);
            }
        }
        if(bits_encendidos==-1)
        {
            printf("No se encontro ningun bit encendido ");
        }

        }
    
        
    break;
    
    case 'b':
        
        printf("dame la calificacion(entre 0 y 100)\n");
        scanf("%d",&cal);
        if(cal>59)
        {
            if(cal>69)
            {
                if(cal>79)
                {
                    if(cal>89)
                    {
                        if(cal>100)
                        {
                            printf("error");

                        }
                        else
                        {
                            printf("su calificacion es: %d \npor lo tanto obtuvo una A",cal);
                        }

                    }
                    else
                    {
                        printf("su calificacion es: %d \npor lo tanto obtuvo una B",cal);
                    }

                }
                else
                {
                    printf("su calificacion es: %d \npor lo tanto obtuvo una C",cal);
                }

            }
            else
            {
                printf("su calificacion es: %d \npor lo tanto obtuvo una D",cal);
            }

        }
        else
        {
            printf("su calificacion es: %d \npor lo tanto obtuvo una F",cal);
        }
    break;

    case 'c':
        printf("INVENTARIO\n");
        for (i = 0; i < 15; i++){
                inven[i]=0;
                printf("%d\n",inven[i]);
            }
        
        while (opc!=4)
        {
            printf("MENU\n1)Agregar\n2)Quitar\n3)Mostrar inventario\n4)salir\n");
            scanf("%d",&opc);
            if(opc==1)
            {
                inven[e]=1;//INTENTAR HACERLO CON CHAR
                e++;
                if(inven[14]==1)
                {
                    printf("EL INVENTARIO ESTA LLENO!!\n"); 
                }
            }else if(opc==2)
            {
                inven[e]=0;//INTENTAR HACERLO CON CHAR
                e--;
                if(inven[0]==0)
                {
                    printf("EL INVENTARIO ESTA VACIO!!\n");
                }

            }else if(opc==3)
            {

                for (i = 0; i < 15; i++)
                {
                    printf("%d\n",inven[i]);
                }

            }
        }
    break;
    
    default:
        printf("error");
        break;
    }
}