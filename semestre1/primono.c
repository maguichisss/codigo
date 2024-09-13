/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DICE SI EL NUMERO ES PRIMO O NO
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
Fecha de modificacion 16-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int num,x;
    printf("Teclea un numero: ");
    scanf("%d",&num);
    if(num==1)
    {
        printf("El numero %d es primo\n",num);
        return;
    }
    for(x=2;x<=num/2;x++)
    {
        if(num%x==0)
        {
            printf("El numero %d no es primo\n",num);
            return;
        }
    }
    printf("El numero %d es primo\n",num);
}
