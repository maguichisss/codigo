/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*    PROGRAMA QUE MULTIPLICA 2 NUMEROS Y MUESTRA EL REUSLTADO         */
/*                   Creado por: Mauricio Garcés                       */
/*                   Fecha de creacion: 14-10-10                       */
/*                   Fecha de modificacion:                            */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    /*declaramos las variables*/
    int prod,numero1,numero2;
    /*inicializamos las variables*/
    numero1=5;
    numero2=10;
    /*multiplicamos los 2 numeros*/
    prod=numero1*numero2;
    /*mostramos el resultado en la pantalla*/
    printf("\nEl producto de %d y %d es: %d\n",numero1,numero2,prod);
    getch();
}
