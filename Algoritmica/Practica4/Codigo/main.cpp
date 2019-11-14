#include "algorithm.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
  //It creates a pointer to algorithm class to use overload in execution
  Algorithm *a;

  char fileNameDC[100], fileNamePA[100];
  int n;
  cout << "Curva digital para obtener la aproximacion poligonal: ";
  cin >> fileNameDC;

  //Creates a new class for method and the pointer points to the new class
  // a = new CollinearSuppressionMethod(fileNameDC);
  a = new Greed

  //Execute the method
  a->apply();

  cout << "Numero de puntos de la aproximacion poligonal: " << a->getNumberPointsPolygonalApproximation() << endl;
  cout << "El valor de ISE es: " << a->getISE() << endl;

  DigitalCurve aP = a->getPolygonalApproximation();

  cout << "Fichero para guardar la aproximacion poligonal: ";
  cin >> fileNamePA;

  aP.saveDigitalCurve(fileNamePA);

  return 0;
}
