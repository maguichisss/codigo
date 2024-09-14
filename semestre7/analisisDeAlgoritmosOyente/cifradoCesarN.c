#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
cifradoCesar(char cadena[], int n){
    int i, aux=0;
    for(i=0; i<strlen(cadena); i++){
        if(cadena[i] < 91)
            aux = 90;
        if(cadena[i] > 96)
            aux = 122;
        if( (65 <= cadena[i] && cadena[i] <= 90) || (97 <= cadena[i] && cadena[i] <= 122))
            if(n+cadena[i] > aux)
                printf("%c",cadena[i]+n-26);
            else
                printf("%c",cadena[i]+n);
        else
            printf("%c",cadena[i]);
    }
}

main(){
    int i, n;
    char cadena[MAX];
    printf("Escribe la frase a cifrar: ");
    do{
        gets(cadena);
        if(strlen(cadena)>256){
            i=1;
            printf("La cadena debe ser menor a %d\n",MAX);
        }else
            i=0;
    }while(i);

    printf("Escribe n: ");
    do{
        scanf("%d",&n);
        if(0<n && n<26 )
            i=0;
        else{
            i=1;
            printf("Error!  -26 < n < 26   \n");
        }
    }while(i);
    cifradoCesar(cadena,n);

}
