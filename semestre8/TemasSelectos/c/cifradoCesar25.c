#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
cifradoCesar(char cadena[]){
    int i, j, aux=0;
    for(i=1; i<26; i++){
        printf("C%d: ",i);
        for(j=0; j<strlen(cadena); j++){
            if(cadena[j] < 91)
                aux = 90;
            if(cadena[j] > 96)
                aux = 122;
            if((65 <= cadena[j] && cadena[j] <= 90) || (97 <= cadena[j] && cadena[j] <= 122))
                if(i+cadena[j] > aux)
                    printf("%c",cadena[j]+i-26);
                else
                    printf("%c",cadena[j]+i);
            else
                printf("%c",cadena[j]);
        }
        printf("\n");
    }
}

main(){
    int i, n;
    char cadena[MAX];
    printf("Escribe la frase a cifrar: ");
    do{
        scanf("%*c%[^\n]",cadena);
        if(strlen(cadena)>256){
            i=1;
            printf("La cadena debe ser menor a %d\n",MAX);
        }else
            i=0;
    }while(i);
    cifradoCesar(cadena);
}
