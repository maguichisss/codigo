#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct ejercicio
{
        struct ejercicio *izq;
        struct ejercicio *der;
        int num;
        
}eje;
int main()
{
    int suma;
    eje *st;
    
    st=new eje;
     
    st->izq=NULL;
    st->der=new eje;
    printf("Dame un entero\n");
    scanf("%d",&st->num);
             
    st->der->izq=NULL;
    st->der->der=new eje;
    printf("Dame un entero\n");
    scanf("%d",&st->der->num);
    
    st->der->der->izq=NULL;
    st->der->der->der=new eje;
    printf("Dame un entero\n");
    scanf("%d",&st->der->der->num);
    
    st->der->der->der->der=NULL;
    st->der->der->der->izq=new eje;
    printf("Dame un entero\n");
    scanf("%d",&st->der->der->der->num);
    
    st->der->der->der->izq->der=NULL;
    st->der->der->der->izq->izq=new eje;
    printf("Dame un entero\n");
    scanf("%d",&st->der->der->der->izq->num);
    
    st->der->der->der->izq->izq->der=NULL;
    st->der->der->der->izq->izq->izq=st;
    printf("Dame un entero\n");
    scanf("%d",&st->der->der->der->izq->izq->num);
    
    suma=st->num+st->der->num+st->der->der->num+st->der->der->der->num+st->der->der->der->izq->num+st->der->der->der->izq->izq->num;
             
    printf("\n\n%d + %d + %d + %d + %d + %d = %d",st->num,st->der->num,st->der->der->num,st->der->der->der->num,st->der->der->der->izq->num,st->der->der->der->izq->izq->num,suma);
    getch();
    
    
    delete(st-> der->der->der->izq->izq);
    delete(st-> der->der->der->izq);
    delete(st-> der->der->der);
    delete(st-> der->der);
    delete(st->der);
    delete(st);
    
    system("cls");
}
