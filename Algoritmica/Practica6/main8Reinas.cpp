#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "funciones8Reinas.hpp"


int main(int argc, char const *argv[]) {
  system("clear");

  int opcion; // Opcion para elegir el metodo
  int soluciones; // Numero de soluciones al metodo
  int n; // Numero de reinas
  int k;  // Fila


  std::cout << "Seleccione el metodo" << '\n';
  std::cout << "\t[1] --- BACTRACKING" << '\n';
  // std::cout << "\t[2] --- LAS VEGAS" << '\n';
  // std::cout << "\t[3] --- OTROS" << '\n';
  std::cout << "\nOPCION: ";
  std::cin >> opcion;
  std::cin.ignore();

  switch (opcion) {
    case 1: // BACTRACKING
      std::cout << "Introduzca el numero de reinas: ";
      std::cin >> n;
      std::cout << '\n';

      std::vector<int> x(n + 1); // Columna
      std::vector< std::vector<int> > m(n + 1, std::vector<int>(n + 1));  // Matriz de soluciones

      k = 1;  // Primera reina en fila 1
      x[k] = 0; // Primera reina en columna 0

      soluciones = backtracking8Reinas(n, k, x, m);

      std::cout << "\n\tHay " << soluciones << " soluciones.\n" << '\n';
    break;

    // case 2: // LAS VEGAS
    // break;
    //
    // case 3:
    // break;
  }


  return 0;
}
