#include<stdio.h>
#include<time.h>
main()
{
    int ani, mes, dia;
    int aniu, mesu, diau;
    int anir, mesr, diar;
    etik:
    system("clear");
    printf("PROGRAMA QUE DICE TU EDAD\n");
    printf("\nDame el año actual: ");
    scanf("%d",&ani);
    printf("\nDame numero del mes en curso: ");
    scanf("%d",&mes);
    printf("\nEscribe que dia del mes es hoy: ");
    scanf("%d",&dia);
    printf("\nDame el año en que naciste: ");
    scanf("%d",&aniu);
    printf("\nDame el mes en que naciste: ");
    scanf("%d",&mesu);
    printf("\nDame el dia en que naciste: ");
    scanf("%d",&diau);
    if(ani<aniu)
    {
        printf("\nLa feha esta mal!!! Sonso...");
        goto etik;
    }
    if(mes<mesu)
    {
        ani--;
        mesu-=12;
    }
    if(dia<diau)
    {
        mes--;
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        diau+31;
        if(mes==2)
        diau+28;
        if(mes==4 || mes==6 || mes==9 || mes==11)
        diau+30;
    }
    mesr=mes-mesu;
    anir=ani-aniu;
    diar=dia-diau;
    time_t tiempo = time(NULL);
    struct tm *tiemlocal = localtime(&tiempo);
    char hms[15];
    strftime(hms,15,"%H:%M:%S",tiemlocal);
    printf("\nTienes %d años %d meses %d dias %s",anir,mesr,diar,hms);
}
