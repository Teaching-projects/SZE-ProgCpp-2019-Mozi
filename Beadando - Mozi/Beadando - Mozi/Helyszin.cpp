#include "Helyszin.hpp"





void Helyszin::hozzaad(Terem terem)
{
	termek.push_back(terem);
}

void Helyszin::kiir()
{

	std::string nev;
	std::string cim;
	std::string nyitas;
	std::string zaras;
	std::cout << "N�v: " << getNev() << std::endl << "C�m: "<< getCim() << std::endl << "Nyit�s: "<< getNyitas() 
		<< std::endl << "Z�r�s: "<< getZaras() << std::endl;

	for (Terem t : termek)
	{
		t.teremKiir();
	}
}

void Helyszin::torol(Terem terem)
{

	for (int i = 0; i < termek.size(); ++i)
	{
		if (termek[i].getAzonosito() == terem.getAzonosito())
		{
			termek.erase(termek.begin()+i);
		}
	}

}