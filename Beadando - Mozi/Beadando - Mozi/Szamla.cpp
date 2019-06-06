#include "Szamla.hpp"
#include "Felhasznalo.hpp"
#include "Szemelyzet.hpp"

Szamla::Szamla() {};

void Szamla::szamlaJegy(Felhasznalo f, std::vector<Jegy> jegyek, Terem t)
{
	std::string temp;
	temp = "j_" + jegyek[0].getKod() + "szamla.txt";
	fajl.open(temp);
	for (Jegy j : jegyek)
	{
		fajl << "Vevõ neve: " << f.getNev() << std::endl << "Vásárlás napja: " << j.getEv() << "." << j.getHonap() << "." << j.getNap() << std::endl <<
			std::endl << "Jegy kódja: " << j.getKod() << std::endl << "Ülés: " << j.getSor() << "/" << j.getOszlop() << std::endl << "Jegy ára: " << j.getAr()
			<< std::endl << "Terem: " << t.getNev() << std::endl << std::endl;
	}
	fajl.close();
}
