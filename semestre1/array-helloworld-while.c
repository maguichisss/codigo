/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DESPLIEGA HELLO WORLD USANDO UN ARREGLO Y UN CICLO WHILE
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    char saludo[] = "hello, world";
    int i = 0;
    while(saludo[i] != '\0')
        printf("%c",saludo[i++]);
    printf("\n");
}
