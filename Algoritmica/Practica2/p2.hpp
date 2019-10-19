#ifndef P2_HPP
#define P2_HPP


////////////////////////////////////////////////////////////////////////////////

// Imprime el camino que se reconoce de la matriz
void imprimeMatriz(const std::vector< std::vector<int> > &m, const int n) {
  system("clear");  // Se limpia la terminal

  std::cout << "Camino: " << n << '\n';
  for (int j = 0; j < m.size(); j++) {
    for (int i = (m.size() - 1); i > -1; i--) {
      // Posicion del movimiento de la ficha
      if (m[j][i] == 1) {
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

// Imprime el camino que se reconoce de la matriz inversamente
void imprimeMatrizInversa(const std::vector< std::vector<int> > &m, const int n) {
  system("clear");  // Se limpia la terminal

  std::cout << "Camino: " << n << '\n';
  for (int i = (m.size() - 1); i > -1; i--) {
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

// Funcion para calcular los caminos posibles comenzando desde el final
void calcularCaminos(const int fila, const int columna, int &nCaminos, std::vector< std::vector<int> > &m, const int opt) {
  // Si se llega al principio del tablero, se ha encontrado un camino
  if (fila == 0) {
    nCaminos++; // Incremento del contador de caminos
    m[fila][columna] = 1; // Asignamos posicion valida

    if (opt == 1) { // Se muestran los caminos
      imprimeMatrizInversa(m, nCaminos); // Imprime los caminos
      std::cout << "\n\n\n\tPulse INTRO para continuar . . ." << '\n';
      std::cin.ignore();
    }
    else if (opt == 2) {
      imprimeMatriz(m, nCaminos); // Imprime los caminos
      std::cout << "\n\n\n\tPulse INTRO para continuar . . ." << '\n';
      std::cin.ignore();
    }

    m[fila][columna] = -1;  // Reincio del valor para continuar la busqueda del camino
  }

  // Se realiza la comprobacion de caminos con las 4 posibles posiciones de las
  else {
    m[fila][columna] = 1; // Colocamos

    // Posicion 1
    if (columna > 1) {  // Evita que salga del tablero
      calcularCaminos(fila - 1, columna - 2, nCaminos, m, opt);
    }

    // Posicion 2
    if ((fila > 1) && (columna > 0)) {  // Evita que salga del tablero
      calcularCaminos(fila - 2, columna - 1, nCaminos, m, opt);
    }

    // Posicion 3
    if ((fila > 1) && (columna < 7)) {  // Evita que salga del tablero
      calcularCaminos(fila - 2, columna + 1, nCaminos, m, opt);
    }

    // Posicion 4
    if (columna < 6) {  // Evita que salga del tablero
      calcularCaminos(fila - 1, columna + 2, nCaminos, m, opt);
    }
  }

  m[fila][columna] = -1;
}

////////////////////////////////////////////////////////////////////////////////

#endif
