#include<stdio.h>
#define prod struct producto
#define n 2
prod
{
    int clave;
    char nomprod[40];
    int cantidad;
    float precio;
}
main()
{
    int i;
    prod invent[n];
    for(i=0; i<n; i++)
    {
        printf("\nClave del elemento [%d]: ",i+1);
        scanf("%d", &invent[i].clave);
        printf("\nNombre del Producto del elemento [%d]: ",i+1);
        gets(invent[i].nomprod);
        gets(invent[i].nomprod);
        printf("\nCantidad del producto[%d]: ",i+1);
        scanf("%d",&invent[i].cantidad);
        printf("\nPrecio por unidad del producto[%d]: ",i+1);
        scanf("%f",&invent[i].precio);
    }
    printf("\n\nEl inventario es: ");
    printf("\n\nClave\tNombre\t\tCantidad\tPrecio");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t%s\t\t%d\t\t%f",invent[i].clave,invent[i].nomprod,invent[i].cantidad,invent[i].precio);
    }
    printf("\n");
}
