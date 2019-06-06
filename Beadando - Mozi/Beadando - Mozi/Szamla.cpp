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
		fajl << "Vev� neve: " << f.getNev() << std::endl << "V�s�rl�s napja: " << j.getEv() << "." << j.getHonap() << "." << j.getNap() << std::endl <<
			std::endl << "Jegy k�dja: " << j.getKod() << std::endl << "�l�s: " << j.getSor() << "/" << j.getOszlop() << std::endl << "Jegy �ra: " << j.getAr()
			<< std::endl << "Terem: " << t.getNev() << std::endl << std::endl;
	}
	fajl.close();
}
