#include<stdio.h>
#include<stdlib.h>
main()
{
    char nom[40];
    int i, num, cont=0;
    printf("Escribe tu nombre: ");
    gets(nom);
    fflush(stdin);
    printf("Cuantas veces quieres repetirlo: ");
    scanf("%d",&num);
    for(i=0; i<num; i++)
    {
        cont++;
        printf("\n%2d  %s",cont,nom);
    }
}

