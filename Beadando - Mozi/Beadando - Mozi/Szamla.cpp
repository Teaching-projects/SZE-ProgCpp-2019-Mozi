#include "Szamla.hpp"
//#include "Felhasznalo.hpp"
#include <iostream>
#include <string>
#include <fstream>

Szamla::Szamla() {};
//Vevõ neve, dátum?, film címe, ülés, ár, kód
void Szamla::szamlaJegy(Felhasznalo f, std::vector<Jegy> jegyek, Terem t)
{
	/*std::string temp; 
	temp = "j_" + j.getKod() + "szamla.txt";
	fajl.open(temp);
	fajl << "Vevo neve: " << f.getNev() << std::endl<< "Vasarlas napja: " << j.getEv() << "." << j.getHonap() << "." << j.getNap() << std::endl <<
		std::endl << "Jegy kodja: " << j.getKod() << std::endl << "Ules: " << j.getSor() << "/" << j.getOszlop() << std::endl << "Jegy ara: " << j.getAr()
		<< std::endl << "Terem: " << t.getNev() << std::endl;
	fajl.close();*/

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

void Szamla::szamlaBerlet(Felhasznalo f, Berlet b, Terem t)
{
	std::string temp;
	temp ="b_"+ b.getKod() + "szamla.txt";
	fajl.open(temp);
	fajl << "Vevo neve: " << f.getNev() << std::endl<<"Berlet intervalluma: " << b.getEvTol()<<"."<<b.getHonapTol()<<"."<<b.getNapTol()<<" - "
		<<b.getEvIg()<<"."<<b.getHonapIg()<<"."<<b.getNapIg() << std::endl << "Berlet kodja: " << b.getKod() 
		<< std::endl << "Berlet ara: " << b.getAr() << std::endl << "Terem: " << t.getNev() << std::endl;
	fajl.close();
}
