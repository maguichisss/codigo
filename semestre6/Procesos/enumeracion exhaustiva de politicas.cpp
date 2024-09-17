/*     Programa elaborado por
  Espíndola Borromeo Jessica Mariana
    
            Grupo:2602  
        Procesos estocasticos        */

#include<conio.h>      
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

main() 
{
       int i, j, k, a, b, Dim;
       float x;
       printf("Cual es el numero de estados? ");
       scanf("%d",&Dim);
       printf("Cuantas decisiones hay? ");
       scanf("%d",&k);
       float transicion[Dim][Dim][k];
       
       for(i=0; i<Dim; i++)
       {
                for(j=0; j<Dim; j++)
                {
                         for(b=0; b<k; b++)
                         {
                                  printf("Cual es la probabilidad de transicion del estado %d al %d tomando la decision %d\n", i, j, b+1);
                                  scanf("%f",&transicion[i][j][b]);
                         }
                }
       }   
      
       int costos[Dim][k];
       for(j=0; j<Dim; j++)
       {
                for(b=0; b<k; b++)
                {
                         printf("Cual es el costo de estar en el estado %d y tomar la decision %d\n", j, b+1);
                         scanf("%d",&costos[j][b]);
                }
       }      
       
       printf("Cuantas politicas relevantes hay\n");
       scanf("%d",&a);
       int politicas[a][Dim];
       for(j=0; j<a; j++)
       {
                for(b=0; b<Dim; b++)
                {
                         printf("Cual es la decision en el estado %d para la politica %d\n", b, j+1);
                         scanf("%d",&politicas[j][b]);
                }
       }
       
       int d;
       float sistemas[Dim][Dim][a];
       float ecuaciones[Dim][Dim+1][a];
       
       for(i=0; i<a; i++)
       {
                for(j=0; j<Dim; j++)
                {
                         for(b=0; b<Dim; b++)
                         {
                              d=politicas[i][b]-1;
                              if(j==Dim-1)
                              {
                                      sistemas[j][b][i]=1;
                                      ecuaciones[j][b][i]=1; 
                              }
                              else if(j==b)
                              {
                                           sistemas[j][b][i]=1-transicion[b][j][d];
                                           ecuaciones[j][b][i]=1-transicion[b][j][d];
                              }
                              else
                              {
                                  sistemas[j][b][i]=-transicion[b][j][d];
                                  ecuaciones[j][b][i]=-transicion[b][j][d];
                              }
                         }
                         if(j != Dim-1)
                         {
                              ecuaciones[j][Dim][i]=0;
                         }
                         else
                         ecuaciones[j][Dim][i]=1;
                }
       }
/*
printf("////////////////////////////////////////////////////////\n\n");
for(b=0; b<a; b++)
       {
                for(j=0; j<Dim; j++)
                {
                     for(i=0; i<=Dim; i++)
                     {
                         printf("%f   ", ecuaciones[j][i][b]);
                     }
                     printf("\n");
                }
                printf("\n\n");
       }*/
//int C,Dimension;
//float Sistema[101][102];

        int NoCero,Col,C1,C2,A;
        float Pivote,V1;
        
    for(i=0; i<a; i++)
    {    
        for(Col=0;Col<Dim;Col++)
        {
                NoCero=0;A=Col;
                while(NoCero==0)
                {
                      if(ecuaciones[A][Col][i]!=0)
                      {
                          NoCero=1;
                      }
                      else A++;
                }    
                Pivote=ecuaciones[A][Col][i];
                for(C1=0;C1<=Dim;C1++)
                {
                       V1=ecuaciones[A][C1][i];
                       ecuaciones[A][C1][i]=ecuaciones[Col][C1][i];
                       ecuaciones[Col][C1][i]=V1/Pivote;
                       //printf("%f   %f   %f   \n", ecuaciones[Col][C1][i], V1, Pivote);
                       
                }
                for(C2=Col+1;C2<Dim;C2++)
                {
                       V1=ecuaciones[C2][Col][i];
                       for(C1=Col;C1<=Dim;C1++)
                       {
                               ecuaciones[C2][C1][i]=ecuaciones[C2][C1][i]-V1*ecuaciones[Col][C1][i];
                       }
                }
        }
    
        for(Col=Dim-1;Col>=0;Col--) 
        for(C1=(Col-1);C1>=0;C1--)
        {
                ecuaciones[C1][Dim][i]=ecuaciones[C1][Dim][i]-ecuaciones[C1][Col][i]*ecuaciones[Col][Dim][i];
                ecuaciones[C1][Col][i]=0;
        }
    }
    
    float soluciones[Dim][a];
    
     for(i=0; i<a; i++)
     {
                for(j=0; j<Dim; j++)
                {
                         soluciones[i][j]=ecuaciones[j][Dim][i];
                }
     }
     
     float total[a];
     
     for(i=0; i<a; i++)
     {
                for(j=0; j<Dim; j++)
                {
                         soluciones[i][j]=ecuaciones[j][Dim][i];
                }
     }
     
     float resultado[a];
     int aux;
     
      for(i=0; i<a; i++)
     {
               resultado[i]=0;
                for(j=0; j<Dim; j++)
                {
                         aux=politicas[i][j];
                         resultado[i]+=soluciones[i][j]*costos[j][aux-1];
                         //printf("%f=+%f*%f\n",resultado[i],soluciones[i][j],costos[j][aux-1]);
                }
     }
     
     int cont;
     
     x=resultado[0];
     cont=0;
     for(i=1; i<a; i++)
     {
                if(x>resultado[i])
                {
                         cont=i;
                         x=resultado[i];
                }
     }
     
     printf("La politica optima es la %d\n\n( ", cont+1);
     for(i=0; i<Dim; i++)
     {
          printf("%d ", politicas[cont][i]);
     }
     printf(")\n\nCon un costo de: %f", x);
       
 /*      printf("////////////////////////////////////////////////////////\n\n");
for(b=0; b<a; b++)
       {
                for(j=0; j<Dim; j++)
                {
                     for(i=0; i<=Dim; i++)
                     {
                         printf("%f   ", ecuaciones[j][i][b]);
                     }
                     printf("\n");
                }
                printf("\n\n");
       }
    
       printf("////////////////////////////////////////////////////////\n\n");
       for(i=0; i<a; i++)
       {
                printf("[ ");
                for(j=0; j<Dim; j++)
                {
                         printf("%f   ", soluciones[i][j]);
                }
                printf("]\n");
       }
       printf("\n\n");
 */      
    
    
    system("pause");
           getch();
  /* portada();
   etik:
   system("cls");
   switch(menu()) 
   { 
      case 1:
           system("cls");
      break;
      case 2:
           system("cls");
           switch(menu()) 
           { 
              case 1: 
                   enum();
              break;
              case 2:
                   pl();
              break;
              case 3: 
                   enum();
              break;
              case 4:
                   pl();
              break;
              case 5:
                   pl();
              break;
           }
      break;
    }
    printf("\n\n\t\t\tPresione para regresar al menu principal");
    getch();
    goto etik; */
}
/*
void portada()
{
     printf("\n\n\n\n\n");
     printf("\t\tFacultad de Estudios Superiores Acatlan  -  UNAM\n");
     printf("\t\t\tMatematicas Aplicadas y Computacion");
     printf("\n\n");
     printf("\t\t\tProcesos Estocasticos  -  2602\n\n");
     printf("\t\t\tEsp%cndola Borromeo Jessica Mariana\n",161);
     printf("\t\t\t\n",130);
     printf("\t\t\t\n",160,160);
     printf("\t\t\t\n");
     printf("\n\n\n\n\t\t\t");
     system("pause");
}

int menu() 
{ 
   do{ 
   printf("Resolver por:\n"); 
   printf("\n1.-Enumeracion exhaustiva de politicas.\n"); 
   printf("\n2.-Por programacion lineal.\n"); 
   printf("\n3.-Mejoramiento de politicas.\n"); 
   printf("\n4.-Mejoramiento de politicas con descuento.\n"); 
   scanf("%d",&op); 
   }
   while (op < 1 || op > 4); 
   return op; 
} 



int colas()
{  
   do{ 
   printf("Opciones:\n"); 
   printf("\n1.-Colas.\n"); 
   printf("\n2.-Bicolas.\n"); 
   printf("\n3.-Colas con prioridad.\n");
   scanf("%d",&op);
   }
   while (op<1 || op>3); 
   return op;
}*/


/*
void ResuelveGauss(int Dim, float sistema[][102])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
    
    for(Col=1;Col<=Dim;Col++)
    {
        NoCero=0;A=Col;
        while(NoCero==0)
        {
            if(sistema[A][Col]!=0)
            {
                NoCero=1;
            }
            else A++;
        }
        Pivote=sistema[A][Col];
        for(C1=1;C1<=(Dim+1);C1++)
        {
            V1=sistema[A][C1];
            sistema[A][C1]=sistema[Col][C1];
            sistema[Col][C1]=V1/Pivote;
        }
        for(C2=Col+1;C2<=Dim;C2++)
        {
            V1=sistema[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++)
            {
                sistema[C2][C1]=sistema[C2][C1]-V1*sistema[Col][C1];
            }
        }
    }
    
    for(Col=Dim;Col>=1;Col--) 
    for(C1=(Col-1);C1>=1;C1--)
    {
        sistema[C1][Dim+1]=sistema[C1][Dim+1]-sistema[C1][Col]*sistema[Col][Dim+1];
        sistema[C1][Col]=0;
    }
}
*/
