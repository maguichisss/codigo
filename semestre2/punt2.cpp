#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct nod
{
    struct nod *izq;
    char car;
    struct nod *der;
}nd;

main()
{
    nd *q;
    q=new nd;
    
    q->car='A';
    q->der=new nd;
    q->izq=new nd;
    
    
    q->der->der=NULL;
    q->der->izq=new nd;
    q->der->izq->der=NULL;
    q->der->car='B';
    q->der->izq->car='D';
    q->der->izq->izq=NULL;
    
    q->izq->izq=new nd;
    q->izq->izq->izq=NULL;
    q->izq->izq->der=NULL;
    q->izq->izq->car='X';
    
    q->izq->der=q->der->izq;
    q->izq->car='Q';
    q->izq->der->der=NULL;
    q->izq->der->car='D';
    q->izq->der->izq=NULL;
    
    printf(" q -> izq %c der ->  izq %c der", q->car, q->der->car);
    printf("\n       |             |         ");
    printf("\n      izq %c der ->  izq %c der", q->izq->car, q->der->izq->car);
    printf("\n       |                      ");
    printf("\n      izq %c der", q->izq->izq->car);
    
    delete(q->izq->izq);
    delete(q->izq->der);
    delete(q->izq);
    delete(q->der);
    delete(q);
    printf("\n FIN");
    getch();
}
    
    
     
    
    
     
