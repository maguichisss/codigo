#include <stdio.h>

float f(float x)
{
	float y;
	y = x * x * x - 2 * x * x + 7 * x - 5;
	return y;
}

float Integra(float a , float b, int n)
{
	//calculando diferencial x
	float dx,suma4x,suma2x,prefactor,postfactor,suma_total,total;
	int i=1;

	dx = (b - a) / n;

	//calculando primera parte de la integral

	suma4x = suma2x = 0;

	prefactor = (( b - a ) / ( 3 * n ) );

	//calculando segunda partede la integral

	for(i=2;i<n;i+=2)
	{
		suma4x = suma4x + 4.0 * f(a + (i-1) * dx);
		suma2x = suma2x + 2.0 * f(a + i * dx);
	}//falta sumar el último, penultimo y primer termino


	suma2x = suma2x + 4 * f( a + (n-1) * dx);		// --> Penultimo termino

	suma_total = f(a) + suma4x + suma2x + f(b);		// --> Primer y ultimo termino

	postfactor = suma_total;

	total = prefactor * postfactor;

	return total;

}

int main()
{
	float integra=Integra(1,3,10);
	printf("%f",integra);

	return 0;
}
