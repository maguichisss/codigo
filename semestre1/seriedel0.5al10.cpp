//ESTE PROGRAMA IMPRIME LA SERIE DEL 0.5 AL 10, CON LA ESTRUCTURA FOR.
/*Serie2*/
#include<stdio.h>
#include<conio.h>
main()
{
 float sr2,e,l;
 l=6;
 printf("Serie del 0.5-10\n");
 for(e=0;e<=10;e+=0.5)
 {
  sr2=e+0.5;
  printf("%.2f\n",sr2);
  l++;
 }
 getche();
 return(0);
}
