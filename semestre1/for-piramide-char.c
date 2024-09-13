
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA HACE UNA PIRAMIDE DEL CARACTER QUE PRESIONASTE
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
Fecha de modificacion : 08-02-11
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int n,x,y;
    char c[10];
    printf("Introduce un caracter: ");
    scanf("%s",&c);
    printf("De cuantos pisos sera: ");
    scanf("%d",&n);
    for(x=n;x>=1;x--)
    {
        for(y=x;y<=n;y++)
        {
            printf("%s",c);
        }
        printf("\n");
    }

}


