///////////////////////////////////////////////////////////////////////////////////////////////////////
// Programa que Caulcula los primeros N numeros Primos
// Escrito por Luis Landín
// Facultad de Ingenieria, UNAM
// Domingo 14 de Agosto 2011
// Modificado por Mauricio I. Garcés FES Acatlan UNAM
// 24 de Octubre de 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int main(){
    unsigned int numero;//limite en los ciclos for
    unsigned int n, esPrimo;//n es el ultimo numero que queremos calcular,
    //esPrimo es una variable que "guarda" si el numero calculado es primo o no
    unsigned int divisor, residuo;//un par de variables para ir probando si es primo o no
    unsigned int contador=0;//un contador para saber cuantos primos obtuvimos
    printf("Desde que numero desea conocer los primos: ");
    scanf("%d",&numero);
    printf("Hasta que numero desea conocer los primos: ");
    scanf("%d", &n);
    for (numero; numero<=n; numero++){
        for(divisor=2; divisor<numero; divisor++){
            esPrimo=1;//damos por hecho que el numero es primo, hasta que se demuestre lo contrario
            residuo=numero%divisor;
            if(residuo==0){
                esPrimo=0;//si entra aquí, sí, se demostró lo contrario
                break;//así que cierra el 2° ciclo for, sigue con el siguiente numero
            }
        }
        if(esPrimo !=0){ //después de verificar y anotar si era o no primo, imprime en pantalla
            printf("%d \n",numero);
            contador=contador+1;//y añade a nuestro contador un termino mas
        }
    }
    printf("Estos son todos los %d numeros primos\n",contador);
    getchar();
    return 0;//en caso de que exista un error, el compilador nos regresara un 1, en ves de 0
}
