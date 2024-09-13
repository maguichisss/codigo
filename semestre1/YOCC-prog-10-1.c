/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE CALCULA LAS TABLAS DE MULTIPLICAR DE LOS NUMERO 1 AL 5
USANDO FORs ANIDADOS
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int x,y;
    for(x = 1; x <= 5; x++)
    {
        for(y = 1; y <= 5; y++)
            printf("%3d",x*y);
        printf("\n");
    }
}
