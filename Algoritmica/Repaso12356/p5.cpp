void DynamicProgrammingMethod::apply() {

  int puntosCurvaOriginal = getOriginalCurve().getNumberPointsDigitalCurve();
  int puntosParaAproximar = getNumberPointsPolygonalApproximation();

  std::vector<std::vector<long double>> matrizErrores(puntosCurvaOriginal+1, std::vector<long double>(puntosParaAproximar+1));
  std::vector<std::vector<long double>> matrizFathers(puntosCurvaOriginal+1, std::vector<long double>(puntosParaAproximar+1));


  calculateSummations();


  rellenarMatrizErrores(puntosCurvaOriginal, matrizErrores);
  rellenarMatrizFathers(puntosCurvaOriginal, puntosParaAproximar, matrizErrores, matrizFathers);
  setDominantPointsPosition(fathersToDominantes(puntosCurvaOriginal, puntosParaAproximar, matrizFathers));


  calculatePolygonalApproximation();

}

////////////////////////////////////////////////////////////////////////////////////////////////

void DynamicProgrammingMethod::rellenarMatrizErrores(int const puntosCurvaOriginal, std::vector<std::vector<long double>> &matrizErrores) {
  matrizErrores[1][1] = 0;

  for (size_t i = 2; i <= puntosCurvaOriginal; i++) {
    matrizErrores[i][1] = std::numeric_limits<long double>::max();
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////


void DynamicProgrammingMethod::rellenarMatrizFathers(int const puntosCurvaOriginal, int const puntosParaAproximar, std::vector<std::vector<long double>> &matrizErrores, std::vector<std::vector<long double>> &matrizFathers) {

  long double error1, error2;

  for (size_t m = 2; m <= puntosParaAproximar; m++) {
    for (size_t n = m; n <= puntosCurvaOriginal; n++) {

      error1 = matrizErrores[m-1][m-1] + calculateISEValue(m-2, n-1);
      matrizFathers[n][m] = m;

      for (size_t j = m; j < n-1; j++) {

        error2 = matrizErrores[j][m-1] + calculateISEValue(j-1, n-1);

        if (error1 > error2) {
          error1 = error2;
          matrizFathers[n][m] = j;
        }

        matrizErrores[n][m] = error1;

      }
    }
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<int> DynamicProgrammingMethod::fathersToDominantes(int const puntosCurvaOriginal, int const puntosParaAproximar, std::vector<std::vector<long double>> &matrizFathers) {

  long double puntoPredecesor;
  std::vector<int> vecDominantes;


  vecDominantes.push_back(puntosCurvaOriginal-1);

  puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];
  vecDominantes.push_back(puntoPredecesor-1);

  for (size_t i = puntosParaAproximar-1; puntoPredecesor > 1; i--) {
    vecDominantes.push_back(matrizFathers[puntoPredecesor][j];
    puntoPredecesor = matrizFathers[puntoPredecesor][j];
  }

  std::reverse(vecDominantes.begin(), vecDominantes.end());

  return vecDominantes;

}
