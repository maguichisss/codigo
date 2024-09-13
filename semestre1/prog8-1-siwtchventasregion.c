/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE EL COSTO DE ENVIO DEPENDIENDO
LA REGION Y VENTAS
Creado por: Mauricio Garcés
Fecha de creacion: 26-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float ventas, proporcion;
    int region;  /*pregunta las ventas y la region*/
    printf("Introduce el monto de las ventas: $ ");
    scanf("%f", &ventas);
    printf("Introduce la region de ventas (1-4): ");
    scanf("%d", &region);
    /*evalua la region y segun sea el caso,
    se le asigna un valor a la proporcion,
    si la region no es verdadera,
    usando default despliega: no hay tal region y termina*/
    switch(region)
    {
        case 1:
            proporcion = .01;
            break;
        case 2:
            proporcion = .02;
            break;
        case 3:
            proporcion = .03;
            break;
        case 4:
            proporcion = .04;
            break;
        default:
            printf("No hay tal region.\n");
    }
    /*si la region NOOO es menor que 1 ó mayor que 4, imprime*/
    if(!(region < 1 || region > 4))
      printf("\n\nEl costo del envio es de: $%.2f\n",ventas * proporcion);
}
