/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DESPLIEGA UN NOMBRE USANDO UN ARREGLO Y UN CICLO WHILE
Creado por: Mauricio Garcés
Fecha de creacion: 21-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    /*Declaras el arreglo dos variable variables y pides un nobre */
    char nombre[20];
    int i = 0, n = 20;
    printf("Escribe un nombre: ");
    /*getchar llama una teclar y la guarda en nombre[0] tiene que ser diferente
      de enter e i < n*/
    while(((nombre[i++])=getchar()) != '\n' && i<n);
    /*al ultimo elemento del arreglo se le guarda un caracter nulo
      imprime la cadena de caracteres guardada en el arreglo nombre*/
    nombre[--i]= '\0';
    printf("%s\n",nombre);
}
