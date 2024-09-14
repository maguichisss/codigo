///////////////////////////////////////////////////////////////////////////////////////////////////////
// Programa que cifra y descifra usando el algoritmo RSA
// Creado por Mauricio I. Garcés FES Acatlan UNAM
// Octubre 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MIN 10000
#define MAX 10000
#define PRIMOALEATORIO 100
primoNaM(unsigned int n, unsigned int m){
    unsigned int esPrimo;       //variable que "guarda" si el numero calculado es primo o no
    unsigned int divisor;
    for (n; n <=m ; n++){
        for(divisor=2; divisor < n/2; divisor++){
            esPrimo = 1;        //damos por hecho que el numero es primo, hasta que se demuestre lo contrario
            if(n%divisor==0){
                esPrimo = 0;    //si entra aquí, no es primo
                break;          //así que cierra el 2° ciclo for
            }
        }
        if(esPrimo !=0)         //después de verificar y anotar si era o no primo, regresa el numero primo
            return n;
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
        if(esPrimoRelativo && rand()%PRIMOALEATORIO == 1)
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
    unsigned int p, q, e ,d, z;
    unsigned long n;
    /*EMPIEZAN DATOS ALEATORIOS*/
    e = rand()%MAX+MIN;                 //Usamos 'e' y 'd' como auxiliares para no declarar otras variables... jaja
    d = rand()%MAX+MIN;
    p = primoNaM(e, rand()%MAX+e);
    q = primoNaM(d, rand()%MAX+d);
    /*TERMINAN DATOS ALEATORIOS*/
    n = q*p;
    z = (p-1) * (q-1);
    e = primoRelativoAleatorio(z);      //Primo relativo con 'z' clave publica
    d = buscandoD(z,e);                 //clave privada


    printf("p = %d\nq = %d\nn = %d\nz = %d\ne = %d\nd = %d\n",p,q,n,z,e,d);




}






