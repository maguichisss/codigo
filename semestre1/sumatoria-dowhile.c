/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE HACE LA SUMATORIA DE UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 2-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int sum, n;
    printf("Dame un numero\n");
    scanf("%d",&n);
    sum = n-1;
    do
    {
        n = n + sum;
        sum--;
    }
    while(sum>=1);
    printf("El resultado es: %d\n",n);
}
