/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE RESTA DOS VECTORES(ARREGLOS)
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,n=5;
    int vec1[5],vec2[5],res[5];
    for(i=0;i<n;i++)
    {
        printf("Escribe un valor para el elemento %d del vector 1 : ",i);
        scanf("%d",&vec1[i]);
        printf("Escribe un valor para el elemento %d del vector 2 : ",i);
        scanf("%d",&vec2[i]);
    }
    for(i=0;i<n;i++)
    {
        res[i] = vec1[i]-vec2[i];
        printf("La de de %5d menos %5d es: %5d\n",vec1[i],vec2[i],res[i]);
    }
}
