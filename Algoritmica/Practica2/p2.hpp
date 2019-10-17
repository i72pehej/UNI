#ifndef P2_HPP
#define P2_HPP


////////////////////////////////////////////////////////////////////////////////

// Imprime el camino que se reconoce de la matriz
void imprimeMatriz(const std::vector< std::vector<int> > &m) {
  system("clear");  // Se limpia la terminal

  int opt; // Opcion

  std::cout << "Would you desire to show the paths?" << '\n';
  std::cout << "(1) ------ YES\n(2) ------ NO" << '\n';
  std::cin >> opt;



  std::cout << "Camino: ";
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m.size(); j++) {
      // Posicion del movimiento de la ficha
      if (m[i][j] == 1) {
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


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// Funcion para calcular los caminos posibles comenzando desde el final
void calcularCaminos(const int fila, const int columna, int &nCaminos, std::vector< std::vector<int> > &m) {
  // Si se llega al principio del tablero, se ha encontrado un camino
  if (fila == 0) {
    m[fila][columna] = 1;   // Asignamos posicion valida
    // imprimeMatriz(m);
    m[fila][columna] = -1;  // Reincio del valor para continuar la busqueda del camino

    nCaminos++;
  }

  // Se realiza la comprobacion de caminos con las 4 posibles posiciones de las
  else {
    m[fila][columna] = 1; // Colocamos

    // Posicion 1
    if (columna > 1) {  // Evita que salga del tablero
      calcularCaminos(fila - 1, columna - 2, nCaminos, m);
    }

    // Posicion 2
    if ((fila > 1) && (columna > 0)) {  // Evita que salga del tablero
      calcularCaminos(fila - 2, columna - 1, nCaminos, m);
    }

    // Posicion 3
    if ((fila > 1) && (columna < 7)) {  // Evita que salga del tablero
      calcularCaminos(fila - 2, columna + 1, nCaminos, m);
    }

    // Posicion 4
    if (columna < 6) {  // Evita que salga del tablero
      calcularCaminos(fila - 1, columna + 2, nCaminos, m);
    }
  }

  m[fila][columna] = -1;
}












#endif
