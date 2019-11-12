#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <iostream>
#include <string>

#include "funcionesbajonivel.hpp"

using namespace std;

string reservarCadena(int n)
{
	string a;
	a.resize(n);
	return a;
}

void partirCadena(string s, string &s1, string &s2)
{
	int n;
	int n1, n2;
	int i;

	n = s.size();

	if (n % 2 == 0) //n es par
	{
		n1 = n / 2;
		n2 = n1;
	}
	else
	{
		n1 = (n + 1) / 2;
		n2 = n1 - 1;
	}

	s1 = reservarCadena(n1 + 1); //Se reserva uno mas para el caracter fin de cadena
	s2 = reservarCadena(n2 + 1); //Se reserva uno mas para el caracter fin de cadena

	for(i = 0; i < n1; i++) //Se rellena la primera cadena
		s1[i] = s[i];

	for(i = n1; i < n; i++) //Se rellena la segunda cadena
		s2[i - n1] = s[i];
}



void agregarCerosFinal(string &c, int nCeros)
{
	int n, numeroCaracteres;
	string nuevaCadena;
	int i;

	n = c.size();
	numeroCaracteres = n + nCeros;

	nuevaCadena = reservarCadena(numeroCaracteres + 1);

	for(i = 0; i < n; i++) //Se rellena la primera cadena
		nuevaCadena[i] = c[i];

	for(i = n; i < numeroCaracteres; i++) //Se rellena con los ceros al final
		nuevaCadena[i] = '0';

	c = nuevaCadena;
}

void agregarCerosDelante(string &c, int nCeros)
{
	int n, numeroCaracteres;
	string nuevaCadena;
	int i;

	n = c.size();
	numeroCaracteres = n + nCeros;

	nuevaCadena = reservarCadena(numeroCaracteres + 1);

	for(i = 0; i < n; i++) //Se desplazan los caracteres iniciales para dejar espacio a los ceros
		nuevaCadena[i + nCeros] = c[i];

	for(i = 0; i < nCeros; i++) //Se rellena con los ceros al principio
		nuevaCadena[i] = '0';
	c = nuevaCadena;
}

void quitarCerosNoSignificativos(string &c)
{
	string aux;
	int l, i = 0;
	int numeroCeros = 0;

	l = c.size();
	//Contamos ceros no significativos
	while(c[i] == '0' && i < l)
	{
		i++;
		numeroCeros++;
	}

	//Reservamos nueva cadena
	aux = reservarCadena(l - numeroCeros + 1);

	//Copiamos la cadena sin los ceros no significativos
	for(i = numeroCeros; i < l; i++)
		aux[i - numeroCeros] = c[i];
	c = aux;
}

string multiplicarPotencia10(const string &c, int potencia)
{
	string aux;

	aux = reservarCadena(c.size() + 1);
	aux = c;
	//cout<<"valor como string"<<c<<endl;
	agregarCerosFinal(aux, potencia);
	//quitarCerosNoSignificativos(aux);
	return aux;
}

void AgregarCeros(string & cadena, int c)
{
	for(int i=0;i<c;i++)
		cadena.append("0");
}
