/* 
   Grupo: 2203
   
   Castro Villanueva Rubén Getsemani
   Enciso Vega Jessica Nohemi
   Garces Brito Mauricio Ilhuicamina
   Rojas Gomez Ana Cecilia
   Rosales Quintanar Mariana
   Sanchez Gutierrez Moises A.
   Vazquez Negrete Lucero
   
*/



#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,i,j,k,cont;
float mat[10][10];
float iwal[10];

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
        printf("\nDame el valor de los iwales  [%d]: ", i+1);
        scanf("%f",&iwal[i]);
    }
}

void edd()
{
    float xii;
    cont=0;
    for(i=0;i<n;i++)
    {
           xii=0;
           for(j=0; j<n; j++)
              if(i!=j)
                 xii+=abs(mat[i][j]);
           for(j=0; j<n; j++)
              if(abs(mat[i][i])>=xii)
              {
                 cont++;
                 break;
              }
    }
    if(n==cont)
    metodo();
    else
    {
        printf("\nNo es EDD\n\n");
        system("pause");
    }
}

void printmat()
{
    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",mat[i][j]);
        printf("= %f\n",iwal[i]);
    }
    system("pause");
}

void metodo()
{
    int x;
    float mataux[n][n],iwalaux[n], raiz[n], raizaux[n], aux[n][n], ekis;
    float error[n], errormax, raizmax;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if(i != j)
                mataux[i][j] = -mat[i][j]/mat[i][i];

        mataux[i][i] = 0;
        iwalaux[i] = iwal[i]/mat[i][i];
        raiz[i] = 0;
        raizaux[i] = 0;
        error[i]=0;
    }

    for(x=0; x<n; x++)
    {
        for(i=0; i<n; i++)
        {
            ekis=0;
            for(j=0; j<n; j++)
            {
                printf(" %f*%f  + ",mataux[i][j],raiz[j]);
                aux[i][j] = mataux[i][j]*raiz[j];
                ekis += aux[i][j];
            }
            printf("%f",iwalaux[i]);
            raizaux[i] = ekis + iwalaux[i];
            printf(" = %f \n",raizaux[i]);

        }

        for(i=0; i<n; i++)
        {
            raiz[i]=raizaux[i];
            error[i] =  raiz[i] - error[i] ;
            if(error[i]<0)
                error[i] = -error[i];
            printf("ERROR: %f",error[i]);
        }
        errormax = error[0];
        if(raiz[0]<0)
            raizmax = -raiz[0];
        else
            raizmax = raiz[0];
        for(i=0; i<n; i++)
        {
            if(error[i] > errormax)
                errormax = error[i];
            if(raiz[i]<0)
                raizmax = -raiz[i];
            if(raiz[i] > raizmax)
                raizmax = raiz[i];
        }
        for(i=0; i<n; i++)
        error[i] = raiz[i];
        errormax = errormax/raizmax;
        printf("ERROR: %f\n",errormax);

    }
    system("pause");
}

int main()
{
    char op;
    printf("\n\n\t\t++METODO DE JACOBI++\n\n");
    system("pause");
    do
    {
        etiq:
        system("cls");
        printf("\n1.- Introduce matriz");
        printf("\n2.- Imprimir matriz");
        printf("\n3.- Aplicar el metodo de Jacobi");
        printf("\n4.- Salir");
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
            break;

            case '3':
                edd();
            break;

            case '4':
                exit(1);
            break;

            default:
            goto etiq;
        }
    }while(op);
}
