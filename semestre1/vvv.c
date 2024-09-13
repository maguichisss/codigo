/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DESPLIEGA HELLO WORLD USANDO UN ARREGLO
USANDO UN CICLO WHILE
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    char nombre[20];
    printf("Escribe un nombre: ");
    int i = 0, n = 20;
    while(((nombre[i++])=getchar()) != '\n' && i<n);
    nombre[--i]= '\0';
    printf("%s",nombre);
    printf("\n");
}
