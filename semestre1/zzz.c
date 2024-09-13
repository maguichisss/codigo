#include<stdio.h>
main()
{
    int x,y,z;
    int kilo[5][5][5];
    for(z=0;z<5;z++)
    {
     for(x=0;x<5;x++)
        {
         for(y=0;y<5;y++)
            {
                kilo[x][y][z]=0;
                if(x==y==z)
                kilo[x][y][z]=1;
                printf("%2d ",kilo[x][y][z]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
