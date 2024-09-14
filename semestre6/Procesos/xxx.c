#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

int Dim=4,i,j,k,x,z,K;//Dim=# de estados, K=# de decisiones
int DR[4][3]={1,0,0,  1,3,0,  1,2,3,  3,0,0};
int A[4]={1,2,3,1};
float TRANS[20][20][20],COS[20][20];//matriz de transiciones y costos
int Pol[10][10];// matriz de politicas
float a[10][10];

void politicasPosibles(){
    for(i=0;i<Dim-1;i++){
        for(j=0;j<A[i];j++){
            printf("(%d) ",DR[i][j]);
            for(k=i+1;k<Dim;k++){
                for(x=0;x<A[k];x++)
                printf("(%d) ",DR[k][x]);
            }
            printf("\n");
        }
    }
    printf("\nhola\n");
    system("pause");
}

otraPrueba(){
    printf("\n\n\t\t\t+++COSTOS+++\n\n");
    for(i=0; i<Dim; i++){
        printf("\nCostos para el estado %d\n",i);
        for(j=1; j<=A[i]; j++){
            printf("COS[%d][%d] =  ",i,DR[i][j]);
            scanf("%f",&COS[i][DR[i][j]]);
        }
    }

    printf("COSTOS \n");
    for(i=0; i<Dim; i++){
        printf("Costos para el estado %d  |  \n",i);
        for(j=1; j<=A[i]; j++)
            printf("%f  ",COS[i][DR[i][j]]);
        printf("\n");
    }


    printf("\n\nAQUI LA PRUEBA\n\n");
    for(i=0;i<Dim;i++)
        for(j=0;j<Dim;j++)
            printf("%f  ",COS[i][j]);
    system("pause");

}

int main(){

    otraPrueba();

    return 0;
}
