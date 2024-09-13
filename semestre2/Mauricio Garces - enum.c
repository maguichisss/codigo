#include<stdio.h>
#include<stdlib.h>
enum dias
{
    lunes=1,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo,
}
main()
{
    int x;
    printf("\t\tDIAS DE LA SEMANA\n");
    printf("Escribe un numero entre 1 y 7\n");
    scanf("%d",&x);
    switch(x)
    {
        case lunes:
        printf("\nHoy es lunes ");
        break;
        case martes:
        printf("\nHoy es martes ");
        break;
        case miercoles:
        printf("\nHoy es miercoles ");
        break;
        case jueves:
        printf("\nHoy es jueves ");
        break;
        case viernes:
        printf("\nHoy es viernes ");
        break;
        case sabado:
        printf("\nHoy es sabado ");
        break;
        case domingo:
        printf("\nHoy es domingo ");
        break;
        default:
        break;
    }
    printf("\n\nFIN\n\n");
}
