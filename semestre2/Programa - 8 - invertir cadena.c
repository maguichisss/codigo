#include<stdio.h>
int numletra(char palabra[])
{
    int i=0;
    do
        i++;
    while(palabra[i-1]!='\0');
    return(i-1);
}
main()
{
    static char palabra[30];
    static char copia[30];
    int i,x,cont=0;
    printf("Escribe una palabra: ");
    gets(palabra);
    x=numletra(palabra);
    for(i=0; i<x; i++)
    {
        copia[x-i-1]=palabra[i];
    }
    printf("\n\nPalabra al reves  : ");
    for(i=0; i<=x; i++)
    {
        printf("%c",copia[i]);
    }
    printf("\n\n");
}
