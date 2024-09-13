#include<stdio.h>
#include<stdlib.h>
main()
{
    int x;
    char seguir;
    do
    {
        system("clear");
        printf("Presiona un numero\n");
        printf(" 1 si es de Centigrados a Farenheit\n");
        printf(" 2 si es de Farenheit a Centigrados\n");
        scanf("%d",&x);
        if(x!=1 && x!=2)
        printf("Tonto te dije que 1 y 2 ahora moriraaasss, jajaja...\nOk no...\n");
        if(x==1)
        centifare();
        if(x==2)
        farecenti();
        printf("\nSi deseas continuar presiona S/s:  ");
        scanf("%s",&seguir);
    }
    while(seguir=='S' || seguir=='s');
    printf("\nGracias por haber jugado.\n");

}
centifare()
{
    float grados;
    printf("Escribe los grados centigrados: ");
    scanf("%f",&grados);
    grados=grados*1.8+32;
    printf("\nEl resultado es: %f\n",grados);
}
farecenti()
{
    float grados;
    printf("Escribe los grados farenheit: ");
    scanf("%f",&grados);
    grados=(grados-32)/1.8;
    printf("\nEl resultado es: %f\n",grados);
}
