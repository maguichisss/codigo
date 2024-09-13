#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodo
{
    int num;
    struct nodo *der;
}nod;
main()
{
    nod *pt;
    pt=(nod*)malloc(sizeof(nod));
    printf("Num 1:  ");
    scanf("%d",&pt->num);
    pt->der=(nod*)malloc(sizeof(nod));
    printf("Num 2:  ");
    scanf("%d",&pt->der->num);
    pt->der->der=NULL;
    printf("%d --> %d",pt->num, pt->der->num);
    FILE *arch;
    char nomarch[60];
    fflush(stdin);
    printf("Escribe la ruta y nombre del archivo:  ");
    gets(nomarch);
    arch=fopen(nomarch,"a");
    if(arch==NULL)
    {
        printf("No se pudo abrir el archivo ");
        getch();
        exit(1);
    }
    fprintf(arch,"%d ",pt->num);
    fprintf(arch,"%d \n",pt->der->num);
    fclose(arch);
    arch=fopen(nomarch,"r");
    int uno_x;
    while(!feof(arch))
    {
        fscanf(arch,"%d",&uno_x);
        printf("%d ",uno_x);
        printf("\n");
    }
    getch();
    fclose(arch);
    free(pt->der);
    free(pt);
}
