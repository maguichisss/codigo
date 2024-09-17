#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
const float alfa=0.9, error=20;
const int edos=4, dec=3, pol=4;
float trans[edos][edos][dec]={0,0,0,  .875,0,0,  .0625,0,0,  .0656,0,0,  0,0,1,  .75,0,0,  .125,0,0,  .125,0,0,  0,0,1,  0,1,0,  .5,0,0,  .5,0,0,  0,0,1,  0,0,0,  0,0,0,  1,0,0};
float costos[edos][dec]={0,999999,999999,       1000,999999,6000,       3000,4000,6000,     999999,999999,6000};
int politicas[pol][edos]={1,1,1,3,  1,1,2,3,  1,1,3,3,  1,3,3,3};

float minimo(float arreglo[]){
    int i,mini;
    mini=arreglo[0];
    for(i=0;i<dec;i++)
        if(arreglo[i]<mini)
            mini=arreglo[i];
    return mini;
}

int todosPositivos(float arreglo[edos][2]){
    int i;
    for(i=0;i<edos;i++)
        if(arreglo[i][0]>=error)
            return 0;
    return 1;
}

float sumatoria(){
    int i,j,k;
    float aux[dec];

}

main(){
    int i,j,k,iteracion=0;
    float V[edos][2], Vsuma[edos][dec];

    do{
        if(iteracion==0)
            for(i=0;i<edos;i++){
                V[i][1]=minimo(costos[i]);
                V[i][0]=0;
            }
        else{
            for(){
                for(){
                    for(){

                        V[i][1]=minimo();
                    }
                }
            }
        }
        for(i=0;i<edos;i++)
            V[i][0]=fabs(V[i][1]-V[i][0]);
        iteracion++;
    }while(!todosPositivos(V));

}
