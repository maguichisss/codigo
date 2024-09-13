/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DICE CUENTA PILDORAS CON UN BUCLE DO-WHILE
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int sobrante, botella, pildora, tam_bot;
    printf("Introduzca la cantidad inicial de pildoras: ");
    scanf("%d",&pildora);
    printf("Introduzca el numero de pildoras por botella: ");
    scanf("%d",&tam_bot);
    if(tam_bot < 1)
        tam_bot = 1;
    botella = 0;
    sobrante = pildora;
    do
    {
        sobrante = sobrante - tam_bot;
        botella++;
    }while(sobrante >= tam_bot);
    if(sobrante < 0)
    {
        sobrante += tam_bot;
        botella--;
    }
    printf("\n\nCantidad inicial de pildoras: %d\n",pildora);
    printf("\n\nNumero de botellas llenadas: %d\n",botella);
    printf("\n\nNumero de pildoras sobrante: %d\n",sobrante);
}
