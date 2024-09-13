/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE PROMEDIA DOS NUMEROS
USANDO UNA FUNCION prom()
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int x, y;
    float a;
    float prom();
    x = 10;
    y = 15;
    a = prom(x,y);/*Llamada a la funcion*/
    printf("El promedio de 10 y 15 es %.2f\n",a);
}
/*Definicion de prom()*/
float prom(mont1,mont2)
int mont1,mont2;
{
    float respuesta;
    respuesta = mont1 + mont2;
    respuesta /= 2;
    return(respuesta);
}
