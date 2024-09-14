///////////////////////////////////////////////////////////////////////////////////////////////////////
// Programa que te muestra todos los primos relativos de un numero
// Creado por Mauricio I. Garcés FES Acatlan UNAM
// Octubre 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

primoRelativo(unsigned int n){
    int i, divisor, esPrimoRelativo, primoRelativo;
    for(primoRelativo = 2; primoRelativo < n; primoRelativo++){
        for(divisor = 2; divisor < n/2; divisor++){
            esPrimoRelativo = 1;
            if( (n%divisor == 0) && (primoRelativo%divisor == 0)){
                esPrimoRelativo = 0;
                break;
            }
        }
        if(esPrimoRelativo)
            printf("%d\n",primoRelativo);
    }
}

ultimoPrimoRelativo(unsigned int n){
    int divisor, esPrimoRelativo, primoRelativo;
    for(primoRelativo = n-1; primoRelativo > 0; primoRelativo--){
        for(divisor = 2; divisor < n/2; divisor++){
            esPrimoRelativo = 1;
            if( (n%divisor == 0) && (primoRelativo%divisor == 0)){
                esPrimoRelativo = 0;
                break;
            }
        }
        if(esPrimoRelativo){
            printf("%d\n",primoRelativo);
            break;
        }
    }
}

primoRelativoAleatorio(unsigned int n){
    int i, divisor, esPrimoRelativo, primoRelativo;
    for(primoRelativo = 2; primoRelativo < n; primoRelativo++){
        for(divisor = 2; divisor < n/2; divisor++){
            esPrimoRelativo = 1;
            if( (n%divisor == 0) && (primoRelativo%divisor == 0)){
                esPrimoRelativo = 0;
                break;
            }
        }
        if(esPrimoRelativo && rand()%5 == 1)
            return primoRelativo;
    }
}

buscandoD(unsigned int z, unsigned int e){
    int d;
    for(d=1; d<z; d++)
        if( (e*d)%z == 1)
            return d;
}

int main(){
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    printf("Primos relativos del %d: \n",n);
    primoRelativo(n);
    printf("Ultimo primo relativo: ");
    ultimoPrimoRelativo(n);
    printf("Primo relativo aleatorio: %d\n",primoRelativoAleatorio(n));
    printf("Encontramos d = : %d\n",buscandoD(20,7));

}





