#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn;
    printf("La funcion a evaluar es 3x + sen x - e^x");
    printf("\nDame el valor inicial: ");
    scanf("%f",&a);
    printf("\nDame el valor final: ");
    scanf("%f",&b);
    printf("\na = %f\nb = %f\n",a,b);
    printf("\n i\t   a\t\t b\t f(a)\t\tf(b)\t     Xn");
    do
    {
        cont ++;
        fa=(19200/a)*(1-pow((1+a),-20))-75000;
        fb=(19200/b)*(1-pow((1+b),-20))-75000;
        xn= (a+b)/2;
        fxn=(19200/xn)*(1-pow((1+xn),-20))-75000;
        printf("\n%2.0f     %.6f     %.6f   %.6f    %.6f     %.6f",cont,a,b,fa,fb,xn);
        if((fxn*fa)>0)
            a=xn;
        else
            b=xn;
    }
    while(cont<30);
    printf("\n\nFIN");
}
