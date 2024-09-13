#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*declaracion de la cola*/
typedef struct nodo
{
    int elemento;
    struct nodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *frente;
    Nodo *final;
}Cola;

/*declaracion de las funciones*/

void CrearCola(Cola *cola);
void insert (Cola *cola, int x);
int remover(Cola *cola);
int empty(Cola cola);

main()
{
    int x, opc=0, j=0;
    Cola cola;
    CrearCola(&cola);
    system("cls");
    while(opc!=3)
    {
        printf("\t\t\tMENU PRINCIPAL\n\n\n");
        printf("\t 1. Insertar\n");
        printf("\t 2. Eliminar\n");
        printf("\t 3. Salir\n");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1: printf("Ingrese el numero a introducir:\n");
                scanf("%d", &x);
                insert(&cola, x);
                ++j;
            break;

            case 2: printf("%d fue eliminado de la cola\n", remover(&cola));
                --j;
                getch();
            break;
        }
        system("cls");
    }
    getch();
    return 0;
}

/*definicion de las funciones*/
void CrearCola(Cola *cola)
{
    cola->frente=cola->final=NULL;
}

/*funcion que inserta el dato en la parte final de la cola*/
void insert (Cola *cola, int x)
{
    Nodo *nuevo;
    nuevo=(Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento=x;
    nuevo->siguiente=NULL;
    if(empty(*cola))
        cola->frente=nuevo;
    else
        cola->final->siguiente=nuevo;
    cola->final=nuevo;
}

/*elimina el elemento que esta aL frente de la cola*/
int remover (Cola *cola)
{
    int temp=NULL;
    if(!empty(*cola))
    {
        Nodo *nuevo;
        nuevo=cola->frente;
        temp=cola->frente->elemento;
        cola->frente=cola->frente->siguiente;
        free(nuevo);
    }
    else
    printf("ERROR, cola vacia, no se puede eliminar\a\n");
    return (temp);
}

int empty(Cola cola)
{
    return (cola.frente==NULL);
}
