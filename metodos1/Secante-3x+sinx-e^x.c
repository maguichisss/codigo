
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn;
    printf("La funcion a evaluar es ???");
    printf("\nDame el valor inicial: ");
    scanf("%f",&b);
    printf("\nDame el valor final: ");
    scanf("%f",&a);
    printf("\na = %f\nb = %f\n",a,b);
    printf("\n i\t   a\t\t b\t f(a)\t\tf(b)\t     Xn");
    do
    {
        cont ++;
        fa=a*a-3;
        fb=b*b-3;
        xn= a-(  (fa*(a-b))  / (fa-fb)  );
        printf("\n%2.0f     %.6f     %.6f   %.6f    %.6f     %.6f",cont,a,b,fa,fb,xn);
        b=a;
        a=xn;
    }while(cont<10);
    printf("\n\nFIN");
}
