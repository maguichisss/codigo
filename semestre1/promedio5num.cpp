#include <cstdlib>
#include <iostream>
using namespace std;
main()
{
    int num1,num2,num3,num4,num5;
    float suma,promedio;
    cout<<"Promedio de 5 numeros \n";
    cout<<"Dame 5 numeros \n";
    cin>>num1>>num2>>num3>>num4>>num5;
    suma=num1+num2+num3+num4+num5;
    promedio=suma/5;
    cout<<"El resultado es: "<<promedio;
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
