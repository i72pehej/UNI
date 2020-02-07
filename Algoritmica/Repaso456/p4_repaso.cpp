void GreedyMethod::apply() {

  // Declara variables para los errores totales
  long double error1 = 0, error2 = 0, error3 = 0;

  // Vector de puntos dominantes deseados
  std::vector<int> puntosDominantes(getNumberPointsPolygonalAproximation());


  // Calcular los sumatorios
  calculateSummations();

  // Elimina los puntos colineares
  collinearPointsElimination();

  // Se seleccionan los puntos dominantes en función a los que se desean aproximar
  int iteradorDominantes = getDominantPointsPosition().size() / (getNumberPointsPolygonalAproximation() - 1);

  for (size_t i = 0; i < getDominantPointsPosition().size(); i+=iteradorDominantes) {
    puntosDominantes.push_back(getDominantPointsPosition()[i]);
  }

  // Se introducen como dominantes
  setDominantPoints(puntosDominantes);

  // Se itera por los puntos dominantes seleccionados para mejorar la posicion de los mismos
  // Se comienza en el primer punto, ya que el 0 y ultimo son el mismo y se tratarán después
  for (size_t i = 1; i < puntosDominantes.size(); i++) {
    error1 = calculateISE(getDominantPointsPosition()[i - 1], getDominantPointsPosition()[i]) + calculateISE(getDominantPointsPosition()[i], getDominantPointsPosition()[i + 1]);

    // Se itera por las posiciones intermedias candidatas a ser dominantes
    for (size_t j = getDominantPointsPosition()[i - 1]; j < getDominantPointsPosition()[i + 1]; j++) {
      error2 = calculateISE(getDominantPointsPosition()[i - 1], j) + calculateISE(j, getDominantPointsPosition()[i + 1]);

      // Se modifica el error inicial y el punto dominante actual por el de menor error
      if (error1 > error2) {
        error1 = error2;
        puntosDominantes[i] = j;
      }
    }
  }
  setDominantPoints(puntosDominantes);

  // Para calcular el punto optimo 0 y ultimo, repetimos el proceso.
  // Se compara primero desde el penultimo hasta el ultimo, y despues, desde el 0 hasta el 1. Calculando tambien los errores de cada seccion (3 en este caso)

  // Calcula el error desde el penultimo punto hasta el 1
  error1 = calculateISE(getDominantPointsPosition()[puntosDominantes.size() - 1], getDominantPointsPosition()[puntosDominantes.size()]) + calculateISE(getDominantPointsPosition()[0], getDominantPointsPosition()[1]);

  // Se itera por los puntos dominantes seleccionados para mejorar la posicion de los mismos
  // Se comienza en el ultimo punto
  for (size_t j = getDominantPointsPosition()[puntosDominantes.size() - 1]; j < getDominantPointsPosition()[puntosDominantes.size()]; j++) {
    error2 = calculateISE(getDominantPointsPosition()[puntosDominantes.size() - 1], j) + calculateISE(j, getDominantPointsPosition()[puntosDominantes.size()]);

    // Se itera por las posiciones intermedias candidatas a ser dominantes
    for (size_t k = 0; k < getDominantPointsPosition()[1]; k++) {
      error3 = calculateISE(getDominantPointsPosition()[0], k) + calculateISE(k, getDominantPointsPosition()[1]);

      // Se modifica el error inicial y el punto dominante 0 y ultimo ya que son iguales
      if (error1 > error2) {
        error1 = error2;
        puntosDominantes[0] = j;
        puntosDominantes[puntosDominantes.size()] = j;
      }

      // Se debe comparar tambien si hay algun punto mejor entre candidatos de 0 a 1
      if (error1 > error3) {
        error1 = error3;
        puntosDominantes[0] = k;
        puntosDominantes[puntosDominantes.size()] = k;
      }
    }
  }
  setDominantPoints(puntosDominantes);

  // Se calcula la aproximacion
  calculatePolygonalApproximation();
}
