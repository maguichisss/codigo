/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
SERIE FIBONACCI
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int num, n1=1, n2=0, save,i;
    printf("Cuantos numero quieres?  ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("%d+",n1);
        save=n1;
        n1=n1+n2;
        n2=save;
    }
    printf("...\n");
}
