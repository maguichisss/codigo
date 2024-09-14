#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
void gauss(float a[][10],float b[][10]);

int Dim,i,j,k,n,w,x,z,K,dat=0;//Dim=# de estados, K=# de decisiones
int DR[10][10],A[15];//matriz de decisiones factibles y array que guarda # de decisiones factibles de un estado
float TRANS[20][20][20],COS[20][20],D[20][20];//matriz de transiciones y costos
int Pol[10][10];// matriz de politicas
float a[10][10],b[10][10];

void inicializar(){
    for(j=0;j<Dim;j++)
        b[1][j+1]=COS[j][Pol[1][j]];
    for(j=0;j<Dim;j++)
        a[j+1][Dim+1]=COS[j][Pol[1][j]];
}

void gauss(float a[10][10],float b[10][10])
{
    int i,j,k,l,m;
    m=Dim;
    l=m;
/*    printf("matriz a\n");
    for(i=1;i<=l;i++){
        for(j=1;j<=m+1;j++)
            printf("%0.4f  ",a[i][j]);
        printf("\n");
    }
*/
    m=l+1;
    for(k=1;k<=l;k++){
        for(j=k;j<=m;j++)
            b[k][j]=((a[k][j])/(a[k][k]));
        for(i=k+1;i<=l;i++)
            for(j=k;j<=m;j++)
                b[i][j]=((-a[i][k])*(b[k][j]))+a[i][j];
        for(i=k;i<=l;i++)
            for(j=k;j<=m;j++)
                a[i][j]=b[i][j];
    }
    for(k=l;k>=1;k--){
        for(i=k-1;i>=1;i--)
            for(j=k;j<=m;j++)
                b[i][j]=((-a[i][k])*(a[k][j]))+a[i][j];
        for(i=1;i<=l;i++)
            for(j=1;j<=m;j++)
                a[i][j]=b[i][j];
    }

    printf("Vector solucion\n");
    for(i=1;i<=l;i++){
        for(j=m;j<=m;j++){
            if(i==l){
                printf("G(R%d)%0.4f  ",n,a[i][j]);
                a[i][j]=0;
            }
            else{
                printf("V%d(R%d)%0.4f  ",i-1,n,a[i][j]);
                printf("\n");
            }
        }
    }
    printf("\n");
}

void mejoramientoPoliticas(float factor){
    int costo;
    n=1;
    for(i=0;i<Dim;i++){
        for(j=0;j<Dim;j++){
            if(i==j){
                if(j==Dim-1)
                    a[i+1][j+1]=0;
                else
                    a[i+1][j+1]=1-(factor * TRANS[i][j][Pol[n][i]]);
            }
            else{
                if(j==Dim-1)
                    a[i+1][j+1]=0;
                else
                    a[i+1][j+1]=-(factor * TRANS[i][j][Pol[n][i]]);
            }
        }
        a[i+1][j]=1;
    }
/*    for(j=1; j<=Dim; j++){
        for(z=1; z<=Dim; z++)
            printf("%f ",a[j][z]);
        printf("\n");
    }
    system("pause");
*/
    gauss(a,b);
    //Paso 2 mejorar la politica
    for(i=0; i<Dim; i++){
        for(j=1; j<=A[i]; j++){
            costo=0; //declaro variable costo
            for(w=0; w<Dim-1; w++)
                costo+= factor * TRANS[i][w][DR[i][j]]*a[w+1][Dim+1];
            D[i][DR[i][j]]=COS[i][DR[i][j]]+costo-a[i+1][Dim+1];
            if(j==1)
                Pol[n+1][i]=DR[i][j];
            else
                if(D[i][DR[i][j]]<D[i][DR[i][j-1]])
            Pol[n+1][i]=DR[i][j];

        }
        //---------------- encuentra el costo mínimo
        // POL[n+1][i]=decision; //en el vector se guarda la decición en el estado "i" para la politica "n+1"
    }//termina primer for

    printf("\nLa politica ( ");
    for(i=0; i<Dim; i++)
        printf("%d ",Pol[n][i]);
    printf(") ");
    n++;
    for(i=0;i<Dim;i++)
        if( Pol[n][i]!=Pol[n-1][i] ){
            printf("NO ES OPTIMA iterara nuevamente\n\n");
            j=0;
            for(j=0;j<Dim;j++)
                Pol[n-1][j]=Pol[n][j];
            mejoramientoPoliticas(factor);
        }
        printf("ES OPTIMA\n");
        system("pause");
        menu();
}

