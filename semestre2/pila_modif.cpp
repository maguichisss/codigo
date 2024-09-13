#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

typedef struct nodito
{
        char nom[30];
        struct nodito *pt;
}nod;

nod *tope=NULL;
char nom[30];

void inserta()
{
     printf("Dar dato a insertar: ");
     gets(nom);
     nod *nvo;

     nvo=new nod;
     strcpy(nvo->nom,nom);
     
     if(tope==NULL)
        nvo->pt=NULL;
     else
        nvo->pt=tope;
     tope=nvo;
}

void elimina()
{
     nod *aux = tope;
     if (tope==NULL)
     {
               printf("\nLista vacia. Pulse tecla para continuar \n");
               getch();
               return;
     }

     printf("\n %s",aux->nom);
     tope=aux->pt;

     delete(aux);
     return;
}

void imprimenodo()
{
     nod *aux=tope;
     if(tope==NULL)
     {
                printf("Lista vacia. No hay nada que imprimir.\n");
                printf("\nPulse tecla para teminar.\n");
                getch();
     }
     else
     {
                printf("\nTope de la lista ");
                while(aux!=NULL)
                {
                       printf("-> %s",aux->nom);
                       aux=aux->pt;
                }
     }
}


void eliminalista()
{
     nod *nvo;
     nod *aux=tope;
     while(tope != NULL)
     {
         elimina();
     }
     free(aux);
     free(nvo);
}

void buscarnodo()
{
     char nombre[30];
     printf("A quien deseas buscar: ");
     gets(nombre);

     nod *aux=tope;
     if(tope==NULL)
     {
                printf("No hay elementos en la lista\n");
                printf("Pulse tecla para teminar.\n");
                getch();
     }
     else
     {

                while(aux!=NULL)
                {
                       if(strcmp(nombre,aux->nom)==0)
                       {
                           printf("\n\nSi esta ese usuario %s",aux->nom);
                           getch();
                           return;
                       }
                       aux=aux->pt;
                }
                aux=tope;
                while(aux!=NULL)
                {
                       if(strcmp(nombre,aux->nom)!=0)
                       {
                           printf("\n\nEse usuario no existe ");
                           getch();
                           return;
                       }
                       aux=aux->pt;
                }
     }
}

main()
{
     int opc;

    system("cls");
    printf("3. Programar en lenguaje C la estructura dinámica lista ligada ordenada.\n\n");
    printf("\n     Los nodos de dicha lista deben estar conformados de Nombres de Personas.");
    printf("\n     Crear funciones insertar nodo, borrar nodo,");
    printf("\n     listar contenido de lista, buscar nodo, eliminar lista.");

    printf("\n\n\nCreado por:\n");
    printf("\nCastro Villanueva Ruben Getsemani");
    printf("\nEnciso Vega Jessica Nohemi");
    printf("\nGarces Brito Mauricio Ilhuicamina");
    printf("\nRojas Gomez Ana Cecilia");
    printf("\n\n\nPresione una tecla para continuar ");
    getch();


     do
     {
                 regresa:
                 system("cls");
                 printf("\n1. Insertar Nombre de Persona");
                 printf("\n2. Borrar nodo");
                 printf("\n3. Mostrar contenido de lista");
                 printf("\n4. Buscar nodo");
                 printf("\n5. Elimina lista");
                 printf("\n6. Salir\n");
                 printf("\n Eija opcion\n\t");
                 scanf("%d",&opc);
                 fflush(stdin);
                 system("cls");

                 switch(opc)
                 {
                          case 1:
                                  inserta();
                                  break;


                          case 2:
                                 printf("\nSe elimino:");
                                 elimina();
                                 getch();
                                 break;

                          case 3:
                                 printf("Los elementos de la lista son:\n");
                                 imprimenodo();
                                 getch();
                                 break;

                          case 4:
                                 buscarnodo();
                                 break;

                          case 5:
                                 printf("\n Elementos eliminados: ");
                                 eliminalista();
                                 printf("\n SE ELIMINO LA LISTA DE NODOS");
                                 getch();
                                 break;

                          case 6:
                                 printf("\n\nPONGANOS 10!!! :D\n\a\a\a");
                                 getch();
                                 exit(1);
                                 break;

                          default:
                                 printf("\nOpción incorrecta, vuelva a elegir, pulse tecla para continuar");
                                 goto regresa;
                                 getch();
                 }

     }while(opc!=6);
}

