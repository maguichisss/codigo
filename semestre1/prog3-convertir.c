/*Programa que muestra la equivalencia de pesos mexicanos a dolares americanos*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float us_dollar, mx_peso=1300.00, factor=13.00;
    us_dollar=mx_peso/factor;
    printf("\n$%2.2f pesos mexicanos equivalen a $%0.0f dolares americanos.\n",mx_peso,us_dollar);
    /*los digitos a la izquierda del punto entre % y f no son significativos.*/
    getchar();/*tambien se puede usar getche()*/
}
