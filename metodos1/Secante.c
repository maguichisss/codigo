// septiembre 2011
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float a1, b1;
float x0,tol;
float fun[10];
int i,n;

guardar()
{
    float cont=0;
    float fa, fb, xn, fxn,error,xerr=0;
    char ruta[]="secante.txt";
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
    fprintf(arch,"\na = %f\nb = %f\n",a1,b1);
    fprintf(arch,"\n i\t   a\t\t b\t f(a)\t     f(b)\t     Xn\t       error");
    do
    {
        fa=0, fb=0,fxn=0;
        cont ++;
        for(i=0; i<n; i++)
            fa+=pow(a1,n-i)*fun[n-i-1];
        fa+=x0;
        for(i=0; i<n; i++)
            fb+=pow(b1,n-i)*fun[n-i-1];
        fb+=x0;
        xn= a1-(  (fa*(a1-b1))  / (fa-fb)  );
        for(i=0; i<n; i++)
            fxn+=pow(xn,n-i)*fun[n-i-1];
        fxn+=x0;        
        error=((xerr-xn)/xn)*100;
        if(error<0)
        error=error*-1;
        fprintf(arch,"\n%2.0f     %f     %f   %f    %f     %f    %f",cont,a1,b1,fa,fb,xn,error);
        b1=a1;
        xerr=a1=xn;
    }while(error>tol);
    fprintf(arch,"\n\nLa raiz es: %f\n\n",xn);
    fclose(arch);
    printf("\n\nGuardado con exito!!!\n\n");
    system("pause");
}

metodo()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn,error,xerr=0;;
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
    scanf("%f",&a); a1=a;
    printf("\nDame el valor final: ");
    scanf("%f",&b); b1=b;
    printf("\nDame la tolerancia: ");
    scanf("%f",&tol);
    for(i=0; i<n; i++)
    printf("%1.0f*%c%c%d + ",fun[n-i-1],120,94,n-i);
    printf("%.2f\n",x0);
    printf("\na = %f\nb = %f\n",a,b);
    printf("\n i\t   a\t\t b\t f(a)\t     f(b)\t     Xn\t       error");
    do
    {
        fa=0, fb=0,fxn=0;
        cont ++;
        for(i=0; i<n; i++)
            fa+=pow(a,n-i)*fun[n-i-1];
        fa+=x0;
        for(i=0; i<n; i++)
            fb+=pow(b,n-i)*fun[n-i-1];
        fb+=x0;
        xn= a-(  (fa*(a-b))  / (fa-fb)  );
        for(i=0; i<n; i++)
            fxn+=pow(xn,n-i)*fun[n-i-1];
        fxn+=x0;        
        error=((xerr-xn)/xn)*100;
        if(error<0)
        error=error*-1;
        printf("\n%2.0f     %f     %f   %f    %f     %f    %f",cont,a,b,fa,fb,xn,error);
        b=a;
        xerr=a=xn;
    }while(error>tol);
    printf("\n\nLa raiz es: %f",xn);
    printf("\n\nFIN");
    getch();
}

main()
{
    char op;
    do
    {
        etiq:
        system("cls");
        printf("\n\n\t\t\t++METODO DE LA SECANTE++\n\n");
        printf("\n1.- Metodo de la secante");
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
