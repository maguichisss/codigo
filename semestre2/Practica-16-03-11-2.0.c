#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
typedef struct nodo
{
    char cad;
    struct nodo *p;
}jk;
main()
{
    jk *st;
    st=(jk*)malloc(sizeof(jk));
    st->p=(jk*)malloc(sizeof(jk));
    st->p->p=(jk*)malloc(sizeof(jk));
    printf("Escribe una letra: ");
    scanf("%s",&st->cad);
    printf("Escribe otra letra: ");
    scanf("%s",&st->p->cad);
    printf("Escribe una 3a letra: ");
    scanf("%s",&st->p->p->cad);
    st->p->p->p=NULL;
    printf("%c --> %c --> %c",st->cad,st->p->cad,st->p->p->cad);
/*
    char ruta[60];
    FILE *archivo;
    fflush(stdin);
    printf("\nEscribe la ruta y nombre del archivo:  ");
    gets(ruta);
    archivo=fopen(ruta,"a");
    if(archivo==NULL)
    {
        printf("No se pudo abrir el archivo ");
        getch();
        exit(1);
    }
    fprintf(archivo,"%c ",st->cad);
    fprintf(archivo,"%c ",st->p->cad);
    fprintf(archivo,"%c\n",st->p->p->cad);
    fclose(archivo);
    archivo=fopen(ruta,"r");
    char caract;
    while(!feof(archivo))
    {
        fscanf(archivo,"%c",&caract);
        printf("%c ",caract);
    }
    //getch();
    fclose(archivo);  */
    free(st->p->p);
    free(st->p);
    free(st);
}
