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
		fajl << "Vevo neve: " << f.getNev() << std::endl << "Vasarlas napja: " << j.getEv() << "." << j.getHonap() << "." << j.getNap() << std::endl <<
			std::endl << "Jegy kodja: " << j.getKod() << std::endl << "Ules: " << j.getSor() << "/" << j.getOszlop() << std::endl << "Jegy ara: " << j.getAr()
			<< std::endl << "Terem: " << t.getNev() << std::endl << std::endl;
	}
	fajl.close();
}


