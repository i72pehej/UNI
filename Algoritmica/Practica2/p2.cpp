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

int main(int argc, char const *argv[]) {
  int opcion ;  // Variable para el switch

  int columnaFinal; // Valor de la columna a la que se quiere llegar
  std::vector< std::vector<int> > matriz;
  int nCaminos; // Numero de caminos para cada posicion


  // Bucle infinito para poder realizar todas las opciones
  while (true) {
    system("clear");  // Se limpia la terminal

    nCaminos = 0; // Reseteo del numero de caminos

    std::cout << "\n\t--------------------------------------------------------" << '\n';
    std::cout << "\t(1) ------ CAMINOS PARA LLEGAR A LA FILA 8 DESDE LA 1" << '\n';
    std::cout << "\t(2) ------ CAMINOS PARA LLEGAR A LA FILA 8 DESDE (1 , 2)" << '\n';
    std::cout << "\t(3) ------ CAMINOS PARA LLEGAR A LA FILA 8 DESDE (1 , 7)" << '\n';
    std::cout << "\t--------------------------------------------------------" << '\n';
    std::cout << "\t(4) ------ VISUALIZAR SOLUCIONES" << '\n';
    std::cout << "\t(5) ------ CAMINOS PARA LLEGAR A LA FILA n DESDE LA 1" << '\n';
    std::cout << "\t--------------------------------------------------------" << '\n';
    std::cout << "\t(0) ------ SALIR" << '\n';
    std::cout << "\t--------------------------------------------------------" << '\n';
    std::cout << "\nIntroduzca el apartado que desea realizar: ";
    std::cin >> opcion;
    std::cout << '\n';

////////////////////////////////////////////////////////////////////////////////

    switch (opcion) {
      case 0:
        system("clear");  // Se limpia la terminal

        std::cout << "Terminando ejecucion . . ." << '\n';
        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();

        system("clear");  // Se limpia la terminal

        return 0;
      break;

      case 1:
        system("clear");  // Se limpia la terminal

        std::cout << "Introduzca la columna de la fila 8 a la que desea llegar (0 a 7): ";
        std::cin >> columnaFinal;
        std::cout << '\n';

        // Comprobacion para que los valores esten en el tablero
        while ((columnaFinal < 0) || (columnaFinal > 7)) {
          std::cout << "\n\nERROR." << "\nPor favor, introduzca un valor entre 0 y 7: ";
          std::cin >> columnaFinal;
          std::cout << '\n';
        }

        matriz = std::vector< std::vector<int> > (8, std::vector<int> (8)); // Reserva de memoria
        calcularCaminos(7, columnaFinal, nCaminos, matriz); // Calcular los caminos

        std::cout << "Caminos para [8," << columnaFinal + 1 << "] = " << nCaminos << '\n';

        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();
      break;

////////////////////////////////////////////////////////////////////////////////

      case 2:
        system("clear");  // Se limpia la terminal

        matriz = std::vector< std::vector<int> > (8, std::vector<int> (8)); // Reserva de memoria
        calcularCaminos(7, 6, nCaminos, matriz); // Calcular los caminos (Posiciones simetricas)
        std::cout << "Caminos para llegar a FILA 8 desde [1,2]: " << nCaminos << '\n';

        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();
      break;

////////////////////////////////////////////////////////////////////////////////

      case 3:
        system("clear");  // Se limpia la terminal

        matriz = std::vector< std::vector<int> > (8, std::vector<int> (8)); // Reserva de memoria
        calcularCaminos(7, 1, nCaminos, matriz); // Calcular los caminos (Posiciones simetricas)
        std::cout << "Caminos para llegar a FILA 8 desde [1,7]: " << nCaminos << '\n';

        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();
      break;

////////////////////////////////////////////////////////////////////////////////

      case 4:
        system("clear");  // Se limpia la terminal



        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();
      break;

////////////////////////////////////////////////////////////////////////////////

      case 5:
        system("clear");  // Se limpia la terminal

        std::cout << "\n\n\n\tPulse cualquier tecla para continuar . . ." << '\n';
        std::cin.ignore();
        std::cin.ignore();
      break;
    }

////////////////////////////////////////////////////////////////////////////////

  }

  return 0;
}
