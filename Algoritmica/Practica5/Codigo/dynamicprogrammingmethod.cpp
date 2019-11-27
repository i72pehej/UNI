#include <vector>    // necesario para el contenedor vector
#include <limits>
#include <algorithm>	// Para utilizar "reverse()"

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

void DynamicProgrammingMethod::rellenarMatrizErrores(int const puntosCurvaOriginal, std::vector< std::vector<long double> > &matrizErrores) {
	matrizErrores[1][1] = 0;

	for (int i = 2; i <= puntosCurvaOriginal; i++) {
		matrizErrores[i][1] = std::numeric_limits<long double>::max();	// Infinito
	}
}

////////////////////////////////////////////////////////////////////////////////

void DynamicProgrammingMethod::rellenarMatrizFathers(int const puntosParaAproximar, int const puntosCurvaOriginal, std::vector< std::vector<long double> > &matrizErrores, std::vector< std::vector<long double> > &matrizFathers) {
	long double error1, error2;	// Errores entre las aproximaciones seleccionadas


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
}

////////////////////////////////////////////////////////////////////////////////

std::vector<int> DynamicProgrammingMethod::fathersToDominantes(int const puntosParaAproximar, int const puntosCurvaOriginal, std::vector< std::vector<long double> > const matrizFathers) {
	long double puntoPredecesor;	// Valor para el predecesor de la aproximacion deseada
	std::vector<int> vecDominantes;	// Vector de puntos dominantes


	puntoPredecesor = matrizFathers[puntosCurvaOriginal][puntosParaAproximar];	// Se asigna el valor de la aproximacion inicial deseada
	// Se insertan en orden los valores de la matriz de puntos predecesores en el vector de puntos dominantes
	vecDominantes.push_back(puntosCurvaOriginal - 1);	// Se inserta el ultimo punto dominante, correspondiente al ultimo punto de la curva
	vecDominantes.push_back(puntoPredecesor - 1);	// Se inserta el predecesor al punto de la aproximacion

	// Se rellena el vector de puntos dominantes de la curva
	for (int j = puntosParaAproximar - 1; puntoPredecesor > 1; j--) {
		vecDominantes.push_back(matrizFathers[puntoPredecesor][j] - 1);	// Se hace "-1" para que el valor introducido este correctamente indexado
		puntoPredecesor = matrizFathers[puntoPredecesor][j];	// Se asigna el nuevo punto predecesor
	}

	// Se invierte el vector para ordenar los puntos dominantes
	std::reverse(vecDominantes.begin(), vecDominantes.end());

	return vecDominantes;
}

////////////////////////////////////////////////////////////////////////////////

void DynamicProgrammingMethod::apply() {
	int puntosCurvaOriginal = getOriginalCurve().getNumberPointsDigitalCurve();	// Numero de puntos de la curva original
	int puntosParaAproximar = getNumberPointsPolygonalApproximation();	// Numero de puntos con los que se quiere aproximar

	std::vector< std::vector<long double> > matrizErrores(puntosCurvaOriginal + 1, std::vector<long double>(puntosParaAproximar + 1));	// Matriz de errores acumulados
	std::vector< std::vector<long double> > matrizFathers(puntosCurvaOriginal + 1, std::vector<long double>(puntosParaAproximar + 1));	// Matriz de puntos predecesores


	// Se calculan los sumatorios para los errores
	calculateSummations();

	// Se asignan los valores de los casos particulares de errores acumulados a la matriz de errores
	rellenarMatrizErrores(puntosCurvaOriginal, matrizErrores);

	// Se asignan los predecesores para cada punto de la matriz "fathers"
	rellenarMatrizFathers(puntosParaAproximar, puntosCurvaOriginal, matrizErrores, matrizFathers);

	// Se asigna el vector de puntos dominantes final al objeto actual
	setDominantPointsPosition(fathersToDominantes(puntosParaAproximar, puntosCurvaOriginal, matrizFathers));

////////////////////////////////////////////////////////////////////////////////

	// Se calcula la aproximacion poligonal
	calculatePolygonalApproximation();
}

////////////////////////////////////////////////////////////////////////////////
