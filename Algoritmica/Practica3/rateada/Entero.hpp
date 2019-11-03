#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cmath>
#include "funcionesbajonivel.cpp"

#ifndef _ENTERO_HPP_
#define _ENTERO_HPP_

using namespace std;
namespace al {
class Entero {
	private:
		string _a;

	public:
		inline Entero(string cadena=""){
			setEntero(cadena);
		}

		inline void setEntero (string a){
			_a = a;
		}

		inline string getEntero() const{
			return _a;
		}

		inline int getvalor(){
			int aux;
			aux = atoi(this->getEntero().c_str());
			return aux;
		}
		inline int getTamano() const{
			string aux=this->getEntero();
			int length=aux.length();
			int tam=0;
			for(int i=0;i<length;i++){
				if(aux[i]!='\0'){
					tam++;
				}
			}
			return tam;
		}

		Entero  operator+(Entero a);

		inline int isCero(){
			string cadena=this->getEntero();
			string aux;
			for(int i=0;i<cadena.length();i++)
			{
				if(cadena[i]!='\0')	//Evita hacer stoi de un valon NaN
				{
					aux=cadena[i];
					int numero=stoi(aux);
					if(numero!=0)
						return 0;
				}
			}
			return 1;
		}


		Entero  operator*(Entero a);

		inline Entero  operator=(Entero a){
			this->setEntero(a.getEntero());
			return *this;
		}

		friend inline istream& operator>>(istream & i, Entero & aux)
		{
			i>>aux._a;
			return i;
		}

	 friend inline ostream& operator<<(ostream & o, Entero aux)
		{
			o << aux.getEntero();
			return o;
		}
	};
}

#endif
