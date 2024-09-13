#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct lista
{
    char clave[10];
    char nombre[30];
    float calif;
}ls;
main()
{
    ls *p;
    p=(ls*)malloc(sizeof(ls));
/*    printf("Clave:  ");
    scanf("%s",&p->clave);
    printf("\nNombre:  ");
    scanf("%s",&p->nombre);
    printf("\nCalificacion:  ");
    scanf("%f",&p->calif);  */
    p->clave="132";
    p->nombre="Ana";
    p->calif=8.4;
    printf("\n\n%s\t%s\t%f",p->clave,p->nombre,p->calif);
    free(p);
}
