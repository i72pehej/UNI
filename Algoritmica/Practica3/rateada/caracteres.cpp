#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string a = "3";
	string b = "9";
	int x, y, aux;
	
	string suma;
	
	x = stoi(a);
	y = stoi(b);
	
	aux = x + y;
	
	printf("%d + %d = %d \n", x,y,aux);
	
		suma = to_string(aux);
		std::cout << a << " + " << b << " = " << suma;

		
	return 0;
}
