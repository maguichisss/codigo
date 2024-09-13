/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DESPLIEGA LA TABLA DE MULTIPLICAR PARA LOS NUMEROS DEL 1 AL 15,
PERO QUE NO DESPLIEGUE NINGUN NUMERO MAYOR QUE 99
Creado por: Mauricio Garcés
Fecha de creacion: 6-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
 int num, multi, res;
 /*se inicia el ciclo(primer for)*/
 for(num = 1; num <= 15; num++)
 {
    /*imprime*/
    printf("*Tabla del %d*\n\n",num);
    /*se inicia el ciclo interno(segundo for)*/
    for(multi = 1; multi <= 15; multi++)
    {
        /*se realiza la operacion*/
        res = num * multi;
        /*si la condicion se cumple, sale del segundo for y pasa al primer for*/
        if(res > 99)
        break;
        /*si la condicion no se cumple, no sale del ciclo e imprime*/
        printf("%2d x %d = %d\n",num,multi,res);
    }/*suma uno a multi en el segundo for y continua el segundo ciclo*/

    printf("\n");
  }/*en el primer for se suma 1 a num y continua el primer ciclo*/

 system("pause");
}
