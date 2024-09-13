#include<stdio.h>
int numletra(char palabra[])
{
    int i=0;
    do
        i++;
    while(palabra[i-1]!='\0');
    return(i-1);
}
main()
{
    static char palabra[30], opc;
    int i, x, cons=0, num=0, esp=0, vocal=0, otro=0;
    do
    {
        system("clear");
        printf("Escribe una palabra: ");
        fflush(stdin);
        gets(palabra);
        x=numletra(palabra);
        for(i=0; i<x; i++)
        {
            if((palabra[i]>65 && palabra[i]<=90 || palabra[i]>97 && palabra[i]<=122) && !(palabra[i]==65 || palabra[i]==69 || palabra[i]==73 || palabra[i]==79 || palabra[i]==85 || palabra[i]==65+32 || palabra[i]==69+32 || palabra[i]==73+32 || palabra[i]==79+32 || palabra[i]==85+32))
                cons++;
            else if(palabra[i]== 32)
                esp++;
            else if(palabra[i]>=48 && palabra[i]<=57)
                num++;
            else if(palabra[i]==65 || palabra[i]==69 || palabra[i]==73 || palabra[i]==79 || palabra[i]==85 || palabra[i]==65+32 || palabra[i]==69+32 || palabra[i]==73+32 || palabra[i]==79+32 || palabra[i]==85+32)
                vocal++;
            else
                otro++;
        }
        printf("\nConsonantes: %d",cons);
        printf("\nNumeros: %d",num);
        printf("\nEspacios: %d",esp);
        printf("\nVocales: %d",vocal);
        printf("\nOtros caracteres: %d",otro);
        printf("\n\nDeseas escribir otra palabra S/N:  ");
        scanf("%s",&opc);
    }while(opc=='S' || opc=='s');

}
