/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE CALCULA EL COSTO DE ENVIO SEGUN LA REGION(USANDO FUNCION COSTO)
Creado por: Mauricio Garcés
Fecha de creacion: 10-11-10
Fecha de modificacion 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    /*Se declaran variables y la FUNCION costo()*/
    int region;
    float tasa,ventas;
    float costo();
    /*Pide ventas y region*/
    printf("Introduzca el monto total de las ventas: $");
    scanf("%f",&ventas);
    printf("Introduzca la region de ventas (1-4): ");
    scanf("%d",&region);
    switch(region)
    {
        /*Dependiendo la region asigna un valor a tasa*/
        /*LLAMA a la funcion costo con los argumentos region, ventas, tasa*/
        /*Termina*/
        case 1:
            tasa = 0.01;
            costo(region,ventas,tasa);
            break;
        case 2:
            tasa = 0.02;
            costo(region,ventas,tasa);
            break;
        case 3:
            tasa = 0.03;
            costo(region,ventas,tasa);
            break;
        case 4:
            tasa = 0.04;
            costo(region,ventas,tasa);
            break;
        /*Si la region no cioncide muestra un error */
        default:
            printf("\aERROR: la region no es correcta");
    }
}
/*Define la funcion*/
float costo(lugar,vendido,porciento)
int lugar;
float vendido,porciento;
{
    float result;
    result = vendido * porciento;
    printf("\nEl costo de envio a la region %d es de: $%.2f\n",lugar,result);
}
