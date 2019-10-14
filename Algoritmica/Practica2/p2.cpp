#include <cassert>
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>  // Para usar memset
#include <stdint.h> // Para usar uint64_t
#include <vector>   // Para usar vectores
#include <fstream>  // Para ficheros
#include <cmath>    // Para log10()
#include <string>   // Para string y stod

#include "p2.hpp"









////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  system("clear");  // Se limpia la terminal

  int opcion ;  // Variable para el switch
  int columnaFinal; // Valor de la columna a la que se quiere llegar


  std::cout << "Introduzca la columna de la fila 8 a la que desea llegar: ";
  std::cin >> columnaFinal;
  std::cout << '\n';

  while ((columnaFinal < 1) || (columnaFinal > 8)) {
    std::cout << "\n\nERROR." << "\nPor favor, introduzca un valor entre 1 y 8: ";
    std::cin >> columnaFinal;
    std::cout << '\n';
  }




  // Selecciona realizar el apartado opcional
  std::cout << "\n\n¿Desea visualizar las tablas de las soluciones?" << '\n';
  std::cout << "-----------------------------------" << '\n';
  std::cout << "\t(1) ------ SI\n\t(2) ------ NO" << '\n';
  std::cout << "-----------------------------------" << '\n';
  std::cout << "Opcion: ";
  std::cin >> opcion;
  std::cout << '\n';

  switch (opcion) {
    case 1: // Se imprimen las tablas de soluciones
      system("clear");



    break;

    case 2: // No se desea imprimir las tablas de soluciones
      system("clear");
      std::cout << "\n\nTerminando programa . . ." << '\n';
    break;
  }











  return 0;
}
