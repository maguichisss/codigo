#include<stdio.h>
#include<stdlib.h>
main()
{
    char nom[]="Soy el mejor";
    int i, num, cont=0;
    printf("Cuantas veces quieres repetir: ");
    scanf("%d",&num);
    for(i=0; i<num; i++)
    {
        cont++;
        printf("\n%2d  %s",cont,nom);
    }
}

