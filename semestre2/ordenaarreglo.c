/*clasifica prog 8-4clasifica.c Ascendente*/
#include <stdio.h>
#include <conio.h>
#define DIMAX 100
void clasif(int arreglo_num[],int tamano);
main(){
int tamreal,k;
/*captura del tamaño del arreglo*/
printf("ingrese el numero de");
printf("\nelementos para clasificar:");
scanf("%d",&tamreal);
int numeros[tamreal];
/*Captura de los elementos*/
for(k=0;k<tamreal;k++){
printf("Elemento #%d=",k+1);
scanf("%d",&numeros[k]);
}
/*llamado a la funcion de clasificacion*/
clasif(numeros,tamreal);
/*impresion de resultados*/
printf("**El arreglo clasificado es:\n");
for(k=0;k<tamreal;k++)
printf("%d\n",numeros[k]);
getche();
return(0);
}
/*Funcion que clasifica en orden ascendente*/
void clasif(int arreglo_num[],int tamano){
int i,j, temporal;
for(i=0;i<tamano-1;i++)
for(j=i+1;j<tamano;j++)
if(arreglo_num[i]>arreglo_num[j]){
temporal=arreglo_num[j];
arreglo_num[j]=arreglo_num[i];
arreglo_num[i]=temporal;
}
}
