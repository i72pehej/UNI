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
	int puntosCurvaOriginal = getOriginalCurve().getNumberPointsDigitalCurve();	// Numero de puntos de la curva original
	int puntosParaAproximar = getNumberPointsPolygonalApproximation();	// Numero de puntos con los que se quiere aproximar

	long double error1, error2;	// Errores entre las aproximaciones seleccionadas
	long double puntoPredecesor;	// Valor para el predecesor de la aproximacion deseada

	std::vector<int> vecDominantes;	// Vector de puntos dominantes

	std::vector< std::vector<long double> > matrizErrores(puntosCurvaOriginal + 1, std::vector<long double>(puntosParaAproximar + 1));	// Matriz de errores acumulados
	std::vector< std::vector<long double> > matrizFathers(puntosCurvaOriginal + 1, std::vector<long double>(puntosParaAproximar + 1));	// Matriz de puntos predecesores


	// Se calculan los sumatorios para los errores
	calculateSummations();

	// Se asignan los valores de los casos particulares de errores acumulados
	matrizErrores[1][1] = 0;
	for (int i = 2; i <= puntosCurvaOriginal; i++) {
		matrizErrores[i][1] = std::numeric_limits<long double>::max();	// Infinito
	}

	// Se itera por los valores de "m"
	for (int m = 2; m <= puntosParaAproximar; m++) {
		// Se itera por los valores de "n"
		for (int n = m; n <= puntosCurvaOriginal; n++) {
			error1 = matrizErrores[m - 1][m - 1] + calculateISEValue(m - 2, n - 1);	// Se calcula el primer valor del error acumulado de la aproximacion
			matrizFathers[n][m] = m - 1;	// Se asigna el predecesor al punto aproximado

			// Se calcula el minimo valor de error acumulado
			for (int j = m; j < n - 1; j++) {
				error2 = matrizErrores[j][m - 1] + calculateISEValue(j - 1, n - 1); // Siguientes valores del conjunto de errores para cada valor de "n"

				if (error1 > error2) {
					error1 = error2;	// Se asigna el nuevo error
					matrizFathers[n][m] = j;	// Se asigna el nuevo predecesor
				}

				matrizErrores[n][m] = error1;	// Se asigna el minimo error acumulado
			}
		}
	}

	// Se insertan en orden los valores de la matriz de puntos predecesores en el vector de puntos dominantes
	vecDominantes.insert(vecDominantes.begin(), puntosCurvaOriginal - 1);	// Se inserta el ultimo punto dominante, correspondiente al ultimo punto de la curva

	puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];	// Se asigna el valor de la aproximacion inicial deseada
	vecDominantes.insert(vecDominantes.begin(), puntoPredecesor - 1);	// Se inserta el predecesor al punto de la aproximacion

	for (int j = puntosParaAproximar - 1; puntoPredecesor > 1; j--) {
		vecDominantes.insert(vecDominantes.begin(), matrizFathers[puntoPredecesor][j] - 1);
		puntoPredecesor = matrizFathers[puntoPredecesor][j];
	}

	// Se asigna el vector de puntos dominantes final al objeto actual
	setDominantPointsPosition(vecDominantes);

////////////////////////////////////////////////////////////////////////////////

	// Se calcula la aproximacion poligonal
	calculatePolygonalApproximation();
}

////////////////////////////////////////////////////////////////////////////////
