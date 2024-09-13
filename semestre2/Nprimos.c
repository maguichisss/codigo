#include <stdio.h>

main()
{
    int x, div, primo, contador;

    printf("Ingresa un numero entero  ");
    scanf("%d", &x);

    contador = 0;

    for (div = 2; div < x; div++)
        {
            primo = (x % div);

            if ( primo == 0)
            {
             printf("\n%d <- SI", div);
             contador = 1;
            }
        }

    if (contador == 1)
        printf("\n\n%d no es un numero primo\n", x);
    else
        printf("\n\n%d es numero primo\n", x);
}
