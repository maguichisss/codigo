/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE CALCULA EL PROMEDIO DEL MONTO DE VENTAS POR CADA CUARTO DE AÑO
Creado por: Mauricio Garcés
Fecha de creacion: 10-11-10
Fecha de modificacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{   /*DECLARA la FUNCION prom(), variables y se inicializan*/
    int cuarto;
    float pventas, ventas, prom();
    ventas = 30000.00;
    cuarto = 4;

    /*Se LLAMA a la funcion prom() con los ARGUMENTOS ventas y cuarto*/
    /*y el resultado que se obtenga lo guardará en pventas, e imprime*/
    pventas = prom(ventas,cuarto);
    printf("El promedio de ventas por cada 3 meses es: $%.2f\n\n",pventas);
    system("pause");
}
/*El error estaba en que los parametros estaban al reves*/
/*Se DEFINE la funcion prom con sus parametros*/
/*Se DECLARAN los PARAMETROS y su tipo de dato*/
float prom(monto,cuar)
int cuar;
float monto;
{  /*Se delara la variable respuesta
   /*Se realiza la operacion y el resultado se guarda en respuesta*/
   /*Finalmente regresa el valor de respuesta a donde la funcion fue llamada*/
    float respuesta;
    respuesta = monto/cuar;
    return (respuesta);
}
