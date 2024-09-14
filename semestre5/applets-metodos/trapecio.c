#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double h,a,b;
double f(double x)
{
    return (x*(sin(x)));
}
trapecio()
{
    printf("\t\t    Metodo del Trapecio\n\n\n");
    int i=0;
    double sum=0,x;
    printf("i\txi\t\tf(xi)\t\tCi\tf(xi)*Ci\n");
    printf("%d\t%f\t%f\t1\t%f\t\n",i,a,f(a),f(a)*1);
    sum+=(f(a)+f(b))/2;
    for(x=a+h; x<b; x+=h,i++)
    {
       sum+=f(x);
       printf("%d\t%f\t%f\t2\t%f\t\n",i+1,x,f(x),f(x)*2);
    }
    printf("%d\t%f\t%f\t1\t%f\t\n",i+1,b,f(b),f(b)*1);
    printf("\t\t\t\t\t Suma = %.8f\n",sum);
    sum*=h;
    printf("\t\t\t\t    Resultado = %.8f\n",sum);
}
validar()
{

}

datos()
{
    printf("Dame a: ");
    scanf("%lf",&a);
    printf("Dame b: ");
    scanf("%lf",&b);
    printf("Dame h: ");
    scanf("%lf",&h);

}

main()
{
    datos();
    trapecio();
}
