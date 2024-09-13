#include<stdio.h>
#include<stdlib.h>
main()
{
    int *p;
    float*q;
    char *r;
    p=(int*)malloc(sizeof(int));
    *p=1200;
    q=(float*)malloc(sizeof(float));
    *q=4.8;
    r=(char*)malloc(sizeof(char));
    *r='A';
    printf("El contenido del puntero *p es: %d\n",*p);
    printf("El contenido del puntero *q es: %f\n",*q);
    printf("El contenido del puntero *r es: %c\n",*r);
    free(p);
    free(q);
    free(r);

}
