/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PROGRAMA QUE MUESTRA LA TABLA ASCII
Creado por: Mauricio Garcés
Fecha de creacion: 11-11-10
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
main()
{
    int x,y;
    printf("\t\tASCII\tDECIMAL\tOCTAL\tHEXADECIMAL\tBINARIO\n");
    for(x=1;x<=256;x++)
    {
        if(x>7 && x<11 || x==13)
        {
            printf("Desconocido");
            printf("\t\t%3d\t%3o\t%6x\t%15d\n",x,x,x,binario(x));
            continue;
        }
        if(x==7)
        printf("Sonido");

        printf("\t\t%3c\t%3d\t%3o\t%6x\t%15d\n",x,x,x,x,binario(x));
    }
    system("pause");
}
binario(num)
int num;
{
    int bin,x,temp;
    bin = 0;
    x = 1;
    temp = num;
    do
    {
        bin += temp % 2 * x;
        temp /= 2;
        x *= 10;
    }while(temp >= 2);
    bin += x * temp;
    return(bin);
}
