#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main()
{
      int p=12, q=10,x,y,z,m,n,i;
      static char cad1[16],cad2[16],cad3[16],cad4[16],cad5[16],cad6[16],cad7[16];
      x=(p&q);
      y=(p|q);
      z=(p^q);
      m=~p;
      n=~q;
      itoa(p,cad1,2);
      itoa(q,cad2,2);
      itoa(x,cad3,2);
      itoa(y,cad4,2);
      itoa(z,cad5,2);
      itoa(~p,cad6,2);
      itoa(~q,cad7,2);
      printf("P  Q  &  |  ^  ~P  ~Q\n");
      printf("\n%s\n",cad6);
      printf("\n%s\n",cad1);
      for(i=0;i<16;i++)
      {
         printf("%c  %c  %c  %c  %c   %c   %c\n",cad1[i],cad2[i],cad3[i],cad4[i],cad5[i],cad6[i],cad7[i]);
      }
      getch();
}
