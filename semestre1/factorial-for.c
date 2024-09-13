/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE HACE LA SUMATORIA DE UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 2-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int fact, n,i;
    printf("Dame un numero\n");
    scanf("%d",&n);
    fact = 1;
    for(i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    printf("El resultado es: %d\n",fact);
}
