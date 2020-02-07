void sumatorioX() {
  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {
      sumatorio = 0;

      for (size_t k = 0; k < n.size(); k++) {
        sumatorio += pow(n[k], i+j);
      }

      A[i][j] = sumatorio;
    }
  }
}

void sumatorioY() {
  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    sumatorio = 0;

    for (size_t j = 0; j < n.size(); j++) {
      sumatorio += tiemposReales * pow(n[j], i);
    }

    B[i][0] = sumatorio;
  }
}

// ---------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------


void ajusteNlogN() {

  for (size_t i = 0; i < n.size(); i++) {
    nlog.push_back(n[i] * log10(n[i]));
  }

  sumatorioX();
  sumatorioY();

  resolverSistemaEcuaciones();

  a0 = X[0][0];
  a1 = X[1][0];
}

// ------------------------------------------------------------------------------------


void calcularTiempoEstimados() {
  for (size_t i = 0; i < count; i++) {
    tiemposEstimados.push_back(a0 + (a1 * pow(n[i], 1)) + (a2 * pow(n[i], 2)));
  }
}





///////////////////////////////////////////////////////////////////////////////////

void sumatorioX() {
  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {

      sumatorio = 0;

      for (size_t k = 0; k < n.size(); k++) {
        sumatorio += pow(n[k], i+j);
      }

      A[i][j] = sumatorio;
    }
  }
}

void sumatorioY() {

  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    sumatorio = 0;

    for (size_t j = 0; j < n.size(); j++) {
      sumatorio += (tiemposReales * pow(n[j], i))
    }

    B[i][0] = sumatorio;
  }

}

void ajusreNlogN() {

  for (size_t i = 0; i < n.size(); i++) {
    nlogn.push_back(n[i] * log10(n[i]));
  }


  sumatorioX();
  sumatorioY();
  resolverSistemaEcuaciones();

  a0 = X[0][0];
  a1 = X[1][0];

}

void calcularTiempoEstimados() {

  for (size_t i = 0; i < n.size(); i++) {
    tiemposEstimados.push_back(a0 + (a1 * n[i]) + (a2 * pow(n[i], 2)));
  }


}


////////////////////////////////////////////////////////////////////////////////////////////
void sumatorioX() {

  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {
      sumatorio = 0;

      for (size_t k = 0; k < n.size(); k++) {
        sumatorio += pow(n[k], i+j);
      }

      A[i][j] = sumatorio;
    }
  }

}

void sumatorioY() {

  int sumatorio = 0;

  for (size_t i = 0; i < m; i++) {
    sumatorio = 0;

    for (size_t k = 0; k < n.size(); k++) {
      sumatorio += tiemposEstimados * pow(n[k], i);
    }

    B[i][0] = sumatorio;
  }

}

void ajusreNlogN() {

  for (size_t i = 0; i < n.size(); i++) {
    nlogn = n[i] * log10(n[i]);
  }

  sumatorioX();
  sumatorioY();
  resolverSistemaEcuaciones();

  a0 = X[0][0];
  a1 = X[1][0];
}

void calcularTiempoEstimados() {

  for (size_t i = 0; i < n.size(); i++) {
    tiemposEstimados.push_back(a0 + a1*n[i] + a2*pow(n[i], 2));
  }

}
