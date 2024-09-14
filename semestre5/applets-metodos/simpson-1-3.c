#include <stdio.h> /*para printf(),scanf()*/
#include <conio.h> /*para getch(),clrscr()*/
#include <stdlib.h>/*para exit()*/
#include <math.h>
//#include <dos.h>
//#define NUMEL 20
double f(double x);
void _error(int n);
enum{INTERVALOS};
enum{SIMPSON1_3=1,SALIR};
int n;
float a,b;
//float X[NUMEL],Fx[NUMEL];

/*Metodo de Simpson 1/3 dada una funcion*/
void Simpson1_3(double a,double b,int n,double *Area)
{
 register int i;
 double x;
 double S0,S1;
 double h;
 h=(b-a)/(2*n);
 S0=S1=0;
 for(i=1;i<=(2*n-1);++i){
   x=a+((double)i)*h;
   if(!(i%2))
   S0+=f(x);
   else
   S1+=f(x);
 }
 *Area=(h*(f(a)+4*S1+2*S0+f(b))/3.0);

  printf("\n El area es -> %5.6f \n\n\n",*Area);
  getch();
}
/*Muestra mensaje de error*/
void _error(int n)
{
  static char *msg[]={
          "Error en los subintervalos",
          ""
         };
  printf("\n %s",msg[n]);
  getch();
}
  /*Funcion a integrar*/
  double f(double x)
 {
   float y;
      y = 1/x;
   return y;
 }

 void LeeDatos(int opc)
{
 if(opc==SIMPSON1_3){
// clrscr();

 putchar('\n');
 printf("\n Numero de intervalos (PAR) -> ");
 }

 scanf("%d",&n);
 if((n<1)||((n%2)!=0)){          //numero de iteraciones menor que 0 o impares
  _error(INTERVALOS);
  exit(1);
 }
 else
  printf("\n Valor de a =>");
  scanf("%f",&a);
  printf("\n Valor de b =>");
  scanf("%f",&b);
}
 /*Muestra el menu en la pantalla*/
 void Menu(char *titulo,char *opciones[])
 {
   int i;
//   clrscr();
   i=0;
//   gotoxy(34,4);
   printf("%s\n\n",titulo);
   for(;*opciones[i];i++)
   printf("\t\t\t\t %d.- %s\n",i+1,opciones[i]);
   printf("\t\t\t\t %d.- Salir\n",i+1);
   putchar('\n');
   printf("\t\t\t\t Opcion: ");
 }
int main(void)
{
  double Area;

  int op;
  char *opciones[]={"Simpson 1/3",

               ""
               };
  do{
 //  clrscr();
   Menu("Metodos de Integracion",opciones);
   scanf("%d",&op);
   switch(op){
    case SIMPSON1_3:    LeeDatos(SIMPSON1_3);
                   Simpson1_3(a,b,n,&Area);
                   break;

    case SALIR:
    //     gotoxy(34,20);
                   printf(" Fin de %s",__FILE__);
//
                   exit(0);
                   break;
    default:
    // gotoxy(34,13);
                   printf("Opcion no permitida. \n\n\n" );
                   getch();
                   break;

   }
  }while(op!=SALIR);

}
