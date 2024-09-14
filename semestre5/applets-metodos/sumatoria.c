#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if(n<2)
      return 1;
    else
      return n * factorial(n-1);
}

main()
{
    double a,b,c,d,x=0;
    int n,i;
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        a=factorial(i);
        a=1/a;
        b=2*i+1;
        b=pow(5,b)/b;
        c=a*b;
        printf("%f      %f      %f      =",a,b,c);
        x += c;
        printf("%f\n",x);
    }
    printf("\n\n%d",x);
}
