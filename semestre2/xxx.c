#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn, x0;
    float fun[10];
    int i,n;
    printf("Cual es el grado de la funcion: ");
    scanf("%d",&n);
    for(i=n; i>0; i--)
    {
        printf("Dame x%d: ",i);
        scanf("%f",&fun[i-1]);
    }
    printf("Dame x0: ");
    scanf("%f",&x0);
    printf("\nDame el valor inicial: ");
    scanf("%f",&a);
    printf("\nDame el valor final: ");
    scanf("%f",&b);
    printf("\n i\t  a\t    b\t    f(a)\tf(b)\t  Xn\t    f(Xn)");
    do
    {
        fa=0, fb=0;
        cont ++;
        for(i=0; i<n; i++)
            fa+=pow(a,10)-1;
        for(i=0; i<n; i++)
            fb+=pow(b,10)-1;
        xn=((a*fb)-(b*fa))/(fb-fa);
        fxn=pow(xn,10)-1;
        printf("\n%2.0f   %.6f  %.6f  %.6f  %.6f",cont,a,b,fa,fb);
        if(fxn>0)
        {
            b=xn;
        }
        else
        {
            a=xn;
        }
        printf("  %.6f   %.6f",xn,fxn);
    }while(cont<15);
    printf("\nFIN");
}
