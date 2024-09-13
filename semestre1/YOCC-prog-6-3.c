/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE PERMITE INGRESAR REGION, VENTAS Y CALCULA EL GASTO DE ENVIO
Creado por: Mauricio Garcés
Fecha de creacion: 7-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float ventas, tasa;
    int region;

    /*se inicializa tasa*/
    tasa = 0.0;

    /*recibe un digito de la terminal y lo guarda en region*/
    printf("Por favor escriba la region de ventas(1-4): ");
    scanf("%d",&region);

    /*recibe el monto de ventas de la terminal y lo coloca en ventas*/
    printf("Ingrese el monto total de ventas: $ ");
    scanf("%f",&ventas);

    /*checa errores de entrada*/
    if(region < 1)
        printf("\nEsa region no existe");
    if(region > 4)
        printf("\nEsa region no existe");

    /*Asigna los cargos de envio para las distintas regiones*/
    if(region == 1)
        tasa = 0.01;
    if(region == 2)
        tasa = 0.02;
    if(region == 3)
        tasa = 0.03;
    if(region == 4)
        tasa = 0.04;
    if(region != 0.0)
        printf("\nLos costos de envio son $ %5.2f\n", ventas*tasa);
    system("pause");
}
