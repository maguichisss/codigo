#include<stdio.h>
main()
{
    static char palabra[30];
    int i=0,x;
    printf("Escribe una palabra: ");
    scanf("%s", &palabra);
    do
    {
        i++;
    }
    while(palabra[i-1]!='\0');
    printf("Tiene %d", i-1);
}
