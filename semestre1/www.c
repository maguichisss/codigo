#include<stdio.h>
#include<ctype.h>
main()
{
    int x,y,z=1,kilo[36][36];
    for(x=0;x<36;x++)
    {
        for(y=0;y<36;y++)
        {
            kilo[x][y]=48;
            if((y==10 && (10<x&&x<20))||(y==20 && (10<x&&x<20))||(x==10 && (10<=y&&y<=20))||(x==20 && (10<=y&&y<=20)))
            kilo[x][y]=0;
            if((y==5 && (5<x&&x<25))||(y==25 && (5<x&&x<25))||(x==5 && (5<=y&&y<=25))||(x==25 && (5<=y&&y<=25)))
            kilo[x][y]=0;
            printf("%2c",kilo[x][y]);
        }
        printf("\n");
    }
}
