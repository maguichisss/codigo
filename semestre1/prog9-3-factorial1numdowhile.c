

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE DESPLIEGA EL FACTORIAL DE UN NUMERO INTRODUCIDO POR EL USUARIO
Creado por: Mauricio Garcés
Fecha de creacion: 27-10-10
Fecha de modificación 29-10-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
main()
{
      int temp,x;
      long i;
      printf("+++++++++++++++PROGRAMA QUE DESPLIEGA EL FACTORIAL DE UN NUMERO++++++++++++++++\n\n");
      printf("Introduce un numero entero\n");
      scanf("%d",&i);
      /*i se guarda en x para desplegarlo al final*/
      x = i;
      /*a temp se le asigna el valor de  i -1 */
      temp = i - 1;
      /*pregunta si 1 es mayor igual que 0,
      porque numeros negativos no tienen factorial*/
      if(i>=0)
      { /*comienza el ciclo y se ejecuta*/
        do
        { /*en i se guarda i * temp (i=5*4)*/
          i *= temp;
          /*se le resta 1 a temp*/
          temp--;
        }/*si temp es mayor o igual que 1 empieza el ciclo de nuevo*/
        while(temp>=1)/*para acabar el while se pone ' ; '   */;
        /*pregunta si i=1 o 1=0 e imprime*/
        if(i==0||i==1)
        printf("El factorial es 1\n");
        /*sino imprime */
        else
        printf("El factorial de %d es: %d\n\n", x, i);
      }
      /*si el numero es menor que 0, imprime*/
      else
      printf("El numero no es valido\n");
      system("pause");
}
