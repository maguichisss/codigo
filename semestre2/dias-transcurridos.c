#include<stdlib.h>
#include<time.h>
#include<stdio.h>
char *dias[] = {"","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};

main()
{
    struct tm fecha;
    int anyo, mes, dia;
    // pides al usuario introducir año, mes y dia
    printf("Año:  ");    scanf("%d",&anyo);
    printf("Mes:  ");    scanf("%d",&mes);
    printf("Dia:  ");    scanf("%d",&dia);
    // Asigna fecha a la estructura fecha, en formato establecido
    fecha.tm_year=anyo-1900;
    fecha.tm_mon=mes-1;
    fecha.tm_mday=dia;
    fecha.tm_hour=0;
    fecha.tm_min=0;
    fecha.tm_sec=1;
    fecha.tm_isdst=-1;
    // mktime encuantra el dia de la semanda y el dia del año
    // devuelve -1 si hay error
    if(mktime(&fecha)==-1)
    {
        puts("Error en la fecha!!!");
        exit(-1);
    }
    // El domingo la funcion mktime le considera 0
    if(fecha.tm_wday==0)
    {
        fecha.tm_wday=7;
    }
    printf("\nEl dia de la semana: %d; dia del año %d",fecha.tm_wday,fecha.tm_yday+1);
    // Escribe el dia de la semana
    printf("\nEs el dia de la semana %s\n",dias[fecha.tm_wday]);
    return 0;

}



