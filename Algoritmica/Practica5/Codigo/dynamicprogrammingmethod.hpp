#ifndef dynamicprogrammingmethod_HPP
#define dynamicprogrammingmethod_HPP

#include "algorithm.hpp"

//This class implements a method for obtaining a polygonal approximation
class DynamicProgrammingMethod:public Algorithm {
	private:
		void rellenarMatrizErrores(int const puntosCurvaOriginal, std::vector< std::vector<long double> > &matrizErrores);

		void rellenarMatrizFathers(int const puntosParaAproximar, int const puntosCurvaOriginal, std::vector< std::vector<long double> > &matrizErrores, std::vector< std::vector<long double> > &matrizFathers);

		std::vector<int> fathersToDominantes(int const puntosParaAproximar, int const puntosCurvaOriginal, std::vector< std::vector<long double> > const matrizFathers);

	public:
		DynamicProgrammingMethod(char * fileName, int numberPointsPolygonalApproximation);
		~DynamicProgrammingMethod();

		void apply();
};

#endif
