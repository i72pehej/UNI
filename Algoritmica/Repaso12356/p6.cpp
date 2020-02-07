bool lugar(int k, std::vector<int> v) {

  for (size_t i = 1; i < k; i++) {
    if ((x[i] == x[k]) || (std::abs((x[i] - x[k])) == (std::abs(i - k)))) {
      return false;
    }
  }

  return true;
}

//////////////////////////////////////////////////////////////////////////////////


std::vector<std::vector<int>> backtracking8Reinas(int nReinas) {

  std::vector<int> x(nReinas+1);

  std::vector<std::vector<int>> solucion(nReinas+1, std::vector<int>(nReinas+1));

  int contador = 0;


  int k = 1;
  while (k > 0) {

    x[k] ++;

    while ((x[k] <= n) && (lugar(k, x) == false)) {

      x[k] ++;

    }

    if (x[k] <= n) {
      if (k == n) {

        contador++;

        for (size_t i = 1; i <= k; i++) {

          if (x[i] != 0) {
            solucion[i][x[i]] = 1;
          }
        }

      }

      else {
        k++;
        x[k] = 0;
      }
    }

    else {
      k--;
    }
  }

  return solucion;
}


//////////////////////////////////////////////////////////////////////////////////////////


std::vector<std::vector<int>> lasVegas8Reinas(int nReinas, bool exito) {

  int contador = 0, columna;

  std::vector<int> x(nReinas+1), ok(nReinas+1);
  std::vector<std::vector<int>> solucion(n+1, std::vector<int>(n+1));

  for (size_t i = 1; i <= nReinas; i++) {
    x[i] = 0;
  }

  for (size_t k = 1; k <= nReinas; k++) {
    contador = 0;

    for (size_t j = 1; j <= nReinas; j++) {
      x[k] = j;

      if (lugar(k, x) == true) {
        contador++;
        ok[contador] = j;
      }
    }

    if (contador != 0) {
      columna = ok[1 + rand()%contador];
      solucion[k][columna] = 1;
      x[k] = columna;
    }

    ok.clear();

  }

  if (contador = 0) {
    exito = false;
  }
  else {
    exito = true;
  }

  return solucion;

}
