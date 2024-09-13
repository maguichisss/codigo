/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DICE SI EL NUMERO ES PAR O IMPAR
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int num;
    printf("Teclea un numero: ");
    scanf("%d",&num);
    if(num%2==0)
        printf("\nEl numero %d es par\n",num);
    else
    printf("\nEl numero %d es impar\n",num);
}
