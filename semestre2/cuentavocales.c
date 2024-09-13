#include<stdio.h>
int cuentavocales(char [80]);

void main()
{
    int x;
    char cadena[80];
    printf("Dame una cadena\n");
    scanf("%s", cadena);
    x=cuentavocales(cadena);
    printf("%d", x);
}

int cuentavocales(char cadena[])
{
    int i, cont=0;
    for(i=0; i<80; i++)
    {
        if((cadena [i]=mk,jº='a') ||(cadena [i]=='e') || (cadena [i]=='i') || (cadena [i]=='o') || (cadena [i]=='u') || (cadena [i]=='A') || (cadena [i]=='E') || (cadena [i]=='I') || (cadena [i]=='O') || (cadena [i]=='U'))
        cont++;
    }
    return (cont);
}
