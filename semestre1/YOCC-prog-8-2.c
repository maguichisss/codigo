/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE QUE PERMITE INGRESAR REGION, VENTAS Y CALCULA EL GASTO DE ENVIO
USANDO ELSE IF
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float ventas, tasa;
    int region;

    /*acepta un digito de la terminal y lo coloca en la variable en region*/
    printf("Por favor escriba la region de ventas(1-4): ");
    scanf("%d",&region);

    /*recibe el monto de ventas de la terminal y lo coloca en ventas*/
    printf("Ingrese el monto total de ventas y presione ENTER: $ ");
    scanf("%f",&ventas);

    if(region< 1 || region > 4)
        printf("\n\nNo existe esa region");

    else
    {
        if(region == 1)
            tasa = .01;
        else if(region == 2)
                tasa = .02;
            else if(region == 3)
                    tasa = .03;
                else if(region == 4)
                        tasa = .04;
        if(ventas >= 0)
            printf("\n\nEl costo de envio es: $%5.2f\n\n",ventas * tasa);
    }
    system("pause");
}
