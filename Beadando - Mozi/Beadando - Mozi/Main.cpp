#include <iostream>
#include <string>
#include <ctime>
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
#include "Mozi.hpp"
#include "Helyszin.hpp"
#include "Inputell.h"
#include <vector>



int main() {
	

	

	/*Ertekeles e1 = Ertekeles("Teszt", 5);
	Ertekeles e2 = Ertekeles("Teszt2", 10);

	f1.ertekelesHozzaad(e1);
	f1.ertekelesHozzaad(e2);

	f1.filmKiir();*/

	

	//ToDo: cinema felulet, fh + jelszo inputell, szamla txt export, jegyhez rendelni termet helyszint, 1 2 3 inputell, szamlat ker e vegen, 3 kilepes
	//destruktor, headeguard; loginnal a felhasznalo valasszon helyszint, ahol külön filmek/termek vannak.

	//sql vagy nosql-> local szerver -> ezt telepíteni, valamint hogy van c++ api --> include header / link

	
	
	

	/*
	
	Helyszin h1 = Helyszin("Nev1","Cim1","8:00","22:00");
	Helyszin h2 = Helyszin("Nev2", "Cim2", "8:00", "22:00");

	h1.hozzaad(t1); h1.hozzaad(t2);

	Mozi m1 = Mozi("Cinema City");

	m1.hozzaad(h1); m1.hozzaad(h2);
	m1.kiir();*/

	Mozi cinemaCity = Mozi("Cinema City Magyarorszag");
	Helyszin h1 = Helyszin("Gyor","Vasvari Pal utca 1","8:00","02:00");
	Helyszin h2 = Helyszin("Budapest", "Kerepesi utca 9", "8:00", "02:00");
	cinemaCity.hozzaad(h1);
	cinemaCity.hozzaad(h2);



	
	Tarolo t = Tarolo();
	
	Kijelzes k = Kijelzes();
	std::vector<Jegy> jegyek;
	
	Film f1 = Film("Asd1", "Dsa", Nyelv::Angol, Tipus::Misztikus);
	Film f2 = Film("Asd2", "Dsa", Nyelv::Angol, Tipus::Misztikus);
	Film f3 = Film("Asd3", "Dsa", Nyelv::Angol, Tipus::Misztikus);

	Felhasznalo felh = Felhasznalo("Felhasznaloneve", "jelszava", "Neve", "Szuldata", "email-e");

	Terem t1 = Terem(1, "terem1", 50, true);
	Terem t2 = Terem(2, "terem2", 20, false);
	Terem t3 = Terem(3, "terem3", 35, false);

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
	char szamlae;

	int sorindex = 0;
	int oszlopindex = 0;
	int temp = 0;


	/*std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);*/

	time_t most = time(0);
	tm *ji = localtime(&most);
	
	int input;

	int kodindex = 0;
	std::string kodelotag = "Mozi_Jegy_"; 
	
	int ar = 0;

	k.kezdooldal();

	while (std::cin >> input, input != 3)
	{
		if (input == 1)
		{
			system("cls");
			k.jelenlegiFilmek(t);
			getchar(); getchar();
			system("cls");
			k.kezdooldal();
		}
		else if (input == 2)
		{
			system("cls");
			k.jegyVasarlas(t);
			std::cin >> filmindex;


			k.teremKiiras(t);
			std::cin >> teremindex;


			std::cout << std::endl << "Hany jegyet szeretne foglalni: ";
			std::cin >> jegydb;


			std::cout << "[1]   Normal" << std::endl << "[2]   Diak" << std::endl << "[3]   Nyugdijas" << std::endl;
			std::cout << std::endl << "Valasszon jegytipust: ";
			std::cin >> tipusindex;

			

			//filmindex   teremindex    jegydb     tipusindex

			if (tipusindex == 1) {
				ar = Akcio::alapar;
			}

			else if (tipusindex == 2)
			{
				ar = Akcio::getDiakAr();
			}

			else if (tipusindex == 3)
			{
				ar = Akcio::getNyugdijasAr();
			}


			for (int i = 0; i < jegydb; i++)
			{
				t.termek[teremindex - 1].ulesKiir();
				kodindex++;

				/*std::cout << std::endl << "Sor: ";
				std::cin >> sorindex;*/
				

				

				while ( std::cout << std::endl << "Sor: ", std::cin >> sorindex,  !Inputell::indexell(sorindex));

				while (std::cout << std::endl << "Oszlop: ", std::cin >> oszlopindex, !Inputell::indexell(oszlopindex));

				while (!t.termek[teremindex - 1].ugyanodaFoglal(sorindex-1, oszlopindex-1))
				{
					t.termek[teremindex - 1].ulesKiir();
					while (std::cout << std::endl << "Sor: ", std::cin >> sorindex, !Inputell::indexell(sorindex));

					
					while (std::cout << std::endl << "Oszlop: ", std::cin >> oszlopindex, !Inputell::indexell(oszlopindex));
					
				}

				t.termek[teremindex - 1].ulesFoglal(sorindex-1, oszlopindex-1);

				Jegy jegy = Jegy(kodelotag + std::to_string(kodindex), sorindex, oszlopindex, ar, 1900 + ji->tm_year, 1 + ji->tm_mon, ji->tm_mday,t.filmek[filmindex-1]);
				
				jegyek.push_back(jegy);
				
			}
			std::cout << std::endl << "Ker szamlat a vasarlasrol? (I/N): ";
			std::cin >> szamlae;
			if (toupper(szamlae) == 'I')
			{
				Szamla::szamlaJegy(felh, jegyek, t.termek[teremindex-1]);
				std::cout << std::endl << "Szamla kiadva!" << std::endl;
			}

			/*for (Jegy j : jegyek)
			{
				j.jegyKiir();
			}*/
			
		}

		else if (input == 3)
		{
			exit(0);
		}

		//}



		//std::cin.ignore();


		/*
		Felhasznalo f1 = Felhasznalo("Felhasznaloneve", "jelszava", "Neve", "Szuldata", "email-e");
		Jegy j = Jegy("123", 2, 3, 5000, 2019, 3, 12);
		Berlet b1 = Berlet(8000,"1233",2019, 2, 1, 2019, 3, 30);
		Terem t1 = Terem(1, "terem1", 50, true);
	*/


	//Szamla sz1 = Szamla();
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
	}
	return 0;
}
