/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA OBTIENE 5 CALIFICACIONES DE 30 ALUMNOS
Creado por: Mauricio Garcés
Fecha de creacion: 23-11-10
Fecha de modificacion 2-12-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#include<stdio.h>
#include<stdlib.h>
float calestud[30][5];
main()
{
    float prom[30];
    printf("Promedia 5 calificaciones de 30 alumnos\n");
    obtcalif();
    califprom(prom);
    propcalif(prom);
}
obtcalif()
{
    int x,y,num;
    printf("Introduce las calificaciones de los alumnos\n");
    printf("Para terminar teclee 999 y luego enter\n");
    for(x=0;x<30;x++)
        for(y=0;y<5;y++)
            calestud[x][y]=999;
    for(x=0;x<30;x++)
    {
        for(y=0;y<5;y++)
        {
            printf("Alumno %d, %da calificacion: ",x+1,y+1);
            scanf("%f",&calestud[x][y]);
            if(calestud[x][y]==999)
            {
                calestud[x][y]=0;
                break;
            }
        }
        if(calestud[x][y]!=999)
            break;
    }
}

califprom(prom)
float prom[30];
{
    int x,y;
    for(x=0;x<30;x++)
        prom[x]=0;
    for(x=0;x<30;x++)
    {
        for(y=0;y<5;y++)
        {
            if(calestud[x][y]==999)
                calestud[x][y]=0;
            prom[x]+=calestud[x][y];
        }
    }
    for(x=0;x<30;x++)
        prom[x]/=5;
}

propcalif(prom)
float prom[30];
{
    int x,y=1;
    for(x=0;x<30;x++)
    {
        if(prom[x]!=0)
            printf("El promedio del alumno %d es: %3.2f\n",y++,prom[x]);
    }
}
