#include<stdio.h>
#include<stdlib.h>
main()
{
    int n=0,x,y;
    char array[50];
    printf("Escribe algo\n");
    scanf("%s",&array);
    if((array[n]<65 || array[n]>90)&&(array[n]<97 || array[n]>122))
    {
        printf("Solo letritas\n");
    }
    for(n=0;n<50;n++)
    {
        if(array[n]>64 && array[n]<91)
            {
            printf("%c",array[n]+32);
            }
        else if(array[n]>96 && array[n]<123)
            {
            printf("%c",array[n]-32);
            }
        else
            {
            printf("\n");
            break;
            }
    }
}
