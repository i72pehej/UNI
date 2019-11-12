#ifndef P3_HPP
#define P3_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cmath>

#include "funcionesbajonivel.cpp"

using namespace std;


////////////////////////////////////////////////////////////////////////////////

// Clase que representa un entero grande
class Entero {
  private:
    string entero_; // Numero entero en formato de string
    int tamMin_; // Tamaño minimo del entero grande

  public:

    ////////////////////////// CONSTRUCTOR /////////////////////////////////////
    inline Entero (string cad = "") {
      setEntero(cad);
    }

    ////////////////////////////// OBSERVADORES ////////////////////////////////
    inline string getEntero() {
      return entero_;
    }

    inline int getEnteroInt() {
      return (atoi(this->getEntero().c_str()));
    }

    inline int getTamMin() {
      return tamMin_;
    }

    inline int getTam() {
      string entero = this->getEntero();

      return (entero.length() - 1);
    }

    inline int es_cero() {
      string entero = this->getEntero();
      string aux;

      for (size_t i = 0; i < entero.length(); i++) {
        if (entero[i] != '\0') {
          aux = entero[i];
          int auxInt = atoi(aux.c_str());

          if (auxInt != 0) {
            return 0;
          }
        }
      }

      return 1;
    }

    ////////////////////////////// MODIFICADORES ///////////////////////////////
    inline void setEntero(const string cad) {
      entero_ = cad;
    }

    ////////////////////////////// SOBRECARGA //////////////////////////////////
    Entero operator + (Entero e2);
    Entero operator * (Entero e2);

    friend inline istream &operator >> (istream &stream, Entero &entrada) {
      stream >> entrada.entero_;

      return stream;
    }

    friend inline ostream &operator << (ostream &stream, Entero &salida) {
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
