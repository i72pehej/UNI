#ifndef FUNCIONES8REINAS_HPP
#define FUNCIONES8REINAS_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>


////////////////////////////////////////////////////////////////////////////////

bool lugar(int k, std::vector<int> x);

////////////////////////////////////////////////////////////////////////////////

int backtracking8Reinas(int n, int k, std::vector<int> x, std::vector< std::vector<int> > &matriz8Reinas);

////////////////////////////////////////////////////////////////////////////////

void imprimeMatriz8Reinas(std::vector< std::vector<int> > matriz8Reinas);

////////////////////////////////////////////////////////////////////////////////

int lasVegas8Reinas(int n, int k, std::vector<int> x, std::vector< std::vector<int> > &matriz8Reinas);

////////////////////////////////////////////////////////////////////////////////

// void guardaEnFicheroMatriz(std::vector<double> &nEle, std::vector<double> &times, std::vector<double> &timesEst);

////////////////////////////////////////////////////////////////////////////////

#endif
