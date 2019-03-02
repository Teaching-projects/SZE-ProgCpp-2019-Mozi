#include <iostream>
#include "Ertekeles.hpp"
#include <string>



 void Ertekeles:: csillagkiir()
{
	for (int i = 0; i < Ertekeles::csillagdb; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}
