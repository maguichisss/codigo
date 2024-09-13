#include<stdio.h>
#include<stdlib.h>
main()
{
    int a=80,*p;
    float b=42,*q;
    p=&a;
    q=&b;
    printf("La suma de %d y %.0f es: %.0f",*p,*q,*p+*q);
}