void enumeracionExhaustiva(){
    int b,d,NoCero,Col,C1,C2,A,a,cont;
    float Pivote,V1,x;

    printf("Cuantas politicas relevantes hay\n");
    scanf("%d",&a);
    for(j=0; j<a; j++)
        for(b=0; b<Dim; b++){
                 printf("Cual es la decision en el estado %d para la politica %d\n", b, j+1);
                 scanf("%d",&Pol[j][b]);
        }
    float sistemas[Dim][Dim][a];
    float ecuaciones[Dim][Dim+1][a];

    for(i=0; i<a; i++){
        for(j=0; j<Dim; j++){
             for(b=0; b<Dim; b++){
                  d=Pol[i][b];
                  if(j==Dim-1){
                      sistemas[j][b][i]=1;
                      ecuaciones[j][b][i]=1;
                  }
                  else if(j==b){
                       sistemas[j][b][i]=1-TRANS[b][j][d];
                       ecuaciones[j][b][i]=1-TRANS[b][j][d];
                  }
                  else{
                      sistemas[j][b][i]=-TRANS[b][j][d];
                      ecuaciones[j][b][i]=-TRANS[b][j][d];
                  }
             }
             if(j != Dim-1)
                ecuaciones[j][Dim][i]=0;
             else
                ecuaciones[j][Dim][i]=1;
        }
    }

    for(i=0; i<a; i++){
        for(Col=0;Col<Dim;Col++){
                NoCero=0;A=Col;
                while(NoCero==0){
                      if(ecuaciones[A][Col][i]!=0)
                        NoCero=1;
                      else
                        A++;
                }
                Pivote=ecuaciones[A][Col][i];
                for(C1=0;C1<=Dim;C1++){
                   V1=ecuaciones[A][C1][i];
                   ecuaciones[A][C1][i]=ecuaciones[Col][C1][i];
                   ecuaciones[Col][C1][i]=V1/Pivote;
                   //printf("%f   %f   %f   \n", ecuaciones[Col][C1][i], V1, Pivote);
                }
                for(C2=Col+1;C2<Dim;C2++){
                   V1=ecuaciones[C2][Col][i];
                   for(C1=Col;C1<=Dim;C1++)
                        ecuaciones[C2][C1][i]=ecuaciones[C2][C1][i]-V1*ecuaciones[Col][C1][i];
                }
        }

        for(Col=Dim-1;Col>=0;Col--)
            for(C1=(Col-1);C1>=0;C1--){
                ecuaciones[C1][Dim][i]=ecuaciones[C1][Dim][i]-ecuaciones[C1][Col][i]*ecuaciones[Col][Dim][i];
                ecuaciones[C1][Col][i]=0;
            }
    }

    float soluciones[Dim][a];
    for(i=0; i<a; i++)
        for(j=0; j<Dim; j++)
            soluciones[i][j]=ecuaciones[j][Dim][i];

    float total[a];

    for(i=0; i<a; i++)
        for(j=0; j<Dim; j++)
            soluciones[i][j]=ecuaciones[j][Dim][i];

    float resultado[a];
    int aux;

    for(i=0; i<a; i++){
        resultado[i]=0;
        for(j=0; j<Dim; j++){
             aux=Pol[i][j];
             resultado[i]+=soluciones[i][j]*COS[j][aux];
             //printf("%f=+%f*%f\n",resultado[i],soluciones[i][j],COS[j][aux-1]);
        }
    }

    x=resultado[0];
    cont=0;
    for(i=1; i<a; i++){
        if(x>resultado[i]){
             cont=i;
             x=resultado[i];
        }
    }

    printf("\n\n\nLa politica OPTIMA es la %d\n\n( ", cont+1);
    for(i=0; i<Dim; i++)
        printf("%d ", Pol[cont][i]);
    printf(")\n\nCon un costo de: %f\n\n", x);
    system("pause");

}


float minimo(float arreglo[]){
    int i;
    float mini;
    mini=arreglo[1];
    for(i=2;i<=K;i++)
        if(arreglo[i]<mini)
            mini=arreglo[i];
    return mini;
}

int poliO(float aux[Dim], float mini){
    int i=0;
    while(aux[i]!=mini){
        i++;
    }
    return i;
}
int todosPositivos(float arreglo[Dim], float error){
    int i;
    for(i=0;i<Dim;i++)
        if(arreglo[i]>=error)
            return 0;
    return 1;
}

