#include "Ertekeles.hpp"
#include <string>
#include <iostream>
#include "Film.hpp"


void Film::filmKiir()
{

	std::cout << "Cim: " << getCim() << std::endl << "Rendezo: " << getRendezo() << std::endl << "Nyelv: " << getNyelv() << std::endl <<
		"Tipus: " << getTipus() << std::endl << std::endl;
	std::cout << "Ertekelesek: " << std::endl << std::endl;
	kiir();


}


void Film::ertekelesHozzaad(Ertekeles ertekeles)
{
	ertekelesek.push_back(ertekeles);
}


void Film::kiir()
{
	for (Ertekeles e : ertekelesek)
	{
		e.ertekelesKiir();
		std::cout << std::endl;
	}


}

