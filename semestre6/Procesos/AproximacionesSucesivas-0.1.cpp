#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
const double alfa=0.9, error=2000;
const int edos=4, dec=3, pol=4;
double trans[edos][edos][dec]={0,0,0,  .875,0,0,  .0625,0,0,  .0625,0,0,  0,0,1,  .75,0,0,  .125,0,0,  .125,0,0,  0,0,1,  0,1,0,  .5,0,0,  .5,0,0,  0,0,1,  0,0,0,  0,0,0,  1,0,0};
double costos[edos][dec]={0,999999,999999,       1000,999999,6000,       3000,4000,6000,     999999,999999,6000};
int politicas[pol][edos]={1,1,1,3,  1,1,2,3,  1,1,3,3,  1,3,3,3};

double minimo(double arreglo[]){
    int i;
    double mini;
    mini=arreglo[0];
    for(i=0;i<dec;i++)
        if(arreglo[i]<mini)
            mini=arreglo[i];
    return mini;
}

int poliO(double aux[edos], double min){
    int i=0;
    while(aux[i]!=min){
        i++;
    }
    return i+1;
}
int todosPositivos(double arreglo[edos]){
    int i;
    for(i=0;i<edos;i++)
        if(arreglo[i]>=error)
            return 0;
    return 1;
}

main(){
    int i,j,k,iteracion=0,poliOpt[edos];
    double V[edos][2], sumatoria, aux[dec], Verror[edos];

    do{
        printf("\nIteracion %d\t\n", iteracion);
        if(iteracion==0)
            for(i=0;i<edos;i++){
                V[i][1]=minimo(costos[i]);
                V[i][0]=0;
                printf("%f\t",V[i][1]);
            }
        else{
            for(i=0;i<edos;i++){
                for(k=0;k<dec;k++){
                    sumatoria=0;
                    for(j=0;j<edos;j++){
                        sumatoria+=trans[i][j][k]*V[j][0];
                    }
                    if(costos[i][k]==999999)
                        aux[k]=999999;
                    else
                        aux[k]=costos[i][k]+alfa*sumatoria;
                }

                V[i][1]=minimo(aux);
               // printf("(%f)\t%f\t%f\t%f\t%f\n",V[i][1],aux[0],aux[1],aux[2],aux[3]);
               poliOpt[i]=poliO(aux, V[i][1]);
                printf("%f\t",V[i][1]);
            }
        }
        for(i=0;i<edos;i++){
            Verror[i]=fabs(V[i][1]-V[i][0]);
            V[i][0]=V[i][1];
        }
        iteracion++;
    }while(!todosPositivos(Verror));
    printf("\nLa politica optima es: (");
    for(i=0;i<edos;i++)
        printf("%d ",poliOpt[i]);
    printf(") en %d iteraciones",iteracion);
}
