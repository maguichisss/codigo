#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
    int n, x;
    long inicio, fin, fact;
    inicio=clock();
    do
    {
        printf("Factorial de (3 < x < 30): ");
        scanf("%d",&x);
    }
    while(x<=3 || x>=30);

    for(n=x, fact=1; x; x--)
        fact*=x;

    fin=clock();
    printf("\nFactorial de %d! = %1d",n,fact);
    printf("\nUnidades de tiempo de proceso: %1f",fin-inicio);
    printf("\nEn segundos: %1f\n\n",(fin-inicio)/(float)CLOCKS_PER_SEC);
}
