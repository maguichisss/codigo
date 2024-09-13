/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE SUMA DOS VECTORES(ARREGLOS)
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int maximo, minimo, i, n=5;
    int vec[5];
    for(i=0;i<n;i++)
    {
        printf("Escribe un valor para el elemento %d del vector: ",i);
        scanf("%d",&vec[i]);
    }
    maximo = vec[0];
    minimo = vec[0];
    for(i=0;i<=n;i++)
    {
        if(vec[i]>maximo)
            maximo = vec[i];
        if(vec[i]<minimo)
            minimo = vec[i];
    }
    printf("El maximo es: %d\nEl minimo es: %d",maximo, minimo);
}
