#include<stdio.h>
main()
{
    static char num[16];
    int mult[16];
    int numero,i,x=1;
    printf("Dame un numero: ");
    scanf("%s",&num);
    for(i=15; i>=0; i--)
    {
        mult[i]=x;
        x*=2;
    }
    for(i=15; i>=0; i--)
    {
        if(num[i]!='1')
            mult[i]=0;
    }
    x=0;
    for(i=15; i>=0; i--)
        x+=mult[i];
    printf("%d",x);
}
