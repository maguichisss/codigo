// septiembre 2011
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
//#include<math.h>

int n,i,j,k,cont,iter;
float mat[10][10];
float iwal[10];

guardar()
{
    char ruta[]="gauss-seidel.txt";
    float mataux[n][n],iwalaux[n], raiz[n], raizaux[n], aux[n][n], ekis;
    FILE *arch;
    arch=fopen(ruta,"w");
    if(arch==NULL)
    {
        printf("\nEl archivo no pudo ser creado\n");
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if(i != j)
                mataux[i][j] = -mat[i][j]/mat[i][i];

        mataux[i][i] = 0;
        iwalaux[i] = iwal[i]/mat[i][i];
        raiz[i] = 0;
        raizaux[i] = 0;
    }
    
    for(k=0; k<iter; k++)
    {
        fprintf(arch,"\n%da iteracion\n",k+1);
        for(i=0; i<n; i++)
        {
            ekis=0;
            for(j=0; j<n; j++)
            {
                fprintf(arch," %f ",mataux[i][j]);
                aux[i][j] = mataux[i][j]*raiz[j];
                ekis += aux[i][j];
            }
            raiz[i] = ekis + iwalaux[i];
            fprintf(arch,"= x%d = %f \n",i+1,raiz[i]);
        }
        fprintf(arch,"\n");
    }
    fclose(arch);
    printf("\n\nGuardado con exito!!!\n\n");
    system("pause");
    
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
    printf("\nEs EDD\n\n");
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
}

void metodo()
{
    float mataux[n][n],iwalaux[n], raiz[n], raizaux[n], aux[n][n], ekis;

    printf("\nDame el numero de iteraciones: ");
    scanf("%d",&iter);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if(i != j)
                mataux[i][j] = -mat[i][j]/mat[i][i];

        mataux[i][i] = 0;
        iwalaux[i] = iwal[i]/mat[i][i];
        raiz[i] = 0;
        raizaux[i] = 0;
    }
/*  for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
            printf(" %f ",mataux[i][j]);
        printf("= %f\n",iwalaux[i]);
    }
*/
    for(k=0; k<iter; k++)
    {
        printf("\n%da iteracion\n",k+1);
        for(i=0; i<n; i++)
        {
            ekis=0;
            for(j=0; j<n; j++)
            {
                printf(" %f ",mataux[i][j]);
                aux[i][j] = mataux[i][j]*raiz[j];
                ekis += aux[i][j];
            }
            raiz[i] = ekis + iwalaux[i];
            printf("= x%d = %f \n",i+1,raiz[i]);
        }
        printf("\n");
    }
    cont=0;
}

int main()
{
    char op;
    printf("\n\n\t\t\t++METODO DE GAUSS-SEIDEL++\n\n");
    getchar();
    do
    {
        etiq:
        system("cls");
        printf("\n1.- Introduce matriz");
        printf("\n2.- Imprimir matriz");
        printf("\n3.- Aplicar metodo de Gauss-Seidel");
        printf("\n4.- Guardar");
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
                edd();
                if(cont==n)
                metodo();
                system("pause");
            break;
            
            case '4':
                guardar();
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
