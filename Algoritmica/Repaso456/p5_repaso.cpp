void DynamicProgrammingMethod::apply() {
  int puntosCurvaOriginal = getOriginalCurve().getNumberPointsDigitalCurve();
  int puntosParaAproximar = getNumberPointsPolygonalApproximation();

  int error1 = 0, error2 = 0;

  int pruntoPredecesor;
  std::vector<int> vecDominantes;

  std::vector< std::vector<long double> > matrizErrores (puntosCurvaOriginal + 1, std::vector<long double> (puntosParaAproximar + 1));
  std::vector< std::vector<long double> > matrizFathers (puntosCurvaOriginal + 1, std::vector<long double> (puntosParaAproximar + 1));


  // Calcular sumatorios
  calculateSummations();

  // Se rellena la matriz de errores con los errores base conocidos
  matrizErrores[1][1] = 0;  // 1,1 a 0
  for (size_t i = 2; i <= puntosCurvaOriginal; i++) {
    matrizErrores[i][1] = std::numeric_limits<long double>::max();  // Primera columna a infinito
  }

  // Rellenar la matriz de fathers con los padres de cada posicion, calculando el error más optimo
  for (size_t m = 2; m <= puntosParaAproximar; m++) {
    for (size_t n = m; n <= puntosCurvaOriginal; n++) {
      error1 = matrizErrores[m - 1][m - 1] + calculateISEValue(m - 2, n - 1);
      matrizFathers[n][m] = m - 1;

      for (size_t j = m; j < n - 1; j++) {
        error2 = matrizErrores[j][m - 1] + calculateISEValue(j - 1, n - 1);

        if (error1 > error2) {
          error1 = error2;
          matrizFathers[n][m] = j;
        }

        matrizErrores[n][m] = error1;
      }
    }
  }

  // Transformar la matriz de fathers en un vector de dominantes
  vecDominantes.push_back(puntosCurvaOriginal - 1);
  puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];
  vecDominantes.push_back(puntoPredecesor - 1);

  for (size_t i = puntosParaAproximar - 1; 1 < puntoPredecesor; i--) {
    vecDominantes.push_back(matrizFathers[puntoPredecesor][i] - 1);
    puntoPredecesor = matrizFathers[puntoPredecesor][i];
  }
  std::reverse(vecDominantes.begin(), vecDominantes.end());

  // Asignar dominantes
  setDominantPointsPosition(vecDominantes);

  // Clalcular aproximacion
  calculatePolygonalApproximation();
}
