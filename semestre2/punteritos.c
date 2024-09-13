#include <stdio.h>
main ()
{
    int a=10, b=20, c=0;
    int *p, *q, *r;
    p=&a;
    q=&b;
    *r=*p*(*q);
    printf("%d  %d  %d", *p, *q, *r);

    a=23;
    b=43;
    printf("\n%d  %d  %d", *p, *q, *r);

    *r=*p*(*q);
    printf("\n%d  %d  %d", *p, *q, *r);

    c=*p*(*q);
    printf("\n%d  %d  %d", *p, *q, c);
}
