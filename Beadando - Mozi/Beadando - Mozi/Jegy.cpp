#include "Jegy.hpp"

void Jegy::jegyKiir()
{
	std::cout << std::endl << "K�d: " << kod << std::endl << "Sor: " << sor << std::endl << "Oszlop: " << oszlop << std::endl << "�r: " << ar << std::endl
		<< "�v: " << ev << std::endl << "H�nap: " << honap << std::endl << "Nap: " << nap << std::endl << "Film neve: " << f.getCim() << std::endl;
}

std::string Jegy::isErvenyes(int ev, int honap, int nap)
{
	return(Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap) ? "�rv�nyes" : "Nem �rv�nyes";
}
