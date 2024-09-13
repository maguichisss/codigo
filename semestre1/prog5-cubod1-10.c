/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE MUESTRA EL CUBO DE UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 16-10-10
Fecha de modificacion: 17-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int i;
    /*inicia ciclo for*/
    for(i=1;i<=10;i++)
    {/*imprime cada vez que la condicion se cumple*/
        printf("%4d cubo de %3d\n",i*i*i,i);
        printf("\n");
    }
    getch();
}
