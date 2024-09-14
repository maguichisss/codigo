///////////////////////////////////////////////////////////////////////////////////////////////////////
// Programa que cifra y descifra usando el algoritmo RSA
// Creado por Mauricio I. Garces FES Acatlan UNAM
// Octubre 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MIN 10
#define MAX 90
#define PRIMOALEATORIO 100
primerPrimoNaM(unsigned int n, unsigned int m){
	unsigned int esPrimo;       //variable que "guarda" si el numero calculado es primo o no
	unsigned int divisor;
	for (n; n <=m ; n++){
		for(divisor=2; divisor < n/2; divisor++){
			esPrimo = 1;        //damos por hecho que el numero es primo, hasta que se demuestre lo contrario
			if(n%divisor==0){
				esPrimo = 0;    //si entra aqui, no es primo
				break;          //asi que cierra el 2o ciclo for
			}
		}
		if(esPrimo !=0)         //despues de verificar y anotar si era o no primo, regresa el numero primo
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
	p = primerPrimoNaM(e, rand()%MAX+e);
	q = primerPrimoNaM(d, rand()%MAX+d);
	/*TERMINAN DATOS ALEATORIOS*/
	n = q*p;							//n
	z = (p-1) * (q-1);					//z
	e = primoRelativoAleatorio(z);      //Primo relativo con 'z' clave publica
	d = buscandoD(z,e);                 //clave privada
	/*IMPRIMIMOS RESULTADOS EN PANTALLA*/
	printf("p = %d\nq = %d\nn = %ld\nz = %d\ne = %d\nd = %d\n",p,q,n,z,e,d);
	/*INICIO GUARDAMOS EN UN ARCHIVO*/
	FILE *archivo;
    archivo = fopen("numeritosRSA","a");	//abrimos el archivo de manera que escriba al final (append)
	fprintf(archivo,"p = %d\nq = %d\nn = %ld\nz = %d\ne = %d\nd = %d\n\n",p,q,n,z,e,d);
	fclose(archivo);
	/*FIN GUARDAMOS EN UN ARCHIVO*/

}




