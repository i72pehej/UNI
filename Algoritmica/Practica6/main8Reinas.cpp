#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "funciones8Reinas.hpp"


int main(int argc, char const *argv[]) {
  system("clear");

  int n; // Numero de reinas
  int k;  // Fila


  std::cout << "Introduzca el numero de reinas: ";
  std::cin >> n;
  std::cout << '\n';

  std::vector<int> x(n + 1); // Columna
  std::vector< std::vector<int> > m(n + 1, std::vector<int>(n + 1));

  k = 1;
  x[1] = 0;

  backtracking8Reinas(n, k, x, m);

  return 0;
}
