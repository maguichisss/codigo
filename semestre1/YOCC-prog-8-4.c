/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE EL COSTO DE ENVIO DEPENDIENDO LA REGION Y VENTAS
USANDO SWITCH
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float ventas, tasa;
    int region;
    printf("Introduce el monto de las ventas: $ ");
    scanf("%f", &ventas);
    printf("Introduce la region de ventas (1-4): ");
    scanf("%d", &region);

    switch(region)
    {
        case 1:
            tasa = .01;
            break;
        case 2:
            tasa = .02;
            break;
        case 3:
            tasa = .03;
            break;
        case 4:
            tasa = .04;
            break;
        default:
            printf("No existe esa region de ventas.\n");
    }
    if(ventas >= 0)
      printf("\n\nEl costo del envio es: $%5.2f\n",ventas * tasa);
}
