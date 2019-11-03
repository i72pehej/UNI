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


  switch (opcion) {
    case 0: // SALIR
      std::cout << "Terminando ejecucion . . ." << '\n';
      std::cout << "\n\n\tPulse cualquier tecla para continuar" << '\n';
      std::cin.ignore();

      system("clear");
      return 0;
    break;

    case 1: // SUMA

    break;

    case 2: // PRODUCTO

    break;
  }

  system("clear");
  return 0;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// METODOS PRIVADOS ////////////////////////////////
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

// Funcion que asigna un valor entero a la variable tamMax_
void Entero::setTam(const int t) {
  tamMax_ = t;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////////////// METODOS PUBLICOS ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// Constructor de la clase Entero
Entero::Entero () {
  this->setEntero("");
  this->setTam(4);
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que devuelve el valor de la clase Entero en formato int
std::string Entero::getEnteroString() {
  return this->entero_;
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que devuelve el valor de la clase Entero en formato int
int Entero::getEnteroInt() {
  // int res = std::stoi(getEnteroString());
  // return res;
  return (std::stoi(this->getEnteroString(), NULL, 0));
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que devuelve el tamaño maximo del Entero
int Entero::getTamMax() {
  return this->tamMax_;
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que asigna un valor a la clase Entero
void Entero::setEntero(std::string str) {
  this->getEnteroString() = str;
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que añade ceros al comienzo del numero con menos digitos
void Entero::colocar_ceros(Entero &e1, const int cant) {
  std::string ceros = NULL;

  for (size_t i = 0; i < cant; i++) {
    ceros.push_back('0');
  }
  e1.setEntero(ceros + e1.getEnteroString());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////// SOBRECARGA DE OPERADORES ////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de la suma
Entero Entero::operator + (const Entero e2) {



}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador del producto
Entero Entero::operator * (const Entero e2) {
  int n;  // Mayor numero de digitos
  int s;  // Potencia a la que elevar 10
  Entero w, x, y, z; // Enteros grandes

  // Colocar ceros para que ambos numeros tengan el mismo numero de digitos
  if (this->getEnteroString().size() > e2.getEnteroString().size()) {
    n = this->getEnteroString().size();
    colocar_ceros(e2, (this->getEnteroString().size() - e2.getEnteroString().seize()));
  }
  else {
    n = e2.getEnteroString().size();
    colocar_ceros(this, (e2.getEnteroString().size() - this->getEnteroString().seize()));
  }

  if (n <= 4) { // Numero lo suficientemente pequeño
    return (this * e2);
  }
  else {  // Enteros grandes
    s = n / 2;
    w = this->getEnteroInt() / pow(10, s);
    x = this->getEnteroInt() % pow(10, s);
    y = e2.getEnteroInt() / pow(10, s);
    z = e2.getEnteroInt() % pow(10, s);

    return ((w * y * pow(10, 2 * s)) + (((w * z) + (x * y)) * pow(10, s)) + (x * z));
  }
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada (std::cin >>;)
std::istream &operator >> (std::istream &stream, Entero &entrada) {
  std::string enteroStr;

  std::cout << "Introduzca el numero: ";
  stream >> enteroStr;
  stream.ignore();

  while (!es_numero(enteroStr)) {  // Comprueba que los 4 valores sean numericos
    std::cout << "\n\nPor favor, introduzca un numero" << '\n';
    std::cout << "VALOR: ";
    stream >> enteroStr;
    stream.ignore();
  }

  entrada.setEntero(enteroStr);

  return stream;
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de salida (std::cout <<;)
std::ostream &operator << (std::ostream &stream, Entero &salida) {
  stream << salida.getEnteroInt();

  return stream;
}

////////////////////////////////////////////////////////////////////////////////
