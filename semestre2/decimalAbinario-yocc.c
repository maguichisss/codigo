#include<stdio.h>
main()
{
    int num, bin, x, temp;
    printf("Escribe el numero que deseas convertir: ");
    scanf("%d",&num);
    bin = 0;
    x = 1;
    temp = num;
    do
    {
        bin += temp % 2 * x;
        temp /= 2;
        x *= 10;
    }
    while(temp >= 2);
    bin += x * temp;
    printf("\n\n%d en decimal es: %d en binario\n",num,bin);
}
