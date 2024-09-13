#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
    int f, c, i, j, k, m[10][10];
    srand((unsigned)time(NULL));
    printf("Introduce numero de filas: ");
    scanf("%d", &f);
    printf("\nIntroduce numero de columnas: ");
    scanf("%d", &c);
    printf("\n\n");
    int min[f],max[c];
//introduces numeros random
    for(i = 0; i < f; i++)
        for(j = 0; j < c; j++)
           m[i][j]= rand()%100;

//imprimes matrix
    for(i = 0; i < f; i++)
    {
       for(j = 0; j < c; j++)
       printf("%2d ", m[i][j]);
       printf("\n");
    }
//iniciamos for para comparar el primer renglon y sucesivamente
    for(i = 0; i < f; i++)
    {
//ponemos j=0 porque al acabar el primer ciclo j tiene que ser 0 al guardar min
        j=0;
//inicializamos min a el primer elemento del renglon
        min[i] = m[i][j];
//empieza el for para cambiar de columna
        for(j = 0; j < c; j++)
        {
//comparamos el elemento de la matriz con min
            if(m[i][j] < min[i])
            {
                min[i] = m[i][j];
            }
        }
        printf("\nEl menor del renglon [%d] es: %d ",i+1,min[i]);
    }
//Comparar columnas para obtener el maximo
    for(j=0; j<c; j++)
    {
        i=0;
        max[j] = m[i][j];
        for(i=0 ; i<f; i++ )
        {
            if(m[i][j] > max[j])
            {
                max[j] = m[i][j];
            }
        }
        printf("\nEl mayor de la columna [%d] es: %d ",j+1,max[j]);
    }
//comparar los min con los max
    for(i=0; i<f; i++)
        for(j=0; j<c; j++)
            if(min[i]==max[j])
                printf("\n%d ",max[j]);
}