void aproximacionesSucesivas(){
    float alfa, error;
    printf("\t\t\t+++APROXIMACIONES SUCESIVAS+++\n\n");
    printf("Cual es el valor de alfa: ");
    scanf("%f",&alfa);
    printf("Cual es el valor del error: ");
    scanf("%f",&error);
    int iteracion=0,poliOpt[Dim],x=K;
    float V[Dim][2], sumatoria, aux[K+1], Verror[Dim];

    do{
        //printf("\nIteracion %d\n", iteracion);
        if(iteracion==0)
            for(i=0;i<Dim;i++){
                V[i][1]=minimo(COS[i]);
                V[i][0]=0;
                //printf("   %f",V[i][1]);
            }
        else{
            for(j=0; j<Dim; j++){
                for(i=1; i<=K; i++){
                    sumatoria=0;
                    for(z=0; z<Dim; z++)
                        sumatoria+=TRANS[j][z][i]*V[z][0];
                    if(COS[j][i]==999999)
                        aux[i]=999999;
                    else
                        aux[i]=COS[j][i]+alfa*sumatoria;
                }
                V[j][1]=minimo(aux);
                //printf("(%.4f)  %.4f  %.4f  %.4f  %.4f\n",V[i][1],aux[0],aux[1],aux[2],aux[3]);
                poliOpt[j]=poliO(aux, V[j][1]);
              //  printf("   %f",V[j][1]);
            }
        }
        for(i=0;i<Dim;i++){
            Verror[i]=fabs(V[i][1]-V[i][0]);
            V[i][0]=V[i][1];
        }
        iteracion++;
    }while(!todosPositivos(Verror, error));
    printf("\nLa politica optima es: ( ");
    for(i=0;i<Dim;i++)
        printf("%d ",poliOpt[i]);
    printf(") en %d iteraciones\n",iteracion);
    system("pause");
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

    printf("Politica arbitraria:  ");
    for(i=0; i<Dim; i++){
        Pol[1][i]=DR[i][1];
        printf("%d  ",Pol[1][i]);
    }
    printf("\n");

    system("pause");

    printf("\n\n\t\t\t+++COSTOS+++\n\n");
    for(i=0; i<Dim; i++)
        for(j=1; j<=K; j++)
            COS[i][j]=999999;

    for(i=0; i<Dim; i++){
        printf("\nCostos para el estado %d\n",i);
        for(j=1; j<=A[i]; j++){
            printf("COS[%d][%d] =  ",i,DR[i][j]);
            scanf("%f",&COS[i][DR[i][j]]);
        }
    }

    printf("COSTOS\n");
    for(i=0; i<Dim; i++){
        printf("Costos para el estado %d  |  ",i);
        for(j=1; j<=A[i]; j++)
            printf("%f  ",COS[i][DR[i][j]]);
        printf("\n");
    }
    printf("Matriz \n");
    for(i=0;i<Dim;i++){
        for(j=0;j<=K;j++)
            printf("%f  ",COS[i][j]);
        printf("\n");
    }

    system("pause");

    for(j=0;j<Dim;j++)
        b[1][j+1]=COS[j][Pol[1][j]];
    for(j=0;j<Dim;j++)
        a[j+1][Dim+1]=COS[j][Pol[1][j]];


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
        printf("DECISION %d\n",i);
        for(j=0; j<Dim; j++){
            for(z=0; z<Dim; z++)
                printf("  %f\t",TRANS[j][z][i]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 1;
}

void portada()
{
     printf("\n\n\n\n");
     printf("\tFacultad de Estudios Superiores Acatlan  -  UNAM\n");
     printf("\t\tMatematicas Aplicadas y Computacion");
     printf("\n\n");
     printf("\t\tProcesos Estocasticos  -  2602\n\n");
     printf("\t\tArellanes Rios Efrain\n");
     printf("\t\tChavez Rodriguez Carla Gabriela\n");
     printf("\t\tEspindola Borromeo Jessica Mariana\n");
     printf("\t\tGarces Brito Mauricio I.\n");
     printf("\t\t\n");
     printf("\t\t\n");
     printf("\t\tMayo 2013\n");
     printf("\n\n\n\n");
     system("pause");
}

void menu(){
    int continuar=0;
    float factor;
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
                    enumeracionExhaustiva();
                else{
                    printf("PRIMERO DEBES LLENAR LOS DATOS...\n");
                    system("pause");
                }
                break;

            case '3':
                //porPogramacionLineal();
                break;

            case '4':
                factor=1;
                inicializar();
                if(dat)
                    mejoramientoPoliticas(factor);
                else{
                    printf("PRIMERO DEBES LLENAR LOS DATOS...\n");
                    system("pause");
                }
                break;

            case '5':
                printf("Dar el factor de descuento\n");
                scanf("%f",&factor);
                inicializar();
                if(dat)
                    mejoramientoPoliticas(factor);
                else{
                    printf("PRIMERO DEBES LLENAR LOS DATOS...\n");
                    system("pause");
                }
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

}

int main(){
    portada();
    menu();
    return 0;
}
