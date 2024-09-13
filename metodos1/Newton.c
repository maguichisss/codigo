// septiembre 2011
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float x1;
float x0,tol;
float fun[10];
int i,n;

guardar()
{
    float cont=0;
    float fx,fdx,xn,error,xerr=0;
    char ruta[]="newton.txt";
    FILE *arch;
    arch=fopen(ruta,"w");
    if(arch==NULL)
    {
        printf("\nEl archivo no pudo ser creado\n");
        exit(1);
    }
    for(i=0; i<n; i++)
    fprintf(arch,"%1.0f*%c%c%d + ",fun[n-i-1],120,94,n-i);
    fprintf(arch,"%.2f\n",x0);
    fprintf(arch,"\n i\t  x\t f(x)\t   f'(x)     error");
    do
    {
        fx=0, fdx=0;
        cont ++;
        for(i=0; i<n; i++)
            fx+=pow(x1,n-i)*fun[n-i-1];
        fx+=x0;
        for(i=0; i<n; i++)
            fdx+=(n-i)*fun[n-i-1]*pow(x1,n-1-i);
        xn=x1-(fx/fdx);
        error=((xerr-xn)/xn)*100;
        if(error<0)
        error=error*-1;
        fprintf(arch,"\n%2.0f   %f  %f  %f  %f",cont,x1,fx,fdx,error);
        xerr=x1=xn;
    }while(error>tol);
    fprintf(arch,"\n\nLa raiz es: %f\n",xn);
    fclose(arch);
    printf("\n\nGuardado con exito!!!\n\n");
    system("pause");
    
}

metodo()
{
    float cont=0, x;
    float fx,fdx,xn,error,xerr=0;
    printf("Cual es el grado de la funcion: ");
    scanf("%d",&n);
    for(i=n; i>0; i--)
    {
        printf("Dame x%d: ",i);
        scanf("%f",&fun[i-1]);
    }
    printf("Dame x0: ");
    scanf("%f",&x0);
    printf("\nDame el valor inicial: ");
    scanf("%f",&x); x1=x;
    printf("\nDame la tolerancia: ");
    scanf("%f",&tol);
    for(i=0; i<n; i++)
    printf("%1.0f*%c%c%d + ",fun[n-i-1],120,94,n-i);
    printf("%.2f\n",x0);
    printf("\n i\t  x\t f(x)\t   f'(x)     error");
    do
    {
        fx=0, fdx=0;
        cont ++;
        for(i=0; i<n; i++)
            fx+=pow(x,n-i)*fun[n-i-1];
        fx+=x0;
        for(i=0; i<n; i++)
            fdx+=(n-i)*fun[n-i-1]*pow(x,n-1-i);
        xn=x-(fx/fdx);
        error=((xerr-xn)/xn)*100;
        if(error<0)
        error=error*-1;
        printf("\n%2.0f   %f  %f  %f  %f",cont,x,fx,fdx,error);
        xerr=x=xn;
    }while(error>tol);
    printf("\n\nLa raiz es: %f",xn);
    printf("\nFIN");
    getch();
}

main()
{
    char op;
    do
    {
        etiq:
        system("cls");
        printf("\n\n\t\t\t++METODO DE NEWTON++\n\n");
        printf("\n1.- Metodo de Newton");
        printf("\n2.- Guardar");
        printf("\n3.- Salir");
        printf("\n\nElige una opcion: ");
        scanf("%s",&op);
        fflush(stdin);
        switch(op)
        {
            case '1':
                metodo();
            break;

            case '2':
                guardar();
            break;

            case '3':
                exit(1);
            break;

            default:
            goto etiq;
        }
    }while(op);
}
