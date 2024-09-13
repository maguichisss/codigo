#include<iostream>
using namespace std;

main()
{
int i,j,k,l,m,n ;
float a[100][100];
float det;
cout << "Introducir el ORDEN DE LA MATRIZ : N = " << endl;
cin >> n;
m=n-1;
/* Vamos a introducir la matriz por teclado*/

cout << "Introducir los elementos" << endl;
cout << "------------------------" << endl;;
for(i=1;i<=n;i++)
{ for(j=1;j<=n;j++)
{cin >> a[i][j];}}
/* SI QUEREMOS LEER LOS ELEMENTOS DE LA MATRIZ LISTADOS */

/*for(i=1;i<=n;i++)
{ for(j=1;j<=n;j++)
printf("\t\t\tA(%d,%d) =%8.4f\n",i,j,a[i][j] ); }*/

/*****Calculo del DETERMINANTE*****/
det=a[1][1];
for(k=1;k<=m;k++)
{ l=k+1;
for(i=l;i<=n;i++)
{ for(j=l;j<=n;j++)
a[i][j] = ( a[k][k]*a[i][j]-a[k][j]*a[i][k] )/a[k][k]; }
det=det*a[k+1][k+1];
}
cout << endl;
cout << "DETERMINANTE = " << det << endl;
cout << "------------------------" << endl;

system("PAUSE");

return 0;
}
