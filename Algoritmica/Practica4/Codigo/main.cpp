#include "algorithm.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include "greedymethod.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
  system("clear");

  //It creates a pointer to algorithm class to use overload in execution
  Algorithm *a;

  char fileNameDC[100], fileNamePA[100];
  int n;
  cout << "Curva digital para obtener la aproximacion poligonal: ";
  cin >> fileNameDC;

  //Creates a new class for method and the pointer points to the new class
  // a = new CollinearSuppressionMethod(fileNameDC);

  std::cout << "\nIntroduzca el numero de puntos para la aproximacion: ";
  std::cin >> n;
  std::cout << '\n';

  a = new GreedyMethod(fileNameDC, (n + 1));

  //Execute the method
  a->apply();

  cout << "\nNumero de puntos de la aproximacion poligonal: " << a->getNumberPointsPolygonalApproximation() << endl;
  cout << "\nEl valor de ISE es: " << a->getISE() << endl;

  DigitalCurve aP = a->getPolygonalApproximation();

  cout << "\nFichero para guardar la aproximacion poligonal: ";
  cin >> fileNamePA;

  aP.saveDigitalCurve(fileNamePA);

  return 0;
}
