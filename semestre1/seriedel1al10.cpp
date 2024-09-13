//ESTE PROGRAMA IMPRIME LA SERIE DEL 1 AL 10, CON LA ESTRUCTURA FOR.
/*Serie1*/
#include<stdio.h>
#include<conio.h>
main()
{
 int serie,r,l;
 l=10;
 printf("Serie del 1-10\n");
 for(r=0;r<10;r++)
 {
  serie=r+1;
  printf("%d\n",serie);
 }
 getch();
 return(0);
}
