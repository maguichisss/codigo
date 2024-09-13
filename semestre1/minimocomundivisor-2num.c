/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE CALCULA EL COSTO DE ENVIO SEGUN LA REGION(USANDO FUNCION COSTO)
Creado por: Mauricio Garcés
Fecha de creacion: 16-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int n1,n2,i;
    printf("Escribe el primer numero: ");
    scanf("%d",&n1);
    printf("Dame el segundo numero: ");
    scanf("%d",&n2);
    for(i=1;i<=n1 && i<=n2;i++)
    {

        if(n1%i==0 && n2%i==0)
        {
            if((n1==1 || n2==1) && (n1%n2!=0 || n2%n1!=0) && i==1)
            {
                printf("\nEl mcd de %d y %d es: %d\n",n1,n2,i);
                return;
            }
            if(i>1)
            {
                printf("\nEl mcd de %d y %d es: %d\n",n1,n2,i);
                return;
            }
        }
    }
}
