#include<stdio.h>
#include<stdlib.h>
main()
{
    int i;
    srand((unsigned)time(NULL));
    for(i=1; i<=20; i++)
    {
        printf("Numero aleatorio: %d\n", rand()%100);
    }
}
