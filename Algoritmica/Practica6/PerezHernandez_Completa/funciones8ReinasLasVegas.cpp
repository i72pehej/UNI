#include "funciones8ReinasLasVegas.hpp"


////////////////////////////////////////////////////////////////////////////////

std::vector<int> repetirLasVegas(int n, int k, std::vector<int> x, int &intentos) {
  bool exito;

  do {
    exito = lasVegas8Reinas(n, k, x, exito);

    intentos++;
  } while(exito != true);

  return x;
}

////////////////////////////////////////////////////////////////////////////////

bool lasVegas8Reinas(int n, int k, std::vector<int> &x, bool &exito) {
// int lasVegas8Reinas(int n, int k, std::vector<int> x, std::vector< std::vector<int> > &matriz8Reinas) {
  int cont = 0, imprimir = 0; // Contador y variable para imprimir las soluciones
  int columna;  // Variable auxiliar para almacenar la columna

  // bool exito = false; // Variable que controla la repeticion de LAS VEGAS

  std::vector<int> ok(n + 1); // Vector donde se guarda la posicion de una reina no amenazada


  // Inicializamos la solucion a 0
  for (int i = 1; i < n; i++) {
    x[i] = 0;
  }

  // Se han colocado k-1 reinas y se buscan todas las posiciones para la k-esima
  for (int k = 1; k <= n; k++) {
    cont = 0;

    // Almacena todas las posiciones posibles de la reina k en el vector x[]
    for (int j = 1; j <= n; j++) {
      x[k] = j; // Se prueba la reina k en la columna j

      // Si se puede colocar en la columna
      if (lugar(k, x) == true) {
        cont++; // Se halla una solucion
        ok[cont] = j;  // Se guarda la posicion encontrada
      }
    }

    // Salir en caso de no encontrar ninguna posicion para la reina
    if (cont == 0) {
      break;
    }

    // Se puede colocar la reina k y se selecciona una posicion aleatoria
    // columna = ok[uniforme(1, cont)];
    columna = ok[(rand() % cont) + 1];
    x[k] = columna;
  }

  if (cont == 0) {
    exito = false;  // No hay solucion
  }
  else {
    exito = true; // Hay solucion
  }

  system("clear");
  return exito;
}

////////////////////////////////////////////////////////////////////////////////
