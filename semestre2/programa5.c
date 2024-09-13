#include<stdio.h>
#include<stdlib.h>
main()
{
    int x,y;
    float z;
    int *p,*q;
    float *r;
    printf("\nNumero 1:  ");
    scanf("%d",&x);
    printf("\nNumero 2:  ");
    scanf("%d",&y);
    p=&x;
    q=&y;
    r=&z;
    *r=(float)(*p)/(float)(*q);
    printf("El cociente es: %.3f",*r);
}
