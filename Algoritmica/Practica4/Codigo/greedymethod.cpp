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

void GreedyMethod::apply()
{
	int iteradorDominantes, i = 0;
	std::vector<int> vecDominantes;

	// Se calculan los sumatorios para los errores
	calculateSummations();

	// Se eliminan los puntos alineados para obtener los puntos dominantes
	collinearPointsElimination();
	std::cout << "PUNTOS DOMINANTES: " << getDominantPointsPosition().size() << '\n';

	// Se seleccionan los puntos que se quiere que tenga la aproximacion y se eliminan el resto
	iteradorDominantes = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() - 1);
	vecDominantes.resize(getNumberPointsPolygonalApproximation());

	for (size_t i = 0; i < getDominantPointsPosition().size(); i += iteradorDominantes) {
		vecDominantes.push_back(getDominantPointsPosition().at(i));
	}
	setDominantPointsPosition(vecDominantes);
	std::cout << "PUNTOS DOMINANTES FINALES: " << getDominantPointsPosition().size() << '\n';

	// Se calcula el error entre los puntos i-1 y i+1 para seleccionar el punto optimo
	for (i = 0; i < ?¿?¿?; i++) {
		calculateISEValue(getDominantPointsPosition().at(i - 1), getDominantPointsPosition().at(i + 1));
	}
	// Optimizacion del ultimo punto, coincidente con el primero
	calculateISEValue();





	// Se calcula la aproximacion poligonal
	calculatePolygonalApproximation();
}
