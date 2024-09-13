#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
    int num1, num2, res, n, num3;
    int oper, i;
    int correcto, aci=0, total=0;
    printf("Cuantas operaciones deseas realizar:  ");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    num1 = rand()%10;
    for(i=0; i<n; i++)
    {
        system("clear");
        printf("%d operaciones \n",i+1);
        num2 = rand()%10;
        oper = rand()%4;
        switch(oper)
        {
            case 0:
            if(i==0)
            {
                printf("  %d + %d   \n",num1,num2);
                total=num1+num2;
            }
            else
            {
                printf(" + %d   \n",num2);
                total+=num2;
            }
            scanf("%d",&res);
            correcto=num1+num2;
            if(res== num1+num2)
                aci++;

            break;

            case 1:
            if(i==0)
            {
                printf("  %d - %d   \n",num1,num2);
                total=num1-num2;
            }
            else
            {
                printf(" - %d   \n",num2);
                total-=num2;
            }
            scanf("%d",&res);
            correcto=num1-num2;
            if(res== num1-num2)
                aci++;

            break;

            case 2:
            if(i==0)
            {
                printf("  %d * %d   \n",num1,num2);
                total=num1*num2;
            }
            else
            {
                printf(" * %d   \n",num2);
                total*=num2;
            }

            scanf("%d",&res);
            correcto=num1*num2;
            if(res== num1*num2)
                aci++;

            break;

            case 3:
            if(i==0)
            {
                if(num2==0)
                    num2=1;
                printf("  %d / %d   \n",num1,num2);
                total=num1/num2;
            }
            else
            {
                if(num2==0)
                    num2=1;
                printf(" / %d   \n",num2);
                total/=num2;
            }
            printf("Debes truncar el resultado: ");
            scanf("%d",&res);
            correcto=num1/num2;
            if(res== correcto)
                aci++;

            break;
        }

        num1=correcto;
    }
    printf("\nEl resultado es: %d ",total);
    printf("\nTuviste %d aciertos \n\n",aci);
}
