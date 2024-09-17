#include<iostream>
using namespace std;

int main() {
	int aux;
	int i;
	int j;
	int n;
	cout<<"programa de pares y nones \\n\\n"<<endl;
	cout<<"escribe el número de elementos del arreglo:"<<endl;
	cin>>n;
	int a[n];
	cout<<"dame "<<n<<" datos :"<<endl;
	for (i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (i=1;i<=n;i++) {
		if (i%2==0) {
			for (j=2;j<=n-1;j+=2) {
				if (a[j]>a[j+1]) {
					aux=a[j];
					a[j]=a[j+1];
					a[j+1]=aux;
				}
			}
		} else {
			for (j=1;j<=n-1;j+=2) {
				if (a[j]>a[j+1]) {
					aux=a[j];
					a[j]=a[j+1];
					a[j+1]=aux;
				}
			}
		}
	}
	for (i=1;i<=n;i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}

