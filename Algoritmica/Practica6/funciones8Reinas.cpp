#include "funciones8Reinas.hpp"


////////////////////////////////////////////////////////////////////////////////

void imprimeMatriz8Reinas(std::vector< std::vector<int> > matriz8Reinas) {
  for (int i = 1; i < matriz8Reinas.size(); i++) {
    for (int j = 1; j < matriz8Reinas.size(); j++) {
      if (matriz8Reinas[i][j] == 1) {
        std::cout << "|X|";
      }
      else {
        std::cout << "| |";
      }
    }
    std::cout << '\n';
  }
}

////////////////////////////////////////////////////////////////////////////////

bool lugar(int k, std::vector<int> x) {
  for (int i = 1; i < k; i++) {
    if ((x[i] == x[k]) || (std::abs(x[i] - x[k]) == std::abs(i - k))) {
      return false;
    }
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////

void backtracking8Reinas(int n, int k, std::vector<int> x, std::vector< std::vector<int> > &matriz8Reinas) {
  int cont = 0;

  while (k > 0) {
    x[k] += 1;

    while ((x[k] <= n) && (lugar(k, x) == false)) {
      x[k] += 1;
    }

    if (x[k] <= n) {
      if (k == n) {
        cont++;
        std::cout << "SOLUCION = " << cont << '\n';
        matriz8Reinas[k][x[k]] = 1;

        imprimeMatriz8Reinas(matriz8Reinas);
        std::cout << "\n\n\n";
        matriz8Reinas[k][x[k]] = -1;
      }
      else {
        matriz8Reinas[k][x[k]] = 1;
        k++;
        x[k] = 0;
      }
    }
    else {
      k -= 1;
      matriz8Reinas[k][x[k]] = -1;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
