#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct let
{
    char letrita;
    struct let *next;
}letras;

typedef struct num
{
    int numerito;
    struct num *next;
}numeros;

typedef struct prim
{
    float pi;
    struct let *arriba;
    struct num *abajo;
}primero;

primero *lista=NULL;
letras *up=NULL;
numeros *down=NULL;
primero *pt;

inserta25()
{
    pt->abajo->next->next->next=(numeros*)malloc(sizeof(numeros));
    pt->abajo->next->next->next->numerito=25;
    printf("\n%d\n",pt->abajo->next->next->next->numerito);
}

insertaA()
{
    pt->arriba->next->next->next=(letras*)malloc(sizeof(letras));
    pt->arriba->next->next->next->letrita='A';
    printf("\n%c\n",pt->arriba->next->next->next->letrita);
}

main()
{

    pt=(primero*)malloc(sizeof(primero));
    pt->pi=3.14;

    pt->arriba=(letras*)malloc(sizeof(letras));
    pt->abajo=(numeros*)malloc(sizeof(numeros));
    pt->arriba->letrita='C';
    pt->abajo->numerito=10;

    pt->arriba->next=(letras*)malloc(sizeof(letras));
    pt->abajo->next=(numeros*)malloc(sizeof(numeros));
    pt->arriba->next->letrita='E';
    pt->abajo->next->numerito=20;

    pt->arriba->next->next=(letras*)malloc(sizeof(letras));
    pt->abajo->next->next=(numeros*)malloc(sizeof(numeros));
    pt->arriba->next->next->letrita='F';
    pt->abajo->next->next->numerito=30;

    printf("\n%f\n%c\n%d\n",pt->pi,pt->arriba->letrita,pt->abajo->numerito);
    printf("\n%c\n%d\n",pt->arriba->next->letrita,pt->abajo->next->numerito);
    printf("\n%c\n%d\n",pt->arriba->next->next->letrita,pt->abajo->next->next->numerito);

    system("pause");
    inserta25();
    system("pause");
    insertaA();

    free(pt->abajo->next->next->next);
    free(pt->arriba->next->next->next);
    free(pt->abajo->next->next);
    free(pt->arriba->next->next);
    free(pt->abajo->next);
    free(pt->arriba->next);
    free(pt->arriba);
    free(pt->abajo);
    free(pt);
    system("pause");

}
