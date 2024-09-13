/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DICE SI EL NUMERO ES PRIMO O NO
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    float base,altura,area;
    printf("Escribe la base: ");
    scanf("%f",&base);
    printf("Dame la altura: ");
    scanf("%f",&altura);
    area = base * altura / 2;
    printf("\n\aEl resultado es: %.2f * %.2f / 2 = %.2f\n",base,altura,area);
}
