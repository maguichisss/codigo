#include<stdio.h>
#include<stdlib.h>
main()
{
      int num1,num2,num3,num4,num5;
      float sum, prom;
      printf("Escribe 5 numeros entre 0 y 9\n");
      scanf("%d %d %d %d %d",&num1,&num2,&num3,&num4,&num5);
      /*printf("Escribe un segundo numero entre 0 y 9\n");
      scanf("%d",&num2);
      printf("Escribe un tercer numero entre 0 y 9\n");
      scanf("%d",&num3);
      printf("Escribe un cuarto numero entre 0 y 9\n");
      scanf("%d",&num4);
      printf("Escribe un quinto numero entre 0 y 9\n");
      scanf("%d",&num5);*/
      sum=num1+num2+num3+num4+num5;
      prom=sum/5;
      printf("El promedio es: %.2f\n",prom);
      system("pause");
}
