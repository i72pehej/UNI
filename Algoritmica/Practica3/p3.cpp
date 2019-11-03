#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>

#include "p3.hpp"



////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  system("clear");

  int opcion; // Opcion para switch

  Entero e1, e2, aux; // Enteros grandes


  std::cout << "\n\n-------------------------------" << '\n';
  std::cout << "Introduzca la operacion deseada" << '\n';
  std::cout << "-------------------------------" << '\n';
  std::cout << "\t(1) ------ SUMA" << '\n';
  std::cout << "\t(2) ------ PRODUCTO" << '\n';
  std::cout << "-------------------------------" << '\n';
  std::cout << "\t(0) ------ SALIR" << '\n';
  std::cout << "-------------------------------\n\n" << '\n';

  std::cout << "OPCION: ";
  std::cin >> opcion;
  std::cin.ignore();
  std::cout << "\n\n";

  cout << "\nIntroduzca el primer entero: ";
  cin >> e1;
  cout << "\nIntroduzca el entero2 entero: ";
  cin >> e2;


  switch (opcion) {
    case 0: // SALIR
      std::cout << "Terminando ejecucion . . ." << '\n';
      std::cout << "\n\n\tPulse cualquier tecla para continuar" << '\n';
      std::cin.ignore();
    break;

    case 1: // SUMA
      aux = e1 + e2;

      std::cout << "\n\n----------------------------------------------" << '\n';
      std::cout << "RESULTADO (SUMA) = " << aux.getEntero() << '\n';
      std::cout << "----------------------------------------------\n\n" << '\n';
    break;

    case 2: // PRODUCTO
      aux = e1 * e2;

      std::cout << "\n\n----------------------------------------------" << '\n';
      std::cout << "RESULTADO (PRODUCTO) = " << aux.getEntero() << '\n';
      std::cout << "----------------------------------------------\n\n" << '\n';
    break;
  }

  system("clear");
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de la suma
Entero Entero::operator + (Entero e2) {
  std::string entero1 = this->getEntero();  // Primer entero
  std::string entero2 = a.getEntero();  // Segundo entero
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
        suma = stoi(pAux) + stoi(sAux);
      }
    }
    else if (p >= 0) {
      pAux = entero1[p];

      if (entero1[p] != '\0') {
        suma = stoi(pAux);
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
    res[i] = aux[res.length() - 1 - i];
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
  if (this->getTam() > a.getTam()) {
    n = this->getTam();
  }
  else {
      n = a.getTam();
  }

  // Operacion directa
	if (n <= 4) {
		Entero resultado(to_string(this->getEnteroInt() * a.getEnteroInt()));

		return resultado;
	}

  s = n / 2;

  // Creacion de los multiplos de 10
	diez_eS = "1";

  for (size_t i = 0; i < s; i++) {
    diez_eS.append("0");
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
	if (a.getTam() > s) {
		for (size_t i = 0; i < a.getEntero().length() - s; i++) {
			aux = a.getEntero()[i];
			y.append(aux);
		}

		for (size_t i = a.getEntero().length() - s; i < a.getEntero().length(); i++) {
			aux = a.getEntero()[i];
			z.append(aux);
		}
	}
	else {
		y = "0";

		for (size_t i = 0; i < a.getEntero().length(); i++) {
			aux = a.getEntero()[i];
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

// Sobrecarga del operador del producto con dos argumentos
Entero &Entero::operator + (Entero &e1,  Entero &e2) {
  int diferencia; // Diferencia de numero de digitos entre los enteros
  int acarreo = 0;
  std::string resStr;
  Entero *res;
  Entero auxE = new Entero();


  diferencia = e1.getTam() - e2.getTam();

  // Se agregan ceros delante del entero con menos digitos
  if (diferencia < 0) {
    agregarCerosDelante(getEntero(), abs(diferencia));
    setEntero(getEntero());
  }
  else if (diferencia > 0) {
    agregarCerosDelante(e2.getEntero(), diferencia);
    e2.setEntero(e2.getEntero());
  }

  resStr.resize(getTam() + 1);

  for (size_t i = e1.getTam() - 1; i >= 0; i--) {
    int suma = (e1.getEntero()[i] - '0') + (e2.getEntero()[i] - '0') + acarreo;

    if (suma < 10) {  // No hay acarreo
      resStr[i + 1] = (char)suma + 48;
      acarreo = 0;
    }
    else {  // Existe acarreo
      suma = suma % 10;
      resultado[i + 1] = (char)suma + 48;
      acarreo = 1;
    }
  }

  // Acarreo final
  if (acarreo == 1) {
    resStr[0] = '1';
  }
  else if (acarreo == 0) {
    resStr[0] = '0';
  }

  quitarCerosNoSignificativos(resStr);
  // cout<<"manada?"<<resultado<<endl;

  auxE.setEntero(resStr);
  std::cout << auxE.getEntero() << '\n';

  return auxE;
}

////////////////////////////////////////////////////////////////////////////////
