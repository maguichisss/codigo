/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE ORDENA DE MAYOR A MENOR 3 NUMEROS INTRODUCIDOS POR EL USUARIO
Creado por: Mauricio Garcés
Fecha de creacion: 2-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int n1,n2,n3,nx;
    printf("Escribe el primer numero\n");
    scanf("%d",&n1);
    printf("Escribe el segundo numero\n");
    scanf("%d",&n2);
    printf("Escribe el tercer numero\n");
    scanf("%d",&n3);
    if(n1>n2)
    {
        if(n1>n3)
        {
            if(n2>n3)
            printf("ES %d > %d > %d\n",n1,n2,n3);
        }
    }
}
