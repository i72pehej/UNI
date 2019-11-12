#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Entero.cpp"

using namespace al;

int main ()
{
	Entero a ;
	Entero b ;
	char auxi;
	int option;
	Entero aux;
	string x, y;
	cout<<"1-Suma"<<endl;
	cout<<"2-multiplicacion"<<endl;
	cin >> option;
	cout << "primer entero ";
	cin >> a;
	cout << "segundo entero: ";
	cin >> b;

	switch(option){
		case 1:

		aux = a + b;
		cout << "suma=" << aux.getEntero();
		break;
		case 2:
		aux = a * b;
		cout << "multiplicacion=" << aux.getEntero();
		break;
	}
}
