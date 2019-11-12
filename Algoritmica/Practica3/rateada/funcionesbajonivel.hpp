#ifndef FUNCIONES_BAJO_NIVEL
#define FUNCIONES_BAJO_NIVEL

#include <iostream>

//Esta función reserva una cadena de n caracteres y devuelve un puntero a la misma.
std::string reservarCadena(int n);

//Esta función divide la cadena c en dos subcadenas c1 y c2, siendo ambas del mismo tamaño cuando el número de caracteres de c es par
//y c1 tendrá un caracter más cuando c tenga un número impar de caracteres.
void partirCadena(std::string s, std::string &s1, std::string &s2);

//Esta función añade tantos ceros como indica nCeros al final del número almacenado en la cadena c
void agregarCerosFinal(std::string &c, int nCeros);

//Esta función añade tantos ceros como indica nCeros al principio del número almacenado en la cadena c
void agregarCerosDelante(std::string &c, int nCeros);

//Esta función elimina todos los ceros que hay al principio del número almacenado en la cadena c
void quitarCerosNoSignificativos(std::string &c);

void AgregarCeros(std::string & cadena, int c);
//Esta función devuelve una cadena que contendrá el número resultante de multiplicar el número almacenado en la cadena c por 10 elevado a potencia.
std::string multiplicarPotencia10( const std::string  &c, int potencia);

#endif
