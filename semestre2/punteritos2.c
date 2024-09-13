#include <stdio.h>
main ()
{
    int a, b;
    int *p, *q, *r;

    //*r=*p*(*q);
    printf("Ingresa el valor de a");
    scanf("%d", &a);

    printf("Ingresa el valor de b");
    scanf("%d", &b);

    p=&a;
    q=&b;

    printf("%d  %d", *p, *q);
}
