#include<stdio.h>
#include<stdlib.h>
main()
{
 int num=1, multi=1, res;
 for(num=1; num<=10; num++)
  {
            for(multi=1; multi<=10; multi++)
            {
            res=num*multi;
            printf("%d por %d es %d\n",multi,num,res);
            }
            printf("\n");
  }
  system("pause");
}
