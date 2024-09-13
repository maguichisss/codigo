//programa que reconoce enteros positivos, negativos y el cero
#include<stdio.h>
#include<conio.h>
main()
{
 int a;
 printf("El numero es: ");
 scanf("%d",&a);
   if(a>=0)
   {   if(a==0)
       {printf("El numero es %d jaja, te ganeee!!!",a);}
       else
       {printf("El numero %d es positivo",a);}
   }
   else
   {printf("El numero %d es negativo",a);}
 getche();
 return(0);
}
