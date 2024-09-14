#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
cifradoVigenere(char cadena[], char clave[]){
    int i, j=0, n, longitudClave;
    longitudClave=strlen(clave);
	printf("El texto cifrado es: ");
    for(i=0; i<strlen(cadena); i++){
        //printf("%d----%d\n",j,longitudClave);
        if((65 <= cadena[i] && cadena[i] <= 90) || (97 <= cadena[i] && cadena[i] <= 122)){
            if(j == longitudClave)
                j=0;
            n = clave[j]-65;
            j++;
            if(n+cadena[i] > 90)
                printf("%c",cadena[i]+n-26);
            else
                printf("%c",cadena[i]+n);
        }else
            printf("%c",cadena[i]);
    }
	printf("\n");
}

main(){
    int i, j, iguales=1;
    char cadena[MAX];
    char clave[MAX];
    do{
        printf("Escribe la cadena a cifrar: ");
        scanf("%*c%[^\n]",cadena);
        if(strlen(cadena)>256){
            i=1;
            printf("La cadena debe ser menor a %d\n",MAX);
        }else
            i=0;
    }while(i);

    do{
        printf("Escribe la clave de la cadena cifrada: ");
        scanf("%*c%[^\n]",clave);
        if(strlen(clave)>256){
            i=1;
            printf("La cadena debe ser menor a %d\n",MAX);
        }else
            i=0;
    }while(i);

    for(i=0; i<strlen(cadena); i++)
        cadena[i] = toupper(cadena[i]);
    for(i=0; i<strlen(clave); i++)
        clave[i] = toupper(clave[i]);

    cifradoVigenere(cadena,clave);

}
