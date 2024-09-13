#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodo
{
    struct nodo *izq;
    int num;
    struct nodo *der;
}sn;
main()
{
    sn *s;
    s= new sn;
    
    s->num=80;
    s->der= new sn;
    s->der->num=90;
    s->der->der=NULL;
    s->der->izq=NULL;
    s->izq= new sn;
    
    s->izq->num=70;
    s->izq->izq=NULL;
    s->izq->der=new sn;
    
    s->izq->der->num=60;
    s->izq->der->der=NULL;
    s->izq->der->izq=NULL;
    printf("\n s -> izq %d der -> izq %d der",s->num,s->der->num);
    printf("\n       |\n       |");
    printf("\n      izq %d der -> izq %d der",s->izq->num,s->izq->der->num);
    delete(s->izq->der);
    delete(s->izq);
    delete(s->der);
    delete(s);
    printf("\n\nFIN");
    getch();
    
}
