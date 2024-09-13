/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE UN NUMERO DECIMAL A BINARIO, OCTAL O HEXADECIMAL
Creado por: Mauricio Garcés
Fecha de creacion: 8-11-10
Fecha de modificacion 9-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int num, tipo, temp;
    long bin,x;
    printf("Escribe el numero que deseas convertir: ");
    scanf("%d",&num);
    printf("\nSelecciona el sistema al que quieres convertir\n1-Binario\n2-Octal\n3-Hexadecimal\n\n");
    scanf("%d",&tipo);
    switch(tipo)
    {
        case 1:
        bin = 0;
        x = 1;
        temp = num;
        do
        {
            bin += temp % 2 * x;
            temp /= 2;
            x *= 10;
        }while(temp >= 2);
        bin += x * temp;
        printf("\n\n%d en decimal es: %d en binario\n",num,bin);
        break;

        case 2:
        printf("\n\n%d en decimal es: %c en octal\n",num,num);
        break;

        case 3:
        printf("\n\n%d en decimal es: %x en hexadecimal\n",num,num);
        break;
    }
}
