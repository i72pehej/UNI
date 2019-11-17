#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "greedymethod.hpp"
#include "digitalcurve.hpp"
//#include "heapvectorMasood.hpp"
//#include "nodoMasood.hpp"



using namespace std;

/* Functions for Collinear suppression method */

//Constructor.

GreedyMethod::GreedyMethod(char *fileName, int numberPointsPolygonalApproximation)
{
  //A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);

  //Digital curve as saved as original curve
  setOriginalCurve(dc);

  //Set the number of points of the polygonal approximation
  setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
GreedyMethod::~GreedyMethod()
{
}

////////////////////////////////////////////////////////////////////////////////

void GreedyMethod::apply()
{
	int iteradorDominantes, i = 0;
	std::vector<int> vecDominantes;

////////////////////////////////////////////////////////////////////////////////

	// Se calculan los sumatorios para los errores
	calculateSummations();

////////////////////////////////////////////////////////////////////////////////

	// Se eliminan los puntos alineados para obtener los puntos dominantes
	collinearPointsElimination();

////////////////////////////////////////////////////////////////////////////////

	// Se seleccionan los puntos que se quiere que tenga la aproximacion y se eliminan el resto
	iteradorDominantes = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() - 1);

	vecDominantes.resize(getNumberPointsPolygonalApproximation());
	vecDominantes.clear();

	// Se iterta sobre el vector de puntos dominantes seleccionando en funcion de la cantidad deseada
	for (i = 0; i < getDominantPointsPosition().size(); i += iteradorDominantes) {
		vecDominantes.push_back(getDominantPointsPosition().at(i));
	}
	setDominantPointsPosition(vecDominantes);	// Se modifican los puntos dominantes

////////////////////////////////////////////////////////////////////////////////

	// Se calcula el error con los puntos "i-1" y "i+1" para seleccionar el punto optimo
	long double error1, error2;	// Errores entre los puntos seleccionados

	// Se itera sobre todos los puntos dominantes (excepto el ultimo = primero) para optimizar su posicion
	for (i = 1; i < getDominantPointsPosition().size() - 1; i++) {
		// Se calcula el error total del punto dominante "i"
		error1 = (calculateISEValue(getDominantPointsPosition().at(i - 1), getDominantPointsPosition().at(i)) + calculateISEValue(getDominantPointsPosition().at(i), getDominantPointsPosition().at(i + 1)));

		// Se itera sobre los posibles puntos candidatos
		for (int j = getDominantPointsPosition().at(i - 1); j < getDominantPointsPosition().at(i + 1); j++) {
			// Se calcula el error total de cada punto candidato "j"
			error2 = (calculateISEValue(getDominantPointsPosition().at(i - 1), j) + calculateISEValue(j, getDominantPointsPosition().at(i + 1)));

			// Se modifica la posicion del punto dominante en caso de que el error del candidato "j" sea inferior
			if (error1 > error2) {
				vecDominantes.at(i) = j;	// Se asigna la nueva posicion
				error1 = error2;	// Se asigna el nuevo error. correspondiente a la nueva posicion
			}
		}
	}
	setDominantPointsPosition(vecDominantes);	// Se modifican los puntos dominantes

////////////////////////////////////////////////////////////////////////////////

	// Se calcula el error total del ultimo punto dominante
	error1 = calculateISEValue(getDominantPointsPosition()[i], getDominantPointsPosition()[i - 1]);

	// Se itera sobre los posibles puntos candidatos de la parte final del vector
	for (int j = getDominantPointsPosition()[i - 1]; j < getDominantPointsPosition()[getDominantPointsPosition().size()]; j++) {
		// Se calcula el error total de cada punto candidato "j"
		error2 = (calculateISEValue(getDominantPointsPosition()[i - 1], j) + calculateISEValue(j, getDominantPointsPosition()[getDominantPointsPosition().size() - 1]));

		// Se modifica la posicion del punto dominante en caso de que el error del candidato "j" sea inferior
		if (error1 > error2) {
			vecDominantes[0] = j;	// Se asigna la nueva posicion
			error1 = error2;	// Se asigna el nuevo error. correspondiente a la nueva posicion
		}
	}
	// Se itera sobre los posibles puntos candidatos de la parte inicial del vector
	for (int k = getDominantPointsPosition()[0]; k < getDominantPointsPosition()[1]; k++) {
		// Se calcula el error total de cada punto candidato "k"
		error2 = (calculateISEValue(getDominantPointsPosition()[0], k) + calculateISEValue(k, getDominantPointsPosition()[1]));

		// Se modifica la posicion del punto dominante en caso de que el error del candidato "k" sea inferior
		if (error1 > error2) {
			vecDominantes[0] = k;	// Se asigna la nueva posicion
			error1 = error2;	// Se asigna el nuevo error. correspondiente a la nueva posicion
		}
	}
	vecDominantes[vecDominantes.size() - 1] = vecDominantes[0];	// Se igualan los puntos ultimo y primero
	setDominantPointsPosition(vecDominantes);	// Se modifican los puntos dominantes

////////////////////////////////////////////////////////////////////////////////

	// Se calcula la aproximacion poligonal
	calculatePolygonalApproximation();
}

////////////////////////////////////////////////////////////////////////////////
