/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DICE LOS DIVISORES DE UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{

    int num, divisores;
    printf("Introduce un numero: ");
    scanf("%d",&num);
    printf("Sus divisores son:\n");
    for(divisores=1;divisores <= num; divisores++)
        if(num % divisores == 0)
            printf("%4d\n",divisores);
}
