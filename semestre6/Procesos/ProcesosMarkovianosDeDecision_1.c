#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
void gauss(float a[][10],float b[][10]);

int Dim,i,j,k,z,K;//Dim=# de estados, K=# de decisiones
int DR[10][10],A[15];//matriz de decisiones factibles y array que guarda # de decisiones factibles de un estado
float TRANS[20][20][20],COS[20][20];//matriz de transiciones y costos
int Pol[10][10];// matriz de politicas
float a[10][10];

float minimo(float arreglo[]){
    int i;
    float mini;
    mini=arreglo[0];
    for(i=0;i<K;i++)
        if(arreglo[i]<mini)
            mini=arreglo[i];
    return mini;
}

int poliO(float aux[Dim], float min){
    int i=0;
    while(aux[i]!=min){
        i++;
    }
    return i+1;
}
int todosPositivos(float arreglo[Dim], float error){
    int i;
    for(i=0;i<Dim;i++)
        if(arreglo[i]>=error)
            return 0;
    return 1;
}

void aproximacionesSucesivas(){
    float alfa=1, error=1;
    printf("\t\t\t+++APROXIMACIONES SUCESIVAS+++\n\n");
    printf("Cual es el valor de alfa: ");
    scanf("%f",&alfa);
    printf("Cual es el valor del error: ");
    scanf("%f",&error);
    int iteracion=0,poliOpt[Dim],x;
    float V[Dim][2], sumatoria, aux[K], Verror[Dim];

    do{
        printf("\nIteracion %d\t\n", iteracion);
        if(iteracion==0)
            for(i=0;i<Dim;i++){
                V[i][1]=minimo(COS[i]);
                V[i][0]=0;
                printf("%f\t",V[i][1]);
            }
        else{
            for(i=0;i<Dim;i++){
                for(k=0;k<K;k++){
                    sumatoria=0;
                    x=1
                    for(j=0;j<Dim;j++){
                        sumatoria+=TRANS[i][j][k]*V[j][0];
                    }
                    if(x<=A[i] &&)
                            COS[i][DR[i][j]];
                    if(!COS[i][k])
                        aux[k]=999999;
                    else
                        aux[k]=COS[i][k]+alfa*sumatoria;
                    x++;
                }

                V[i][1]=minimo(aux);
               // printf("(%f)\t%f\t%f\t%f\t%f\n",V[i][1],aux[0],aux[1],aux[2],aux[3]);
               poliOpt[i]=poliO(aux, V[i][1]);
                printf("%f\t",V[i][1]);
            }
        }
        for(i=0;i<Dim;i++){
            Verror[i]=fabs(V[i][1]-V[i][0]);
            V[i][0]=V[i][1];
        }
        iteracion++;
    }while(!todosPositivos(Verror, error));
    printf("\nLa politica optima es: (");
    for(i=0;i<Dim;i++)
        printf("%d ",poliOpt[i]);
    printf(") en %d iteraciones",iteracion);

}

int datos(){
    printf("\t\t\t+++ESTADOS Y DECISIONES+++\n\n");
    printf("Cuantos estados existen: ");
    scanf("%d",&Dim);
    printf("Cuantas decisiones existen: ");
    scanf("%d",&K);
    printf("\n\n\t\t\t+++DECISIONES RELEVANTES+++\n\n");

    for(i=0; i<Dim; i++){
         printf("\nCUANTAS DECISIONES FACTIBLES EXISTEN PARA EL ESTADO %d:  ",i);
         //z=1;//falta validar que no pase de las decisiones factibles
         scanf("%d",&z);
         printf("Cuales son las decisiones para el estado %d:  ",i);
         for(j=1; j<=z; j++)
            scanf("%d",&DR[i][j]);
         A[i]=z;
    }

    for(i=0; i<Dim; i++){
        printf("Estado = %d  |  ",i);
        for(j=1; j<=A[i]; j++)
            printf("%d  ",DR[i][j]);
        printf("\n");
    }
    system("pause");

    printf("Politica arbitraria:\n");
    for(i=0; i<Dim; i++){
        Pol[1][i]=DR[i][1];
        printf("%d  ",Pol[1][i]);
    }

    system("pause");

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

    system("pause");

    float b[10][10];
    for(j=0;j<Dim;j++)
        b[1][j+1]=COS[j][Pol[1][j]];

    for(j=0;j<Dim;j++)
        printf("%f ", b[1][j+1]);

    system("pause");

    printf("\n\n\t\t\t+++PROBABILIDADES DE TRANSICION+++\n\n");
    for(i=1; i<=K; i++){
        printf("\nPROBABILIDADES PARA LA DECISION  %d\n",i);
        for(j=0; j<Dim; j++)
            for(z=0; z<Dim; z++){
                printf("DE [%d] A [%d] =  ",j,z);
                scanf("%f",&TRANS[j][z][i]);
            }
    }

    printf("PROBABILIDADES DE TRANSICION \n");
    for(i=1; i<=K; i++){
        printf("PROBABILIDADES DE TRANSICION  PARA LA DECISION %d\n",i);
        for(j=0; j<Dim; j++)
            for(z=0; z<Dim; z++)
                printf("  %f\t",j,z,TRANS[j][z][i]);
    }
    system("pause");
    return 1;
}

void portada()
{
     printf("\n\n\n\n\n");
     printf("\t\tFacultad de Estudios Superiores Acatlan  -  UNAM\n");
     printf("\t\t\tMatematicas Aplicadas y Computacion");
     printf("\n\n");
     printf("\t\t\tProcesos Estocasticos  -  2602\n\n");
     printf("\t\t\tArellanes Rios Efrain\n");
     printf("\t\t\tChavez Rodriguez Carla Gabriela\n");
     printf("\t\t\tEspindola Borromeo Jessica Mariana\n");
     printf("\t\t\tGarces Brito Mauricio I.\n");
     printf("\t\t\t\n");
     printf("\t\t\t\n");
     printf("\t\t\tMayo 2013\n");
     printf("\n\n\n\n\t\t\t");
     system("pause");
}

int main(){
    int continuar=0, dat=0;
    portada();
    do{
        system("cls");
        printf("\n\n\t\t\t++Procesos Markovianos de Decision++\n\n");
        printf("\n1.- Introducir datos");
        printf("\n2.- Enumeracion Exhaustiva de Politicas");
        printf("\n3.- Por Programacion Lineal");
        printf("\n4.- Mejoramiento de Politicas");
        printf("\n5.- Mejoramiento de Politicas con Descuento");
        printf("\n6.- Aproximaciones Sucesivas");
        printf("\n7.- Salir");
        printf("\n\nElige una opcion: ");
        scanf("%s",&continuar);
        system("cls");
        fflush(stdin);
        switch(continuar)
        {
            case '1':

                dat=datos();
                break;

            case '2':
                if(dat)
                    exit(1);//
                else{
                    printf("PRIMERO DEBES LLENAR LOS DATOS...\n");
                    system("pause");
                }

                break;

            case '3':

                break;

            case '4':

                break;

            case '5':

                break;

            case '6':
                if(dat)
                    aproximacionesSucesivas();
                else{
                    printf("PRIMERO DEBES LLENAR LOS DATOS...\n");
                    system("pause");
                }
                break;

            case '7':
                printf("HASTA LUEGO :D");
                exit(1);
                break;

            default:
                printf("ELIGE UNA OPCION CORRECTA...\n");
                system("pause");
        }

    }while(continuar!=7);

    return 0;
}
