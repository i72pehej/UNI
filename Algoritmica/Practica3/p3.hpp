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
    void setTam(const int t);

  public:
    Entero ();  // Constructor
    // virtual ~Entero (); // Destructor

    // Observadores
    std::string getEnteroString();
    int getEnteroInt();
    int getTamMax();
    bool es_numero(const std::string &s);

    // Modificadores
    void setEntero(const std::string str);
    void colocar_ceros(Entero &e1, const int cant);

    // Sobrecarga de operadores
    Entero operator + (const Entero e2);
    Entero operator * (const Entero e2);
};

////////////////////////////////////////////////////////////////////////////////

// Operadores externos
std::istream &operator >> (std::istream &stream, Entero &entrada);
std::ostream &operator << (std::ostream &stream, Entero &salida);

////////////////////////////////////////////////////////////////////////////////


#endif
