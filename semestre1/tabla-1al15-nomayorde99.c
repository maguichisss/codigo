#include<stdio.h>
#include<stdlib.h>
main()
{
 int num, multi, res;
 for(num = 1; num <= 15; num++)
  {
    printf("*Tabla del %d*\n\n",num);
    for(multi = 1; multi <= 15; multi++)
    {
        res = num * multi;
        if(res > 99)
        break;
        printf("%2d x %d = %d\n",multi,num,res);
    }
    printf("\n");
  }
  system("pause");
}
