#include<stdio.h>
main()
{
    int segxmin=60,segxhor=3600;
    int hor,min,seg,minx,segx;
    printf("Cuantos segundos??? ");
    scanf("%d",&seg);
    hor=seg/segxhor;
    min=seg/segxmin;
    minx=min&segxmin;
    segx=seg&segxmin;
    printf("%d segundos es igual a %d horas "
           "%d minutos %d segundos.",seg,hor,minx,segx);

}
