#include<iostream>
using namespace std;
int main()
{     long double num,cant,fact;
      fact=1;
      cout<<"Ingrese el numero"<<endl;
      cout<<endl;                      //endl es para bajar de linea
      cin>>num;
      cant=num;
      cout<<endl;
      while (num>0)
      {     fact=fact*num;
            num=num-1;
      }
      cout<<endl;
      cout<<cant<<"!="<<fact<<endl;
      cout<<endl;
      system ("pause");
      return 0;
} 
