#include<stdio.h>
main()
{
    int i;
    float num;
    char bin[28];
    printf("Dame un numero con decimales: ");
    scanf("%f",&num);

    for(i=0; i<28; i++)
    {
        printf("\n%d.-  %.20f X 2 = ",i+1,num);
        num=num*2.0;
        printf("%.20f",num);
        if(num>=1.0)
        {
            num-=1.0;
            bin[i]='1';
        }

        else
        bin[i]='0';
    }
    printf("\nEl numero es: %s\n",bin);
}
