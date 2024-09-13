#include<stdio.h>
#include<stdlib.h>
main()
{
    int *pum;
    pum=(int*)malloc(sizeof(int));
    *pum=100;
    printf("\nEL contenido es: %i",*pum);
    free(pum);
}
