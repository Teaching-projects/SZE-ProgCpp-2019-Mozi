#include "Ertekeles.hpp"

 void Ertekeles:: csillagKiir()
{
	for (int i = 0; i < Ertekeles::csillagdb; i++)
	{
		std::cout << "*";
	}
}
 
 void Ertekeles::ertekelesKiir()
 {
	 csillagKiir();
	 std::cout << std::endl;
	 std::cout << this->leiras << std::endl;
 }
