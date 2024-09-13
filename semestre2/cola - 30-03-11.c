#include<stdio.h>
#include<stdlib.h>

typedef struct colisima
{
    int num;
    struct colisima *pt;
}nd;

nd *ini=NULL;

insertar(int ndato)
{
    nd *nvo;
    nd *aux=ini;
    nvo=(nd*)malloc(sizeof(nd));
    nvo->num=ndato;
    nvo->pt=NULL;
    if(ini==NULL)
    {
        ini=nvo;
    }
    else
    {
        while(aux->pt !=NULL)
        {
            aux=aux->pt;
        }
        aux->pt=nvo;
    }
}

eliminar()
{
    nd *aux=ini;
    if(ini==NULL)
    {
        printf("\nFila vacia. Pulse tecla para continuar ");
        return;
    }
    else
    {
        ini=aux->pt;
        free(aux);
    }
}

lista()
{
    nd *aux=ini;
    if(ini==NULL)
    {
        printf("\nFila vacia. Pulse tecla para continuar \n\n");
        getch();
        return;
    }
    while(aux!=NULL)
    {
        printf("%d  <--  ",aux->num);
        aux=aux->pt;
    }
    printf("\n");
}

main()
{
    printf("\t\tPROGRAMA QUE SIMULA UNA FILA\n");
    insertar(111);
    insertar(222);
    insertar(333);
    insertar(444);
    lista(); //100 <-- 200 <-- 300 <-- 400 <--
    eliminar();
    lista(); //200 <-- 300 <-- 400 <--
    eliminar();
    lista(); //300 <-- 400 <--
    eliminar();
    lista(); //400 <--
    eliminar();
    lista(); //fila vacia
/*
A) CREAR UNA FUNCION QUE ELIMINE TODA LA FILA

B) CREAR UN MENU

C) HACER UNA FUNCION QUE INDIQUE EL PRIMERO DE LA FILA

D) OTRA FUNCION QUE INDIQUE EL ULTMO DE LA FILA

E) FUNCION QUE BUSQUE UN ELEMENTO DE LA FILA

F) GUARDAR LA FILA EN UN ARCHIVO

G) LEER LA FILA DEL ARCHIVO
*/
}
