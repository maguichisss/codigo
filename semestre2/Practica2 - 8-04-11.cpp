#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main()
{
      int x,y;
      char resp;
      do
      {
           system("cls");
           printf("Ingresa un numero: ");
           scanf("%d",&x);
           printf("\nIngresa otro numero: ");
           scanf("%d",&y);
           printf("\n%d & %d = %d",x,y,x&y);
           printf("\n%d & %d = %d",x,y,x|y);
           printf("\n%d & %d = %d",x,y,x^y);
           printf("\n~%d = %d",x,~x);
           printf("\n~%d = %d",y,~y);
           printf("\nDeseas continuar S/N :  ");
           scanf("%s",&resp);
      }while(resp=='s' || resp=='S');
}
