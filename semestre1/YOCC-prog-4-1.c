/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE CONVIERTE DOLARES A PESOS
Creado por: Mauricio Garcés
Fecha de creacion: 7-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float us_dollar, factor_c;

    /*asigna los valores iniciales y el factor de conversion*/
    us_dollar = 100.0;
    factor_c = 13.0;

    /*Imprime encabezado*/
    printf("Dolar Americano Tipo cambio Peso mexicano\n\n");

    /*Ciclo para calcular el valor correspondiente en pesos mexicanos
    para un rango de dolares americanos*/
    while(us_dollar<=200.0)
    {
        printf("%4.2f         %4.2f        %4.2f\n",us_dollar, factor_c,
               factor_c * us_dollar);
        us_dollar = us_dollar + 10;
    }
    system("pause");
}
