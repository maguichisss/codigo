/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE HACE EL FACTORIAL DE UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 2-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int den;
    float sum, n;
    printf("Dame un numero\n");
    scanf("%d",&den);
    sum = 0;
    for(n = 1; n <= den; n++)
    {
        sum = sum + (1 / n);
    }
    printf("El resultado es: %.3f\n",sum);
}
