#include<stdio.h>
#include<ctype.h>
main()
{
    int x,y,z=1,kilo[5][5];
    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            kilo[x][y]=z++;
            printf("%2d ",kilo[x][y]);
        }
        printf("\n");
    }
}
