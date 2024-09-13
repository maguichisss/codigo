#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,i,j,k,cont,iter;
float mat[10][10],l[10][10];
float iwal[10],xs[10],xspg[10];

guardad()
{
    char ruta[]="cholesky.txt";
    FILE *guardad;
    guardad=fopen(ruta,"w");
    if(guardad==NULL)
    {
        printf("\nEl archivo no pudo ser creado\n");
        exit(1);
    }
    fprintf(guardad,"Matriz simetrica\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            fprintf(guardad," %f ",mat[i][j]);
        fprintf(guardad,"= %f\n",iwal[i]);
    }
    fprintf(guardad,"\n\n");
    fprintf(guardad,"Matriz L\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            fprintf(guardad," %f ",l[i][j]);
        fprintf(guardad,"= %f\n", xspg[i]);
    }
    fprintf(guardad,"\n\n"); 
    fprintf(guardad,"Matriz Lt\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            fprintf(guardad," %f ",l[j][i]);
        fprintf(guardad," = %f\n",xs[i]);
    }
    fprintf(guardad,"\n\n");
    fclose(guardad);
    printf("\n\nGuardado con exito!!!\n\n");
    system("pause");
}

metodo()
{
    float aux1[n][n],aux=0;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            l[i][j]=0;
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",mat[i][j]);
        printf("= %f\n",iwal[i]);
    }
    //1ª columna
    l[0][0]=sqrt(mat[0][0]);
    for(i=0; i<n; i++)
        if(i>0)
            l[i][0]=mat[i][0]/l[0][0];  
    //2ª columna
    l[1][1]=sqrt(mat[1][1]-pow(l[1][0],2));
    for(i=0; i<n; i++)
        if(i>1)
            l[i][1]=(mat[i][1]-l[1][0]*l[i][0])/l[1][1]; 
    //3ª columna   
    l[2][2]=sqrt(mat[2][2]-pow(l[2][1],2)-pow(l[2][0],2));
    for(i=0; i<n; i++)
        if(i>2)
            l[i][2]=(mat[i][2]-l[2][0]*l[i][0]-l[2][1]*l[i][1])/l[2][2];
    //4ª columna
    l[3][3]=sqrt(mat[3][3]-pow(l[3][0],2)-pow(l[3][1],2)-pow(l[3][2],2));
    //Sustitucion hacia adelante
    xs[0]=( iwal[0] /  l[0][0]);
    xs[1]=( iwal[1] - (l[1][0] * xs[0]) ) / l[1][1];
    xs[2]=( iwal[2] - (l[2][0] * xs[0]) - (l[2][1] * xs[1]) )/ l[2][2] ;
    xs[3]=( iwal[3] - (l[3][0] * xs[0]) - (l[3][1] * xs[1]) - (l[3][2] * xs[2]) ) / l[3][3]  ;
    //Imprime matriz L con primeras X de la sustitucion hacia adelante
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",l[i][j]);
        printf("= %f\n",xs[i]);
        xspg[i]=xs[i];
    }
    printf("\n\n");
    //Sustitucion hacia atras
    xs[n-1]=( xs[n-1] /  l[n-1][n-1]);
    xs[n-2]=( xs[n-2] - (l[n-1][n-2]* xs[n-1]) ) / l[n-2][n-2];
    xs[n-3]=( xs[n-3] - (l[n-1][n-3]* xs[n-1]) - (l[n-2][n-3] * xs[n-2]) ) / l[n-3][n-3];
    xs[n-4]=( xs[n-4] - (l[n-1][n-4]* xs[n-1]) - (l[n-2][n-4] * xs[n-2]) - (l[n-3][n-4] * xs[n-3])  ) / l[n-4][n-4];
/*    if(n<=3)
    {
        xs[2]=( xs[2] /  l[2][2]);
        xs[1]=( xs[1] - (l[2][1] * xs[2]) ) / l[1][1];
        xs[0]=( xs[0] - (l[2][0] * xs[2]) - (l[1][0] * xs[1])  ) / l[0][0] ;
    }
    if(n>=4)
    {
        xs[3]=( xs[3] / l[3][3]);
        xs[2]=( xs[2] - (l[3][2] * xs[3]) ) / l[2][2];
        xs[1]=( xs[1] - (l[3][1] * xs[3]) - (l[2][1] * xs[2])  ) / l[1][1] ;
        xs[0]=( xs[0] - (l[3][0] * xs[3]) - (l[2][0] * xs[2]) - (l[1][0] * xs[1])  ) / l[0][0] ;
    }
*/    
    
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",l[j][i]);
        printf("= %f\n",xs[i]);
    }
    printf("\n\n");
    cont==-1;
}

hacertrans()
{
    float aux[n][n],aux1[n][n],aux2[n];
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
        {
            aux[j][i]=mat[i][j];
            aux1[i][j]=0;
            aux2[j]=0;
        }
        
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            aux2[i]+=aux[i][j]*iwal[j];
    
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            for(k=0; k<n; k++)
                aux1[i][j]+=aux[i][k]*mat[k][j];
                
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
        {
            mat[i][j]=aux1[i][j];
            iwal[j]=aux2[j];
        }
}

transpuestaX()
{
    cont=0;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            if(mat[i][j]==mat[j][i])
              cont++;
}

void printmat()
{
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",mat[i][j]);
        printf("= %f\n",iwal[i]);
    }
    printf("\n\n");
}

void matriz()
{
    printf("Dame la dimension: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
            {
                printf("\nDame el valor de a[%d][%d]:", i+1, j+1);
                scanf("%f",&mat[i][j]);
            }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("\nDame el vector de soluciones  [%d]: ", i+1);
        scanf("%f",&iwal[i]);
    }
    cont=0;
}

int main()
{
    char op;
    printf("\n\n\t\t\t++METODO DE CHOLESKY++\n\n");
    getchar();
    do
    {
        etiq:
        system("cls");
        printf("\n1.- Introduce matriz");
        printf("\n2.- Imprimir matriz");
        printf("\n3.- Aplicar metodo de Cholesky");
        printf("\n4.- Guardar en un archivo");
        printf("\n5.- Salir");
        printf("\n\nElige una opcion: ");
        scanf("%s",&op);
        fflush(stdin);
        switch(op)
        {
            case '1':
                matriz();
            break;

            case '2':
                printmat();
                
                system("pause");
            break;

            case '3':
                transpuestaX();
                if(cont==n*n)
                metodo();
                else
                {
                    hacertrans();
                    metodo();
                }                
                system("pause");
            break;
            
            case '4':
                guardad();
            break;

            case '5':
                printf("\n");
                exit(1);
            break;

            default:
            goto etiq;
        }
    }while(op);
}
