#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "funciones8Reinas.hpp"
#include "funciones8ReinasLasVegas.cpp"

#include "ClaseTiempo.cpp"


int main(int argc, char const *argv[]) {
  srand(time(NULL));

  Clock time; // Inicia temporizador

  int opcion; // Opcion para elegir el metodo
  int soluciones; // Numero de soluciones al metodo
  int n; // Numero de reinas
  int k;  // Fila

  bool salir = false; // Opcion para salir del programa
  bool success = false; // Variable que controla la repeticion de LAS VEGAS


  while (!salir) {
    system("clear");

    std::cout << "Seleccione un metodo" << '\n';
    std::cout << "\t[1] --- BACTRACKING" << '\n';
    std::cout << "\t[2] --- LAS VEGAS" << '\n';
    std::cout << "\t[0] --- SALIR" << '\n';
    std::cout << "\nOPCION: ";
    std::cin >> opcion;
    std::cin.ignore();

    switch (opcion) {
      case 0: { // SALIR
        salir = true;

        system("clear");
      }
      break;

      case 1: { // BACTRACKING
        time.start(); // Inicia el contador

        std::cout << "Introduzca el numero de reinas: ";
        std::cin >> n;
        std::cout << '\n';
        std::cin.ignore();

        std::vector<int> x(n + 1); // Columna
        std::vector< std::vector<int> > m(n + 1, std::vector<int>(n + 1));  // Matriz de soluciones

        k = 1;  // Primera reina en fila 1
        x[k] = 0; // Primera reina en columna 0

        soluciones = backtracking8Reinas(n, k, x, m);

        std::cout << "\n\tHay " << soluciones << " soluciones.\n" << '\n';

        // Se detiene el temporizador
        if (time.isStarted()) {
          time.stop();
          std::cout << "Han pasado " << time.elapsed() << " microsegundos.\n\n\n";
        }

        std::cout << "\n\nPULSE INTRO PARA CONTINUAR . . ." << '\n';
        std::cin.ignore();
      }
      break;

      case 2: { // LAS VEGAS
        std::cout << "Introduzca el numero de reinas: ";
        std::cin >> n;
        std::cout << '\n';
        std::cin.ignore();

        int intentos = 0; // Numero de veces que se intenta LAS VEGAS

        std::vector<int> x(n + 1); // Columna
        std::vector< std::vector<int> > m(n + 1, std::vector<int>(n + 1));  // Matriz de soluciones

        k = 1;  // Primera reina en fila 1
        x[k] = 0; // Primera reina en columna 0

        x = repetirLasVegas(n, k, x, intentos); // Se rellena el vector de soluciones

        // Se introduce un 1 en las posiciones de las reinas en la matriz
        for (size_t i = 1; i < m.size(); i++) {
          m[i][x[i]] = 1;
        }

        imprimeMatriz8Reinas(m);

        std::cout << "\nSolucion hallada en " << intentos << " intentos." << '\n';

        std::cout << "\n\nPULSE INTRO PARA CONTINUAR . . ." << '\n';
        std::cin.ignore();
      }
      break;
    }
  }

  system("clear");
  return 0;
}
