#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, x;
    float fx,fdx,xn;
    printf("La funcion a evaluar es x^10-1");
    printf("\nDame el valor inicial: ");
    scanf("%f",&x);
    printf("\n i\t  x\t    f(x)\t    f'(x)");
    do
    {
        cont ++;
        fx=pow(x,3)-x-1;
        fdx=3*pow(x,2)-1;
        xn=x-(fx/fdx);
        printf("\n%2.0f   %.6f  %.6f  %.6f  ",cont,x,fx,fdx);
        x=xn;
    }while(cont<15);
    printf("\nFIN");
}
