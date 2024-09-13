/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE SI EL TIPO DE TECLA PRESIONADO ES NUMERO O NO
Creado por: Mauricio Garcés
Fecha de creacion: 19-10-10
Fecha de modificacion: 20-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int num,c;
    printf("Presiona una tecla\n\n");
    /*El valor en ASCII de la tecla presionada se guarda en c*/
    c=getchar();
    /*El if pregunta si 47<c y c<58, si si, imprime*/
    if(47<c && c<58)
    printf("\nLa tecla presionada es un numero\n\n");
    /*El if pregunta si 58<c ó c<47, si si, imprime*/
    if(c>58 || c<47)
    printf("\nLa tecla presionada no es un numero\n\n");
    getch();
}
