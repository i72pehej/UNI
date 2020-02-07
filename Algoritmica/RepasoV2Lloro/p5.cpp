void DynamicProgrammingMethod::rellenarMatrizFathers() {

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


std::vector<int> DynamicProgrammingMethod::fathersToDominantes() {

  long double puntoPredecesor;
  std::vector<int> vecDominantes;

  vecDominantes.pusch_back(puntosCurvaOriginal);
  puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];

  vecDominantes.pusch_back(puntoPredecesor);

  for (size_t i = puntosParaAproximar-1; puntoPredecesor > 1; i--) {
    vecDominantes.pusch_back(matrizFathers[puntoPredecesor][i]);
    puntoPredecesor = matrizFathers[puntoPredecesor][i];
  }

  std::reverse(vecDominantes.begin(), vecDominantes.end());

  return vecDominantes;
}


////////////////////////////////////////////////////////////////////////////////////


void rellenarMatrizFathers() {

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


std::vector<int> fathersToDominantes() {

  long double puntoPredecesor;
  std::vector<int> vecDominantes;


  vecDominantes.pusch_back(puntosCurvaOriginal);
  puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];
  vecDominantes.pusch_back(puntoPredecesor);

  for (size_t i = puntosParaAproximar-1; puntoPredecesor > 1; i--) {
    vecDominantes.push_back(matrizFathers[puntoPredecesor][i]);
    puntoPredecesor = matrizFathers[puntoPredecesor][i];
  }

  std::reverse(vecDominantes.begin(), vecDominantes.end());

  return vecDominantes;

}


////////////////////////////////////////////////////////////////////////////////////////
