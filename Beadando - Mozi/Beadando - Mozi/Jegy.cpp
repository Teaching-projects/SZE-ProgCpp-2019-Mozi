#include "Jegy.hpp"

void Jegy::jegyKiir()
{
	std::cout << std::endl << "Kód: " << kod << std::endl << "Sor: " << sor << std::endl << "Oszlop: " << oszlop << std::endl << "Ár: " << ar << std::endl
		<< "Év: " << ev << std::endl << "Hónap: " << honap << std::endl << "Nap: " << nap << std::endl << "Film neve: " << f.getCim() << std::endl;
}

std::string Jegy::isErvenyes(int ev, int honap, int nap)
{
	return(Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap) ? "Érvényes" : "Nem érvényes";
}
