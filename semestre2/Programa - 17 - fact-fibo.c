#include<stdio.h>
#include<stdlib.h>
main()
{
    int fact, n, i, fibo,x,y;
    printf("Dame un numero\n");
    scanf("%d",&n);
    fact = 1;
    fibo = 1;
    x = 1;
    y = 0;
    for(i=2; i<=n; i++)
    {
        fact *= i;
    }
    printf("El factorial es: %d\n",fact);
    for(i=3; i<=n; i++)
    {
        fibo=x+y;
        y=x;
        x=fibo;
    }
    if(n==1)
        fibo=0;
    printf("El fibonacci es: %d\n",fibo);
}
