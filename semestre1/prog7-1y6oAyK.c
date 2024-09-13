/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE SI EL TIPO DE TECLA PRESIONADO
ESTA ENTRE 1 Y 6 Ò A Y K
Creado por: Mauricio Garcés
Fecha de creacion: 24-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int c;
    printf("Presiona una tecla\n");
    /*guardas el valor de getchar en c*/
    c = getchar();
    /*si el valor de c esta entre 1 y 6, imprime*/
    if('1' <= c && c <= '6')
    printf("La tecla %c esta entre 1 y 6\n",c);
    /*si el valor de c esta entre A y K, imprime*/
    if('A' <= c && c <= 'K')
    printf("La tecla %c esta entre A y K\n",c);
    /*si el valor de c NO!!! esta entre 1 y 6 o A y K, imprime*/
    if(!('1' <= c && c <= '6' || 'A' <= c && c <= 'K'))
    printf("La tecla %c no esta entre 1 y 6 ni entre A y K\n",c);
    system("PAUSE");
}
