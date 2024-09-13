#include<stdio.h>
#include<stdlib.h>
//#define Pi 3.1416
int main()
{
       float *PI;
       float *radio,*area,*perimetro;
       PI=new float;
       *PI=3.1416;
       radio=(float*)malloc(sizeof(float));
       area=new float;
       perimetro=(float*)malloc(sizeof(float));
       printf("\t\tPROGRAMA QUE CALCULA EL AREA Y PERIMETRO DE UN CIRCULO\N");
       printf("\nEscribe el radio del circulo:  ");
       scanf("%f",&(*radio));
       *area=(*PI)*(*radio)*(*radio);
       *perimetro=(*PI)*(*radio)*2;
       printf("El area del circulo es: %.4f",*area);
       printf("\nEl perimetro del circulo es: %f",*perimetro);
       delete(radio);
       delete(perimetro);
       free(PI);
       free(area);
       return 0;
}
