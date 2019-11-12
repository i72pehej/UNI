#ifndef P3_HPP
#define P3_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>


////////////////////////////////////////////////////////////////////////////////

// Clase que representa un entero grande
class Entero {
  private:
    std::string entero_; // Numero entero en formato de string
    int tamMax_; // Tamaño maximo del entero

    // Funciones privadas
    bool es_numero(const std::string &s);
    int setTam(const int t);

  public:
    Entero ();  // Constructor
    virtual ~Entero (); // Destructor

    // Observadores
    std::string getEnteroString();
    int getEnteroInt();
    int getTamMax();

    // Modificadores
    void setEntero(const std::string str);
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// METODOS PRIVADOS ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

// Funcion que comprueba si un string contiene valores numericos
bool Entero::es_numero(const std::string &s) {
  std::string::const_iterator it = s.begin();

  while (it != s.end() && std::isdigit(*it)) {++it;}

  // Devuelve false cuando el string esta vacio y no se ha llegado al final
  // Devuelve true cuando el string no esta vacio y se ha llegado al final = son numeros
  return (!s.empty() && it == s.end());
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que asigna un valor entero a la variable tamMax_
void Entero::setTam(const int t) {
  getTamMax() = t;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////////////// METODOS PUBLICOS ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// Constructor de la clase Entero
Entero::Entero () {
  setEntero("");
  setTam(4);
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
  return (std::stoi(getEnteroString(), NULL, 0));
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que devuelve el tamaño maximo del Entero
int Entero::getTamMax() {
  return this->tamMax_;
}

////////////////////////////////////////////////////////////////////////////////

// Funcion que asigna un valor a la clase Entero
void Entero::setEntero(std::string str) {
  getEnteroString() = str;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////////////////////// SOBRECARGA DE OPERADORES ////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de la suma
Entero &operator +(Entero &res, const Entero e1, const Entero e2) {


  return res;
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador del producto
Entero &operator *(const Entero e2) {

  return e2;
  // return pow(w*y, 2s) + pow10(w*y + y*z, s);
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada (std::cin >>;)
istream &operator >>(Entero &entrada, istream &in) {
  cout << "Introduzca el numero: ";
  in >> entrada.getEntero();
  in.ignore();

  // while (in.size() != getTamMax()) {  // Comprueba que se introduzcan 4 valores
  //   std::cout << "\n\nPor favor, introduzca un numero de maximo 4 digitos" << '\n';
  //   std::cout << "VALOR: ";
  //   in >> entrada.getEntero();
  //   in.ignore();

    while (!es_numero(in)) {  // Comprueba que los 4 valores sean numericos
      std::cout << "\n\nPor favor, introduzca un numero" << '\n';
      std::cout << "VALOR: ";
      in >> entrada.getEntero();
      in.ignore();
    }
  }

  return in;
}

////////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de salida (std::cout <<;)
ostream &operator <<(const Entero salida, ostream &out) {
  out << salida.getEntero();

  return out;
}

////////////////////////////////////////////////////////////////////////////////





#endif
