#include <iostream>
#include "Ertekeles.hpp"
#include "Film.hpp"
#include <string>
#include "Jegy.hpp"
#include "Akcio.hpp"
#include "Terem.hpp"
#include "Szemelyzet.hpp"
#include "Ervenyes.hpp"
#include "Berlet.hpp"
#include "Mozi.hpp"


int main() {
	
	

	/*Film f1 = Film("Asd","Dsa",Nyelv::Angol,Tipus::Misztikus);	
	Ertekeles e1 = Ertekeles("Teszt", 5);
	Ertekeles e2 = Ertekeles("Teszt2", 10);

	f1.ertekelesHozzaad(e1);
	f1.ertekelesHozzaad(e2);

	f1.filmKiir();

	
*/
	//ToDo: cinema felulet, fh + jelszo inputell, adatbázis

	//sql vagy nosql-> local szerver -> ezt telepíteni, valamint hogy van c++ api --> include header / link

	Terem t1 = Terem(1, "terem1", 50, true);
	Terem t2 = Terem(2, "terem2", 20, false);
	
	Helyszin h1 = Helyszin("Nev1","Cim1","8:00","22:00");
	Helyszin h2 = Helyszin("Nev2", "Cim2", "8:00", "22:00");

	h1.hozzaad(t1); h1.hozzaad(t2);

	Mozi m1 = Mozi("Cinema City");

	m1.hozzaad(h1); m1.hozzaad(h2);
	m1.kiir();

		

		
		
		//(std::string kod, int sor, int oszlop, int ar, int ev, int honap, int nap)
		/*Jegy j = Jegy("123", 2, 3, 5000, 2019, 3, 12);

		std::cout << j.isErvenyes(2019,3,12) << std::endl;*/
	

		//Berlet b1 = Berlet(2019, 2, 1, 2019, 3, 30); //Hibaellenõrzés
		//std::cout << b1.isErvenyes(2019, 2, 1);

		//Terem t1 = Terem(1, "terem1", 50, true);
		//Terem t2 = Terem(2, "terem2", 20, false);
		//Helyszin h1 = Helyszin("Gyori","Bartok Bela 59","8:00","23:00");
		////std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email
		////Szemelyzet sz = Szemelyzet("asd", "asd", "asd", "asd", "asd", "asd");
		//Szemelyzet sz = Szemelyzet("fh", "jelszo", "nev", "szuldat", "email", "beosztas");
		//std::cout << sz.getFelhasznalonev() << sz.getJelszo()<<sz.getNev()<<sz.getEmail()<<sz.getBeosztas();

		std::cin.ignore();

	

	return 0;
}
