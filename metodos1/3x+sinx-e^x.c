#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
main()
{
    float cont=0, a, b;
    float fa, fb, xn, fxn;
    printf("La funcion a evaluar es 3x + sen x - e^x");
    printf("\nDame el valor inicial: ");
    scanf("%f",&a);
    printf("\nDame el valor final: ");
    scanf("%f",&b);
    printf("  i\t    a\t\t b\t\t f(a)\t\t f(b)\t\t Xn\t\t  f(Xn)");
    printf("%f  %f\n",a,b);
    do
    {
        cont ++;
        fa=3*a+sin(a)-pow(2.718281828,a);
        fb=3*b+sin(b)-pow(2.718281828,b);
        xn= a-(  (fa*(a-b))  / (fa-fb)  );
        //fxn=pow(xn,10)-1;
        printf("\n%3.0f     %.9f    %.9f   %.9f    %.9f",cont,a,b,fa,fb);
      /*if(>0)
        {
            b=xn;
        }
        else
        {
            a=xn;
        }*/
        printf("  %.9f       %.9f",xn,fxn);

    FILE *arch;
    //char nomarch[60];
    fflush(stdin);
   // printf("Escribe la ruta y nombre del archivo:  ");
    //scanf("%s",&nomarch);
    arch=fopen("/home/mau/Escritorio/woow1.txt","a");
    if(arch==NULL)
    {
        printf("No se pudo abrir el archivo ");
        exit(1);
    }
    else
    //do
    {
        fprintf(arch,"%3.0f     %.7f     %.7f     %.7f     %.7f     %.7f     %.7f \n",cont,a,b,fa,fb,xn,fxn);
    }
    //while(!NULL);
    fclose(arch);
    b=a;
    a=xn;
    }
    while(cont<10);


    printf("\nFIN");
    getch();
}
