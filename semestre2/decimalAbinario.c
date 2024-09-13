#include<stdio.h>
#include<stdlib.h>
main()
{
    static int binario[16];
    int numero,i;

    printf("Introduce el numero que quieras pasar a binario: ");
    scanf("%d",&numero);
    printf("\n\nEl numero %d en binario es: ",numero);
    for(i=15; i>=0; i--)
    {
        if(numero%2 != 0)
        binario[i]=1;
        numero/=2;
    }
    for(i=0;i<16;i++)
    printf("%2d",binario[i]);
}
