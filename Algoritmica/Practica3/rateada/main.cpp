#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Entero.cpp"

using namespace al;

int main(int argc, char const *argv[]) {
	Entero a;
	Entero b;
	Entero aux;
	int option;

	char auxi;
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
