/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE SI LA TECLA PRESIONADA ES UN NUMERO
USANDO IFs ANIDADOS
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int c;
    printf("Por favor presione una tecla, luego presione ENTER: ");
    c = getchar();
    if(c >= '0')
        if(c <= '9')
            printf("\nEste es un numero\n\n");
    system("pause");
}
