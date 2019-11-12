#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>

#include "p3.hpp"



////////////////////////////////////////////////////////////////////////////////

// Funcion que comprueba si un string contiene valores numericos
bool es_numero(const std::string &s) {
  std::string::const_iterator it = s.begin();

  while (it != s.end() && std::isdigit(*it)) {++it;}

  // Devuelve false cuando el string esta vacio y no se ha llegado al final
  // Devuelve true cuando el string no esta vacio y se ha llegado al final = son numeros
  return (!s.empty() && it == s.end());
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de la suma
Entero Entero::operator + (Entero e2) {
  std::string entero1 = this->getEntero();  // Primer entero
  std::string entero2 = e2.getEntero();  // Segundo entero
  std::string res;  // Resultado de la operacion

  // Variables auxiliares
  int suma, acarreo = 0;
  std::string pAux, sAux;
  std::string sumaStr;

  // Numero de digitos de los enteros
  int p = entero1.length() - 1;
  int s = entero2.length() - 1;


  while ((p >= 0) || (s >= 0)) {
    if ((p >= 0) && (s >= 0)) {
      pAux = entero1[p]; // Valor de cada digito
      sAux = entero2[s]; // Valor de cada digito

      if ((entero1[p] != '\0') && (entero2[s] != '\0')) {
        suma = atoi(pAux.c_str()) + atoi(sAux.c_str());
      }
    }
    else if (p >= 0) {
      pAux = entero1[p];

      if (entero1[p] != '\0') {
        suma = atoi(pAux.c_str());
      }
    }
    else {
      sAux = entero2[s];

      if (entero2[s] != '\0') {
        suma = stoi(sAux);
      }
    }

    // Consideracion del acarreo
    if (acarreo == 1) {
      suma++;
    }

    if (suma < 10) {  // No hay acarreo
      sumaStr = to_string(suma);
      res.append(sumaStr);

      acarreo = 0;
    }
    else {  // Existe acarreo
      suma = suma % 10;
      sumaStr = to_string(suma);
      res.append(sumaStr);

      acarreo = 1;
    }

    // Se retrocede posicion para continuar compribando los digitos
    p--;
    s--;
  }

  // Consideracion del acarreo final
  if (acarreo == 1) {
    res.append("1");
  }

  // Se corrige el orden de los digitos
  std::string auxResultado = res;
  for (size_t i = 0; i < res.length(); i++) {
    res[i] = auxResultado[res.length() - 1 - i];
  }

  // Se devuelve un Entero
  Entero resultado(res);

  return resultado;
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador del producto
Entero Entero::operator * (Entero e2) {
  int n;  // Numero de digitos
  int s;  // Mitad de los digitos
  std::string w, x, y, z; // Numeros enteros grandes
  std::string diez;  // Multiplos de 10
  std::string aux; // Auxiliar

  // Comparacion de numero de digitos
  if (this->getTam() > e2.getTam()) {
    n = this->getTam();
  }
  else {
      n = e2.getTam();
  }

  // Operacion directa
	if (n <= 4) {
		Entero resultado(to_string(this->getEnteroInt() * e2.getEnteroInt()));

		return resultado;
	}

  s = n / 2;

  // Creacion de los multiplos de 10
	diez = "1";

  for (size_t i = 0; i < s; i++) {
    diez.append("0");
  }

  // Se asignan las variables "w" y "x"
	if (this->getTam() > s) {
		for (size_t i = 0; i < this->getEntero().length() - s; i++) {
			aux = this->getEntero()[i];
			w.append(aux);
		}

		for (size_t i = this->getEntero().length() - s; i < this->getEntero().length(); i++) {
			aux = this->getEntero()[i];
			x.append(aux);
		}
	}
	else {
		w = "0";

		for (size_t i = 0; i < this->getEntero().length(); i++) {
			aux = this->getEntero()[i];
			x.append(aux);
		}
	}

  // Se asignan las variables "y" y "z"
	if (e2.getTam() > s) {
		for (size_t i = 0; i < e2.getEntero().length() - s; i++) {
			aux = e2.getEntero()[i];
			y.append(aux);
		}

		for (size_t i = e2.getEntero().length() - s; i < e2.getEntero().length(); i++) {
			aux = e2.getEntero()[i];
			z.append(aux);
		}
	}
	else {
		y = "0";

		for (size_t i = 0; i < e2.getEntero().length(); i++) {
			aux = e2.getEntero()[i];
			z.append(aux);
		}
	}

  // Transforamcion de las cadena a Entero
	Entero dieces(diez);
	Entero W(w);
  Entero X(x);
  Entero Y(y);
  Entero Z(z);

  // Calculo de la potencia de 10 y el primer entero
  Entero potencia10((W * Y).getEntero());
	std::string entero1 = potencia10.getEntero();
  Entero auxiliar(entero1);

	if (auxiliar.es_cero() == 0) {
    for (size_t i = 0; i < 2 * s; i++) {
      entero1.append("0");
    }
  }

  // Resultado
	Entero resultado(entero1);
	resultado = resultado + (((W * Z) + (X * Y)) * (dieces + (X * Z)));

	return resultado;
}

////////////////////////////////////////////////////////////////////////////////
