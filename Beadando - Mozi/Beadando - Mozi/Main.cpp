#include <iostream>
#include "Ertekeles.hpp"
#include <string>

int main() {

	
	Ertekeles e1 = Ertekeles("Teszt", 1);
	
	std::cout<<e1.getLeiras()<<std::endl;
	std::cin.ignore();

	return 0;
}
