/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE HALLA EN MENOR DE 2 NUMEROS
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int n1,n2,menor;
    printf("Teclea 2 numeros:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    if(n2 < n1)
    {
        menor = n2;
        printf("%d es menor que %d",menor,n1);
    }
    if(n1 < n2)
            printf("%d es menor que %d",n1,n2);
    if(n1 == n2)
                printf("%d es igual que %d",n1,n2);

}
