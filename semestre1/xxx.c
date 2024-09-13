#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
main()
{
    float n,x;
    printf("Escribe un numero: ");
    scanf("%f",&n);
    x=sqrt(n);
    printf("\nLa raiz es: %f\n\n",x);

    multimatrices();
}
multimatrices()
{
    int i,n=3;
    int vec1[3],vec2[3];
    for(i=0;i<n;i++)
    {
        printf("Escribe un valor para el elemento %d del vector 1 : ",i);
        scanf("%d",&vec1[i]);
        printf("Escribe un valor para el elemento %d del vector 2 : ",i);
        scanf("%d",&vec2[i]);
    }
    int strcmp(const char *vec1, const char *vec2);
}




