/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DE DONDE INTRODUCES NOMBRE Y EDAD, Y LO DESPLIEGA EN PANTALLA
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    char nombre[30],apellido[30];
    int edad;
    printf("Escribe tu nombre(s): ");
    scanf("%s",nombre);
    printf("Escribe tu apellido(s): ");
    scanf("%s",apellido);
    printf("Cual es tu edad? ");
    scanf("%d",&edad);
    printf("\n\n%s %s tienes %d a%cos.",nombre,apellido,edad,164);
}
