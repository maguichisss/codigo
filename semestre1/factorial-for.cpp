#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{   int num,fact,i;
    cout<<"FACTORIAL";
    cout<<"Introduce un numero: "; 
    cin>>num;
    fact=1;
    for(i=2; i<=num; i++)
    {   fact = fact * i;
    }
    cout << "Su factorial es: " << fact;
    cin.get();cin.get();
    return 0;

}
