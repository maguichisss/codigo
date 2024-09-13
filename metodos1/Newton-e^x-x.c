#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, x;
    float fx,fdx,xn;
    printf("La funcion a evaluar es e^x-x");
    printf("\nDame el valor inicial: ");
    scanf("%f",&x);
    printf("\n i\t  x\t    f(x)\t    f'(x)");
    do
    {
        cont ++;
        fx=exp(-x)-x;
        fdx=-exp(-x)-1;
        xn=x-(fx/fdx);
        printf("\n%2.0f   %.9f  %.9f  %.9f  ",cont,x,fx,fdx);
        x=xn;
    }while(cont<15);
    printf("\nFIN");
}
