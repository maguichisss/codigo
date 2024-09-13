#include<stdio.h>
#include<stdlib.h>
main()
{
    int x,y,z=1,kilo[5][5];
    for(y=0;y<5;y++)
        for(x=0;x<5;x++)
            kilo[x][y]=z++;

    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            printf("%2d ",kilo[x][y]);
        }
        printf("\n");
    }
}
