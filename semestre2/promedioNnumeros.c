/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE OBTIENE PROMEDIO DE N NUMEROS
Creado por: Mauricio Garc�s
Fecha de creacion: 01-02-11
Fecha de modificacion 01-02-11
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int n,i;
    printf("Cuantos numeros vas a promediar? ");
    scanf("%d",&n);
    float grup[n],prom=0;
    for(i=0; i<n; i++)
    {
        printf("Dame la calificacion del alumno %d ",i+1);
        scanf("%f",&grup[i]);
    }
    for(i=0;i<n;i++)
    {
        prom=prom+grup[i];
    }
    prom=prom/n;
    printf("El promedio es: %.2f ",prom);
}
