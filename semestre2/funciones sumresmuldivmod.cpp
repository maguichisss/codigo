#include<stdio.h>
#include<conio.h>
int suma(int a, int b)
    {return a+b;
    }
int resta(int a, int b)
    {return a-b;
    }
int multi(int a, int b)
    {return a*b;
    }
float divi(int a,  int b)
      {if(b !=0)
       return (float)a/(float)b;
      }
int modulo(int a, int b)
    {return a%b;
    }
main()
      {int x,y;
       printf("Dame 2 numeros\n");
       scanf("%d", &x);
       scanf("%d", &y);
       printf("La suma de %d + %d es: %d \n",x,y,suma(x,y));
       printf("La resta de %d - %d es: %d \n",x,y,resta(x,y));
       printf("La multiplicacion de %d  %d es: %d \n",x,y,multi(x,y));
       if(y!=0)  printf("La division de %d / %d es: %.2f\n",x,y,divi(x,y));
       else      printf("Error\n");
       printf("El modulo de %d y %d es: %d \n",x,y,modulo(x,y));
       getch();
       }
