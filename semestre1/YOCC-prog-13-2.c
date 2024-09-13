/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA DE EXPONENCIACION
USANDO SENTENCIA obtnum() Y exponente()
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
int x,y;
main()
{
    obtnum();
    printf("\n\n%d a la %da pontencia es %d \n",x,y,exponente(x,y));
}

obtnum()
{
    printf("Teclea el numero que quieres elevar: ");
    scanf("%d",&x);
    printf("Teclea el valor del esponente: ");
    scanf("%d",&y);
}

exponente(m,n)
register int m,n;
{
    int sal=1;
    while(n-- > 0)
        sal = sal * m;
    return(sal);
}
