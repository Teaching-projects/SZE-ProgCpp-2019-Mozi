#include <iostream>
#include <string>
#include "Terem.hpp"

void Terem:: teremKiir()
{
	/*std::cout << "Azonosito: " << getAzonosito() << std::endl << "Nev: " << getNev() << std::endl << "Kapacitas: " << getKapacitas() << std::endl
		<< getLegkondizalte() ? "Legkondizalt" : "Nem legkondizalt";*/

	std::cout << "Azonosito: " << getAzonosito() << std::endl << "Nev: " << getNev() << std::endl << "Kapacitas: " << getKapacitas() << std::endl;
	if (getLegkondizalte() == true)
	{
		std::cout << "Legkondizalt";
	}
	else
	{
		std::cout << "Nem legkondizalt";
	}
	std::cout << std::endl;
}