#include "Film.hpp"

void Film::filmKiir()
{
	std::cout << "Cím: " << getCim() << std::endl << "Rendezõ: " << getRendezo() << std::endl << "Nyelv: " << getNyelv() << std::endl <<
		"Típus: " << getTipus() << std::endl << std::endl;
	std::cout << "Értékelések: " << std::endl << std::endl;
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
