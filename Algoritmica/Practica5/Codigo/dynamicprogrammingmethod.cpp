#include <vector>    // necesario para el contenedor vector
#include <limits>
#include "algorithm.hpp"
#include "digitalcurve.hpp"
#include "dynamicprogrammingmethod.hpp"
//#include "heapvectorMasood.hpp"
//#include "nodoMasood.hpp"

using namespace std;



//Constructor.
DynamicProgrammingMethod::DynamicProgrammingMethod(char *fileName, int numberPointsPolygonalApproximation) {
  //A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);

  //Digital curve as saved as original curve
  setOriginalCurve(dc);

  //Set the number of points of the polygonal approximation
  setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
DynamicProgrammingMethod::~DynamicProgrammingMethod() {}

////////////////////////////////////////////////////////////////////////////////

int minimoError(int i, int j) {

}

////////////////////////////////////////////////////////////////////////////////

void DynamicProgrammingMethod::apply() {
	long double error1, error2;	// Errores entre las aproximaciones seleccionadas
	long double pre;	// Valor para el predecesor de la aproximacion deseada
	std::vector<int> vecDominantes;	// Vector de puntos dominantes
	std::vector< std::vector<long double> > E;	// Matriz de errores acumulados
	std::vector< std::vector<long double> > fathers;	// Matriz de puntos predecesores
	int N = getOriginalCurve().getNumberPointsDigitalCurve();	// Numero de puntos de la curva original
	int M = getNumberPointsPolygonalApproximation();	// Numero de puntos con los que se quiere aproximar


	// Se calculan los sumatorios para los errores
	calculateSummations();

	// Se asignan los tamaños de las matrices
	E.resize(N + 1, std::vector<long double> (M + 1));
	fathers.resize(N + 1, std::vector<long double> (M + 1));

	// Se asignan los valores de los casos particulares de errores acumulados
	E[1][1] = 0;
	for (int i = 2; i <= N; i++) {
		E[i][1] = std::numeric_limits<long double>::max();	// Infinito
	}

	// Se itera por los valores de "m"
	for (int m = 2; m <= M; m++) {
		// Se itera por los valores de "n"
		for (int n = m; n <= N; n++) {
			error1 = E[m - 1][m - 1] + calculateISEValue(m - 2, n - 1);	// Se calcula el primer valor del error acumulado de la aproximacion
			fathers[n][m] = m - 1;	// Se asigna el predecesor al punto aproximado

			// Se calcula el minimo valor de error acumulado
			for (int j = m; j < n - 1; j++) {
				error2 = E[j][m - 1] + calculateISEValue(j - 1, n - 1); // Siguientes valores del conjunto de errores para cada valor de "n"

				if (error1 > error2) {
					error1 = error2;	// Se asigna el nuevo error
					fathers[n][m] = j;	// Se asigna el nuevo predecesor
				}

				E[n][m] = error1;	// Se asigna el minimo error acumulado
			}
		}
	}

	// Se insertan en orden los valores de la matriz de puntos predecesores en el vector de puntos dominantes
	vecDominantes.insert(vecDominantes.begin(), N - 1);	// Se inserta el ultimo punto dominante, correspondiente al ultimo punto de la curva

	pre = fathers[N][M];	// Se asigna el valor de la aproximacion inicial deseada
	vecDominantes.insert(vecDominantes.begin(), pre - 1);	// Se inserta el predecesor al punto de la aproximacion

	for (int j = M - 1; 1 < pre; j--) {
		vecDominantes.insert(vecDominantes.begin(), fathers[pre][j] - 1);
		pre = fathers[pre][j];
	}

// ?¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
	for (size_t t = 0; t < count; t++) {
		vecDominantes.push_back();
	}
	std::reverse(vecDominantes.begin(), vecDominantes.end());


	// Se asigna el vector de puntos dominantes final al objeto actual
	setDominantPointsPosition(vecDominantes);

////////////////////////////////////////////////////////////////////////////////

	// Se calcula la aproximacion poligonal
	calculatePolygonalApproximation();
}

////////////////////////////////////////////////////////////////////////////////
