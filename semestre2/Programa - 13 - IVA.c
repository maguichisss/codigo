#include<stdio.h>
#include<stdlib.h>
#define IVA .16
main()
{
    float precio, res;
    printf("Precio: ");
    scanf("%f",&precio);
    res = precio*IVA;
    printf("\nCon el 16 de IVA");
    printf("\n\nEl IVA de %.2f es: %.2f\n\n",precio,res);
}

