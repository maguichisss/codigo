/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE HACE LA SUMATORIA DE UNO HASTA n
Creado por: Mauricio Garcés
Fecha de creacion: 2-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int sum, n,i;
    printf("Dame un numero\n");
    scanf("%d",&n);
    sum = 1;
    for(i = 2; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("El resultado es: %d\n",sum);
}
