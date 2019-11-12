#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include <iostream>

#include "p3funciones.cpp"



////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  system("clear");

  int opcion; // Opcion para switch

  Entero e1, e2, aux; // Enteros grandes


  std::cout << "\n\n-------------------------------" << '\n';
  std::cout << "Introduzca la operacion deseada" << '\n';
  std::cout << "-------------------------------" << '\n';
  std::cout << "\t(1) ------ SUMA" << '\n';
  std::cout << "\t(2) ------ PRODUCTO" << '\n';
  std::cout << "-------------------------------" << '\n';
  std::cout << "\t(0) ------ SALIR" << '\n';
  std::cout << "-------------------------------\n\n" << '\n';

  std::cout << "OPCION: ";
  std::cin >> opcion;
  std::cin.ignore();
  std::cout << "\n\n";



  switch (opcion) {
    case 0: // SALIR
      std::cout << "Terminando ejecucion . . ." << '\n';
      std::cout << "\n\n\tPulse INTRO para continuar" << '\n';
      std::cin.ignore();
    break;

    case 1: // SUMA
      cout << "\nIntroduzca el primer entero: ";
      cin >> e1;
      cout << "\nIntroduzca el entero2 entero: ";
      cin >> e2;

      aux = e1 + e2;

      std::cout << "\n\n----------------------------------------------" << '\n';
      std::cout << "RESULTADO (SUMA) = " << aux.getEntero() << '\n';
      std::cout << "----------------------------------------------\n\n" << '\n';

      std::cout << "\n\n\tPulse INTRO para continuar" << '\n';
      std::cin.ignore();
      std::cin.ignore();
    break;

    case 2: // PRODUCTO
      cout << "\nIntroduzca el primer entero: ";
      cin >> e1;
      cout << "\nIntroduzca el entero2 entero: ";
      cin >> e2;

      aux = e1 * e2;

      std::cout << "\n\n----------------------------------------------" << '\n';
      std::cout << "RESULTADO (PRODUCTO) = " << aux.getEntero() << '\n';
      std::cout << "----------------------------------------------\n\n" << '\n';

      std::cout << "\n\n\tPulse INTRO para continuar" << '\n';
      std::cin.ignore();
      std::cin.ignore();
    break;
  }

  system("clear");
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
