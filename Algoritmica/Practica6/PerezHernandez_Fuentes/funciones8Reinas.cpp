#include "funciones8Reinas.hpp"


////////////////////////////////////////////////////////////////////////////////

void imprimeMatriz8Reinas(std::vector< std::vector<int> > matriz8Reinas) {
  for (int i = 1; i < matriz8Reinas.size(); i++) {
    for (int j = 1; j < matriz8Reinas.size(); j++) {
      if (matriz8Reinas[i][j] == 1) {
        std::cout << "|X";
      }
      else {
        std::cout << "| ";
      }
    }
    std::cout << "|\n";
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

int backtracking8Reinas(int n, int k, std::vector<int> x, std::vector< std::vector<int> > &matriz8Reinas) {
  int cont = 0, imprimir = 0; // Contador y variable para imprimir las soluciones

  std::cout << "¿Desea imprimir las soluciones?" << '\n';
  std::cout << "[0] --- NO" << '\n';
  std::cout << "[1] --- SI" << '\n';
  std::cout << "\n\nOPCION: ";
  std::cin >> imprimir;
  std::cin.ignore();

  // Mientras no se tengan todas las soluciones
  while (k > 0) {
    x[k] += 1;  // Se desplaza la reina a la siguiente columna

    // Mientras no se salga del tablero y sea amenazada por una reina anterior
    while ((x[k] <= n) && (lugar(k, x) == false)) {
      x[k] += 1;  // Se desplaza a la siguiente columna
    }

    // Se encuentra una posicion para la reina
    if (x[k] <= n) {
      // Es la ultima reina para colocar, es decir, se encuentra una solucion
      if (k == n) {
        cont++;
        matriz8Reinas[k][x[k]] = 1; // Se coloca un marcador en la posicion de la reina

        // Si se desea imprimir se llama a la funcion asociada
        if (imprimir == 1) {
          system("clear");

          std::cout << "SOLUCION nº" << cont << '\n';
          imprimeMatriz8Reinas(matriz8Reinas);

          std::cout << "\n\nPULSE INTRO PARA CONTINUAR . . ." << '\n';
          std::cin.ignore();
        }

        matriz8Reinas[k][x[k]] = -1;  // Se resetea el valor de la posicion de la matriz
      }
      // Se continua con la proxima reina
      else {
        matriz8Reinas[k][x[k]] = 1; // Se coloca un marcador en la posicion de la reina
        k++;  // Se incrementa la fila
        x[k] = 0; // Se resetea la columna
      }
    }
    // La reina no se puede colocar en la fila actual
    else {
      k--;  // Se retrocede a la fila anterior
      matriz8Reinas[k][x[k]] = -1;  // Se anula la posicion de la reina, ya que imposibilita la colocacion de la siguiente
    }
  }

  system("clear");
  return cont;
}

////////////////////////////////////////////////////////////////////////////////
