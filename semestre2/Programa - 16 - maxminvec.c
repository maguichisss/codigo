#include<stdio.h>
#include<stdlib.h>
#define n 3
main()
{
    float max, min, vec[n];
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d elemento : ",i+1);
        scanf("%f",&vec[i]);
    }
    max = vec[0];
    min = vec[0];
    for(i=0;i<n;i++)
    {
        if(vec[i]>max)
            max = vec[i];
        if(vec[i]<min)
            min = vec[i];
    }
    printf("El maximo es: %.2f\nEl minimo es: %.2f",max, min);
}
