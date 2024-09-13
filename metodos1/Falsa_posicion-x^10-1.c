#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn;
    printf("La funcion a evaluar es x^10-1");
    printf("\nDame el valor inicial: ");
    scanf("%f",&a);
    printf("\nDame el valor final: ");
    scanf("%f",&b);
    printf("\n i\t  a\t    b\t    f(a)\tf(b)\t  Xn\t    f(Xn)");
    do
    {
        cont ++;
        fa=exp(a)-a*a+3*a-2;
        fb=exp(b)-b*b+3*b-2;
        xn=((a*fb)-(b*fa))/(fb-fa);
        fxn=exp(xn)-xn*xn+3*xn-2;
        printf("\n%2.0f   %.6f  %.6f  %.6f  %.6f",cont,a,b,fa,fb);
        if(fxn>0)
        b=xn;
        else
        a=xn;
        printf("  %.6f   %.6f",xn,fxn);
    }while(cont<15);
    printf("\nFIN");
}
