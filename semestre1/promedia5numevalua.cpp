//programa que en el que introduces 5 calificaciones, las promedia y dice si la calificacion es aprobatoria
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int main()
{ float cal1,cal2,cal3,cal4,cal5;
  float suma,promedio;
  printf("Escribe 5 calificaciones \n");
  printf("\nPrimera:  ");
  cin>>cal1;
  printf("\nSegunda:  ");
  cin>>cal2;
  printf("\nTercera:  ");
  cin>>cal3;
  printf("\nCuarta:  ");
  cin>>cal4;
  printf("\nQuinta:  ");
  cin>>cal5;
  cout<<endl;
  suma=cal1+cal2+cal3+cal4+cal5;
  promedio=suma/5;
  if(promedio>=6)
    {printf("Pasasteeee!!! sacaste: %d",suma);}
  else
    {printf("Nee no pasaste, rebuey");}
  getch();
}
