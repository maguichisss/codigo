/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE SI EL TIPO DE TECLA PRESIONADO
ES NUMERO O LETRA
Creado por: Mauricio Garcés
Fecha de creacion: 26-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int c;
    printf("Presiona una y solo una tecla\n");
    /*guardas el valor de getchar en c*/
    c = getchar();
    /*si el valor de c esta entre '0' y '9', imprime*/
    if(48 <= c && c <= 57)
        printf("La tecla %c es un numero\n",c);
    /*todo lo demas es letra*/
    else
        printf("La tecla %c es letra\n",c);
    system("pause");
}

