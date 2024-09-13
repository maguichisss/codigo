#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
    int num1, num2, res, n, num3;
    int oper, i;
    int correcto, aci=0;
    printf("Cuantas operaciones deseas realizar:  ");
    scanf("%d",&num1);
    n=num1;
    for(i=0; i<n; i++)
    {
        system("clear");
        printf("%d operaciones \n",i+1);
        srand((unsigned)time(NULL));
        num2 = rand()%10;
        oper = rand()%5;
        switch(oper)
        {
            case 0:
            printf("Cual es el resultado de  %d + %d   \n",num1,num2);
            scanf("%d",&res);
            correcto=num1+num2;
            if(res== num1+num2)
                aci++;

            break;

            case 1:
            printf("Cual es el resultado de %d - %d   \n",num1,num2);
            scanf("%d",&res);
            correcto=num1-num2;
            if(res== num1-num2)
                aci++;

            break;

            case 2:
            printf("Cual es el resultado de  %d * %d   \n",num1,num2);
            scanf("%d",&res);
            correcto=num1*num2;
            if(res== num1*num2)
                aci++;

            break;

            case 3:
            printf("Cual es el resultado del modulo %d | %d   \n",num1,num2);
            scanf("%d",&res);
            correcto=num1%num2;
            if(res==num1%num2)
                aci++;

            break;

            case 4:

            num3=num1*num2;
            if(num1==0)
            num1=num2;
            printf("Cual es el resultado de dividir %d / %d   \n",num1,num2);
            scanf("%d",&res);
            correcto=num3/num1;
            if(res== correcto)
                aci++;

            break;
        }
        num1=correcto;
    }
    printf("\nTuviste %d aciertos ",aci);
}
