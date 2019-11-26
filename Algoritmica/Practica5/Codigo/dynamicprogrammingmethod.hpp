#ifndef dynamicprogrammingmethod_HPP
#define dynamicprogrammingmethod_HPP

#include "algorithm.hpp"

//This class implements a method for obtaining a polygonal approximation
class DynamicProgrammingMethod:public Algorithm {
	private:

	public:
		DynamicProgrammingMethod(char * fileName, int numberPointsPolygonalApproximation);
		~DynamicProgrammingMethod();

		void apply();
};

#endif
