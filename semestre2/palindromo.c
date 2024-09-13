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
    scanf("%s", &palabra);
    x=numletra(palabra);
    printf("Letras de la palabra: %d\n",x);
    for(i=0; i<x; i++)
    {
        copia[x-i-1]=palabra[i];
    }
    printf("Palabra  copia  : ");
    for(i=0; i<=x; i++)
    {
        printf("%c",copia[i]);
    }
    printf("\nPalabra original: %s\n",palabra);
    for(i=0; i<x; i++)
    {
        if(copia[i]==palabra[i])
        cont++;
    }
    printf("Letras que coinciden: %d\n",cont);
    if(cont==x)
    printf("Es palindromo");
    else
    printf("No es palindromo");
}

