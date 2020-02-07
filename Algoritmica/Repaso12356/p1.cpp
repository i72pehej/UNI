// Funcion comprobar siestá ordenado
bool ordenado(const std::vector<int> vec) {

  for (int i = 0; i < vec.size(); i++) {

    #ifndef NDEBUG
      assert(vec[i - 1] <= vec[i]);
    #endif

    if (vec[i-1] > vec[i]) {
      return false;
    }

  }

  return true;
}

//////////////////////////////////////////////////////////////////////////////////

// Funciones de los sumatorios
void sumatorioX(int m, std::vector<double> n, std::vector< std::vector<double> > A) {

  A.clear();
  A.resize(m, std::vector<double>(m));
  // std::vector< std::vector<double> > A(filas, std::vector<double>(columnas));

  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {
      sumatorio = 0;

      for (size_t k = 0; k < n.size(); k++) {
        sumatorio += pow(n[k], i + j);
      }

      A[i][j] = sumatorio;
    }
  }
}


void sumatorioY(int m, std::vector<double> n, std::vector<double> &tiemposReales, std::vector< std::vector<double> > B) {

  B.clear();
  B.resize(m, std::vector<double>(m));
  // std::vector< std::vector<double> > A(filas, std::vector<double>(columnas));

  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    sumatorio = 0;

    for (size_t j = 0; j < n.size(); j++) {
      sumatorio += tiemposReales[j] * pow(n[j], i);
    }

    B[i][0] = sumatorio;
  }
}

//////////////////////////////////////////////////////////////////////////////////

void ajusteNlogN(std::vector<double> n, std::vector<double> tiemposReales, double a0, double a1) {

  std::vector<double> nlog;
  std::vector<std::vector<double>> A;
  std::vector<std::vector<double>> B;
  std::vector<std::vector<double>> X(2, std::vector<double>(2));


  for (size_t i = 0; i < n.size(); i++) {
    nlog.push_back(n[i] * log10(n[i]));
  }

  sumatorioX(2, nlog, A);

  sumatorioY(2, nlog, tiemposReales, B);

  resolverSistemaEcuaciones(A, B, 2, X);

  a0 = X[0][0];
  a1 = X[1][0];
}

///////////////////////////////////////////////////////////////////////////////////////

void calcularTiemposEstimadosNlogN(std::vector<double> n, std::vector<double> tiemposReales, double a0, double a1, std::vector<double> tiemposEstimados) {

  std::vector<double> nlog;

  for (size_t i = 0; i < n.size(); i++) {
    nlog.push_back(n[i] * log10(n[i]));
    tiemposEstimados.push_back(a0 + (a1 * nlog[i]));
  }

}

double calcularTiempoEstimadosNlogN() { // Con un N que pasa el usuario.

  double tiempoEstimados = 0;

  tiemposEstimados = a0 + (a1 * n * log10(n));

  return tiempoEstimados;
}

////////////////////////////////////////////////////////////////////////////////////

void ajustePolinomico(std::vector<double> n, std::vector<double> tiemposReales, std::vector<double> a) {

  std::vector<std::vector<double>> A;
  std::vector<std::vector<double>> B;
  std::vector<std::vector<double>> X(3, std::vector<double>(3));
  a.resize(3);

  sumatorioX(3, n A);

  sumatorioY(3, n tiemposReales, B);

  resolverSistemaEcuaciones(A, B, 3, X);

  a[1] = X[0][0];
  a[2] = X[1][0];
  a[3] = X[2][0];
}

/////////////////////////////////////////////////////////////////////////////////////

void calcularTiemposEstimadosPolinomicos(std::vector<double> n, std::vector<double> tiemposReales, std::vector<double> a, std::vector<double> tiemposEstimados) {

  for (size_t i = 0; i < n.size(); i++) {
    tiemposEstimados.push_back(a[0] + (a[1] * n[i]) + (a[2] * pow(n[i], 2)));
  }
}


double calcularTiempoEstimadosPolinomicos() {

  tiempoEstimado = a[0] + (a[1] * n[i]) + (a[2] * pow(n[i], 2));
}

//////////////////////////////////////////////////////////////////////////////////////
