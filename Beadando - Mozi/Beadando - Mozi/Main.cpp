#include <iostream>
#include <string>
#include "Ertekeles.hpp"
#include "Film.hpp"
#include "Jegy.hpp"
#include "Akcio.hpp"
#include "Terem.hpp"
#include "Szemelyzet.hpp"
#include "Ervenyes.hpp"
#include "Berlet.hpp"
#include "Mozi.hpp"
#include "Kijelzes.hpp"
#include "Tarolo.hpp"
#include "Szamla.hpp"
#include <vector>



int main() {
	
	

	

	/*Ertekeles e1 = Ertekeles("Teszt", 5);
	Ertekeles e2 = Ertekeles("Teszt2", 10);

	f1.ertekelesHozzaad(e1);
	f1.ertekelesHozzaad(e2);

	f1.filmKiir();*/

	

	//ToDo: cinema felulet, fh + jelszo inputell, szamla txt export

	//sql vagy nosql-> local szerver -> ezt telepíteni, valamint hogy van c++ api --> include header / link

	Terem t1 = Terem(1, "terem1", 50, true);
	Terem t2 = Terem(2, "terem2", 20, false);
	Terem t3 = Terem(3, "terem3", 35, false);
	/*
	
	Helyszin h1 = Helyszin("Nev1","Cim1","8:00","22:00");
	Helyszin h2 = Helyszin("Nev2", "Cim2", "8:00", "22:00");

	h1.hozzaad(t1); h1.hozzaad(t2);

	Mozi m1 = Mozi("Cinema City");

	m1.hozzaad(h1); m1.hozzaad(h2);
	m1.kiir();*/

	Tarolo t = Tarolo();
	Kijelzes k = Kijelzes();
	k.kezdooldal();
	Film f1 = Film("Asd1", "Dsa", Nyelv::Angol, Tipus::Misztikus);
	Film f2 = Film("Asd2", "Dsa", Nyelv::Angol, Tipus::Misztikus);
	Film f3 = Film("Asd3", "Dsa", Nyelv::Angol, Tipus::Misztikus);
	t.filmHozzaad(f1);
	t.filmHozzaad(f2);
	t.filmHozzaad(f3);
	t.teremHozzaad(t1);
	t.teremHozzaad(t2);
	t.teremHozzaad(t3);
	//t.listaKiir();
	int filmindex = 0;
	int teremindex = 0;
	int jegydb = 0;
	int tipusindex = 0;

	int sorindex = 0;
	int oszlopindex = 0;
	int temp = 0;

	char input;
	while (std::cin >> input, input!='3')
	{
		if (input == '1')
		{
			system("cls");
			k.jelenlegiFilmek(t);
			getchar(); getchar();
			system("cls");
			k.kezdooldal();
		}
		else if (input =='2')
		{
			system("cls");
			k.jegyVasarlas(t);
			std::cin >> filmindex;
			//filmindex = (input - '0')-1;
			
			k.teremKiiras(t);
			std::cin >> teremindex;
			//teremindex = (input - '0') - 1;

			std::cout << std::endl << "Hany jegyet szeretne foglalni: ";
			std::cin >> jegydb;
			//jegydb = input - '0';

			std::cout << "[1]   Normal" << std::endl << "[2]   Diak" << std::endl << "[3]   Nyugdijas" << std::endl;
			std::cout << std::endl << "Valasszon jegytipust: ";
			std::cin >> tipusindex;
			//tipusindex = input - '0';
			t.termek[teremindex].ulesKiir();
			for (int i = 0; i < jegydb;i++)
			{
				std::cout << std::endl << "Sor: ";
				std::cin >> sorindex;
				std::cout << std::endl << "Oszlop: ";
				std::cin >> oszlopindex;
			}
			
			
			
			
			
			
			//std::cout << std::endl << "Ulesek: " << std::endl;
			
			

				
			


		}

		else if (input =='3')
		{

		}

	}
	
	std::cin.ignore();


	/*
	Felhasznalo f1 = Felhasznalo("Felhasznaloneve", "jelszava", "Neve", "Szuldata", "email-e");
	Jegy j = Jegy("123", 2, 3, 5000, 2019, 3, 12);
	Berlet b1 = Berlet(8000,"1233",2019, 2, 1, 2019, 3, 30);
	Terem t1 = Terem(1, "terem1", 50, true);
*/
	

	Szamla sz1 = Szamla();
	//sz1.szamlaBerlet(f1, b1, t1);
	//sz1.szamlaJegy(f1,j,t1);


		

		
		
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
