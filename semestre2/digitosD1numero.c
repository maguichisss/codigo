#include<stdio.h>
main()
{
    int numero,x,cont=0;
    printf("Dame un numero: ");
    scanf("%d",&numero);
    x=numero;
    do
    {
        cont++;
        numero/=10;
    }
    while(numero!=0);
    printf("\nEl numero de digitos de %d es: %d\n",x, cont);
}
