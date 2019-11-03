#ifndef P3_HPP
#define P3_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <cmath>
#include <iostream>

#include "funcionesbajonivel.cpp"



////////////////////////////////////////////////////////////////////////////////

// Clase que representa un entero grande
class Entero {
  private:
    std::string entero_; // Numero entero en formato de string
    int tamMin_; // Tamaño minimo del entero grande

  public:

    ////////////////////////// CONSTRUCTOR /////////////////////////////////////
    inline Entero (std::string cad = "") {
      setEntero(cad);
      setTam(4);
    }

    ////////////////////////////// OBSERVADORES ////////////////////////////////
    inline std::string getEntero() {
      return entero_;
    }

    inline int getEnteroInt() {
      return (std::atoi(this->getEntero().c_str()));
    }

    inline int getTamMin() {
      return tamMin_;
    }

    inline int getTam() const {
      std::string entero = this->getEntero();
      int i = 0, tam = 0;

      while (entero[i] != '\0') {
        tam++;
        i++;
      }

      return tam;
    }

    inline bool es_numero(const std::string &s) {
      std::string::const_iterator it = s.begin();

      while (it != s.end() && std::isdigit(*it)) {
        it++;
      }
      // Devuelve false cuando el string esta vacio y no se ha llegado al final
      // Devuelve true cuando el string no esta vacio y se ha llegado al final = son numeros
      return (!s.empty() && it == s.end());
    }

    inline int es_cero() {
      std::string entero = this->getEntero();
      std::string aux;

      for (size_t i = 0; i < count; i++) {
        /* code */
      }
    }

    ////////////////////////////// MODIFICADORES ///////////////////////////////
    inline void setEntero(const std::string cad) {
      entero_ = cad;
    }

    inline void setTam(int t) const {
      tamMax_ = t;
    }

    ////////////////////////////// SOBRECARGA //////////////////////////////////
    Entero operator + (Entero e2);
    Entero operator * (Entero e2);
    Entero &operator + (Entero &e1, Entero &e2);

    inline std::istream &operator >> (std::istream &stream, Entero &entrada) {
      std::string enteroStr;

      stream >> enteroStr;

      while (!es_numero(enteroStr)) {  // Comprueba que los 4 valores sean numericos
        std::cout << "\n\nPor favor, introduzca un numero valido" << '\n';
        std::cout << "VALOR: ";
        stream >> enteroStr;
      }

      entrada.setEntero(enteroStr);

      return stream;
    }

    inline std::ostream &operator << (std::ostream &stream, Entero &salida) {
      stream << salida.getEntero();

      return stream;
    }

    inline Entero operator = (Entero e2) {
      this->setEntero(e2.getEntero());

      return *this;
    }
  };

////////////////////////////////////////////////////////////////////////////////



#endif
