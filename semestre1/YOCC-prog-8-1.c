/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE SI LA TECLA PRESIONADA ES UN NUMERO
Creado por: Mauricio Garcés
Fecha de creacion: 7-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int c,num;
    printf("Por favor presione una tecla, luego presione Enter: ");
    c = getchar();

    if(c >= '0')
        num = 1;
    if(c > '9')
        num = 0;
    if(num)
        printf("\nEste es un numero.\n");
}
