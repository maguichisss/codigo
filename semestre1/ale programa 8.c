#include <stdio.h>
#include <conio.h>
void burbuja(int a[],int n);
int main(void)
{
    int const n=5;
    int i,a[n];
    for(i=0;i<n;i++)
    {
        printf("Ingrese el %d elemento=",i+1);
        scanf("%d",&a[i]);
    }
    burbuja(a,n);
    printf("\nvector ordenado.\n");
    for(i=0;i<n;i++)
        printf("%d elemento=%d\n",i+1,a[i]);
    getch();
    return 0;
}
void burbuja(int a[],int n)
{
    int i,j,aux;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]<a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}
