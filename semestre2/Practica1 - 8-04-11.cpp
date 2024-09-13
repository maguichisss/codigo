#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void verbits(int i)
{
      int t;
      for(t=256; t>0; t=t/2 )
          if(i&t)
             printf("1");
          else
             printf("0");
      printf("\n");
      getch();
}
main()
{
      char resp;
      int x;
      do
      {
          system("cls");
          printf("Introduce un entero: ");
          scanf("%d",&x);
          printf("\nLos bist del byte son: ");
          verbits(x);
          printf("\nSi deseas continuar presiona S/s: ");
          scanf("%s",&resp);
      }while(resp=='S' || resp=='s');
}
