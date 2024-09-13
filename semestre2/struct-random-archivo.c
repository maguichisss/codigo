#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define n 3
typedef struct renglon
{
    int a;
    int b;
    int c;
}ren;
main()
{
    int i;
    ren col[n];
    srand((unsigned)time(NULL));
    for(i=0; i<n; i++)
    {
        col[i].a = rand()%10;
        col[i].b = rand()%10;
        col[i].c = rand()%10;
    }
    printf("\n\nLa matriz es: \n");

    for(i=0; i<n; i++)
    {
        printf("%d %d %d",col[i].a,col[i].b,col[i].c);
        printf("\n");
    }
    printf("\n\nFIN");

    FILE *matrix;
    char direc[60];
    printf("Dame la ruta y nombre de archivo:  ");
    scanf("%s",&direc);
    matrix=fopen(direc,"a");
    if(matrix==NULL)
    {
        printf("No se puede abrir el archivo sonso!!!");
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        fprintf(matrix,"%d %d %d\n",col[i].a,col[i].b,col[i].c);
    }
    fclose(matrix);

    matrix=fopen(direc,"r");
    if(matrix==NULL)
    {
        printf("No se puede abrir el archivo sonso!!!");
        exit(1);
    }
    int x,y,z;
    while(!feof(matrix))
    {
        fscanf(matrix,"%d %d %d\n",&x,&y,&z);
        printf("%d %d %d\n",x,y,z);
    }
    fclose(matrix);

}
