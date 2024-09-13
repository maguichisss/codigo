#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592
cilindro()
{
    system("clear");
    float radio, altura;
    float area, volumen;
    printf("Escribe el radio de la circunferencia del cilindro: ");
    scanf("%f",&radio);
    printf("Escribe la altura del cilindro: ");
    scanf("%f",&altura);
    area=PI*radio*radio;
    volumen=area*altura;
    printf("El volumen del cilindro es:  %f",volumen);

}
cubo()
{
    system("clear");
    float lado,volumen;
    printf("Escribe el lado del cubo:  ");
    scanf("%f",&lado);
    volumen=lado*lado*lado;
    printf("El volumen del cubo es: %f",volumen);
}
piramide()
{
    system("clear");
    float lado, altura;
    float area,volumen;
    printf("Escribe el lado de la base de la  piramide:  ");
    scanf("%f",&lado);
    printf("\nEscribe la altura de la piramide:  ");
    scanf("%f",&altura);
    area=lado*lado;
    volumen=(area*altura)/3;
    printf("\nEl volumen de la piramide es:  %.3f",volumen);

}
main()
{
    char seguir;
    int num;
    do
    {
        etiqueta:
        system("clear");
        printf("Presiona el numero de la operacion que de seas realizar");
        printf("\n  1  - Volumen de cilindro");
        printf("\n  2  - Volumen de cubo");
        printf("\n  3  - Volumen de piramide   ");
        scanf("%i",&num);
        switch(num)
        {
            case 1:
            cilindro();
            break;

            case 2:
            cubo();
            break;

            case 3:
            piramide();
            break;

            default:
            goto etiqueta;
            break;
        }
        printf("\n\nDeseas realizar alguna otra operacion  S/N:  ");
        scanf("%s",&seguir);
    }
    while(seguir=='S' || seguir=='s');
}

