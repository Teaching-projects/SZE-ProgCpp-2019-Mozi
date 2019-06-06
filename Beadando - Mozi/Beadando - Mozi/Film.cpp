#include "Film.hpp"

void Film::filmKiir()
{
	std::cout << "C�m: " << getCim() << std::endl << "Rendez�: " << getRendezo() << std::endl << "Nyelv: " << getNyelv() << std::endl <<
		"T�pus: " << getTipus() << std::endl << std::endl;
	std::cout << "�rt�kel�sek: " << std::endl << std::endl;
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
