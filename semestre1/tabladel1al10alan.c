/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA HACE LA TABLA DEL 1 AL 10 Y EL RESULTADO LO ELEVA A LA n
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
 int num=1, multi=1, res, exp;
 printf("Teclea el exponente: ");
 scanf("%d",&exp);
 for(num=1; num<=10; num++)
  {
            for(multi=1; multi<=10; multi++)
            {
            res=num*multi;
            printf("%2d por %2d es %3d",multi,num,res);
            printf("   (O_o) %5d a la %d es %d",res,exp,exponente(res,exp));
            printf("\n");
            }
            printf("\n");
  }
  system("pause");
}
exponente(m,n)
register int m,n;
{
    long sal=1;
    while(n-- > 0)
        sal = sal * m;
    return(sal);
}
