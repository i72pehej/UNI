void calcularCamino(int fila, int columna, int contador, std::vector<std::vector<int>> matriz) {

  if (fila == 0) {//Encuentra un camino, colocamos el valor 1 se imprime y reinicia valor
    contador++;
    m[fila][columna] = 1;

    std::cout << "/* message */" << '\n';

    m[fila][columna] = -1;
  } else {
    m[fila][columna] = 1;

    if (columna > 1) {
      calcularCamino(fila-1, columna-2, contador, m);
    }

    if ((fila > 1) && (columna > 0)) {
      calcularCamino(fila-2, columna-1, contador, m);
    }

    if ((fila > 1) && (columna < 7)) {
      calcularCamino(fila-2, columna+1, contador, m);
    }

    if (columna < 6) {
      calcularCamino(fila-1, columna+2, contador, m);
    }
  }

  m[fila][columna] = -1;
}


/////////////////////////////////////////////////////////////////////////////////

void imprimeMatriz() {

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = (m.size()-1); j > -1; j--) {
      if (m[i][j] == 1) {
        std::cout << "/* message */" << '\n';
      } else {
        std::cout << "/* message */" << '\n';
      }
    }
    std::cout << '\n';
  }

}
