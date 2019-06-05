#include "Jegy.hpp"




void Jegy::jegyKiir()
{

	std::cout << std::endl << "Kod: " << kod << std::endl << "Sor: " << sor << std::endl << "Oszlop: " << oszlop << std::endl << "Ar: " << ar << std::endl
		<< "Ev: " << ev << std::endl << "Honap: " << honap << std::endl << "Nap: " << nap << std::endl << "Film neve: " << f.getCim() << std::endl;
}

std::string Jegy::isErvenyes(int ev, int honap, int nap)
{
	return(Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap) ? "Ervenyes" : "Nem ervenyes";
}

