#include "main.hpp"

void Main::start() {
	system("CLS");
	Ertekeles e1 = Ertekeles("Közepes", 5);
	Ertekeles e2 = Ertekeles("Legjobb", 10);
	Ertekeles e3 = Ertekeles("Kaki", 1);
	Ertekeles e4 = Ertekeles("Meh", 3);

	Mozi cinemaCity = Mozi("Cinema City Magyarország");
	Helyszin h1 = Helyszin("Gyõr","Vasvári Pál utca 1","8:00","02:00");

	cinemaCity.hozzaad(h1);
	
	Tarolo t = Tarolo();
	
	Kijelzes k = Kijelzes();
	std::vector<Jegy> jegyek;
	
	Film f1 = Film("Bosszúállók", "Anthony Russo", Nyelv::Angol, Tipus::Akcio);
	Film f2 = Film("Pókember", "Sam Raimi", Nyelv::Angol, Tipus::Thriller);
	Film f3 = Film("A sikeres C++ vizsga", "Orbán Máté - Zsigmond Richárd Tamás - Szekendi Balázs", Nyelv::Magyar, Tipus::Vigjatek);

	f1.ertekelesHozzaad(e1);
	f2.ertekelesHozzaad(e4);
	f1.ertekelesHozzaad(e3);
	f3.ertekelesHozzaad(e2);

	Szemelyzet sz = Szemelyzet("fh", "jelszo", "nev", "szuldat", "email",20000, "beosztas", 10000);
	Felhasznalo felh = Felhasznalo("Felhasznaloneve", "jelszava", "Neve", "Szuldata", "email-e", 100000);

	Terem t1 = Terem(1, "Spielberg terem", 50, true);
	Terem t2 = Terem(2, "Hitchcock terem", 20, false);
	Terem t3 = Terem(3, "Fellini terem", 35, false);

	t.filmHozzaad(f1);
	t.filmHozzaad(f2);
	t.filmHozzaad(f3);

	t.teremHozzaad(t1);
	t.teremHozzaad(t2);
	t.teremHozzaad(t3);

	int filmindex = 0;
	int teremindex = 0;
	int jegydb = 0;
	int tipusindex = 0;
	char szamlae;
	int sorindex = 0;
	int oszlopindex = 0;
	int temp = 0;

	time_t most = time(0);
	tm *ji = localtime(&most);
	
	int input;

	int kodindex = 0;
	std::string kodelotag = "Mozi_Jegy_"; 
	
	int ar = 0;

	cinemaCity.kiir();
	std::cout <<std::endl << std::endl;

	k.kezdooldal();
	std::cin >> input;
	while (!Inputell::menuell(input) || input!=3 )
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 1)
		{
			system("cls");
			k.jelenlegiFilmek(t);
			std::cout << std::endl;
			system("pause");
			system("cls");
			k.kezdooldal();
			std::cin >> input;
		}
		else if (input == 2)
		{
			system("cls");
			k.jegyVasarlas(t);
			std::cin >> filmindex;

			while (filmindex <1 || filmindex > t.filmek.size())
			{
				std::cout << std::endl<< "Nincs ilyen indexû film! Adjon meg újat: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> filmindex;
			}
			k.teremKiiras(t);
			std::cin >> teremindex;

			while (teremindex <1 || teremindex > t.termek.size())
			{
				std::cout << std::endl << "Nincs ilyen indexû terem! Adjon meg újat: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> teremindex;
			}
			std::cout << std::endl << "Hány jegyet szeretne foglalni (1-10 db): ";
			std::cin >> jegydb;

			while (!Inputell::indexell(jegydb))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Hány jegyet szeretne foglalni (1-10 db): ";
				std::cin >> jegydb;
			}
			std::cout << "[1]   Normál" << std::endl << "[2]   Diák" << std::endl << "[3]   Nyugdíjas" << std::endl;
			std::cout << std::endl << "Válasszon jegytípust: ";
			std::cin >> tipusindex;

			while (!Inputell::menuell(tipusindex))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<std::endl<< "Válasszon jegytípust: ";
				std::cin >> tipusindex;
			}

			if (tipusindex == 1) {
				ar = Akcio::alapar;
				felh.setPenztarca(felh.getPenztarca() - ar*jegydb);
			}
			else if (tipusindex == 2)
			{
				ar = Akcio::getDiakAr();
				felh.setPenztarca(felh.getPenztarca() - ar * jegydb);
			}
			else if (tipusindex == 3)
			{
				ar = Akcio::getNyugdijasAr();
				felh.setPenztarca(felh.getPenztarca() - ar * jegydb);
			}

			for (int i = 0; i < jegydb; i++)
			{
				t.termek[teremindex - 1].ulesKiir();
				kodindex++;

				std::cout << std::endl << "Sor: ";
				std::cin >> sorindex;

				while (!Inputell::indexell(sorindex))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << "Sor: ";
					std::cin >> sorindex;
				}
				std::cout << std::endl << "Oszlop: ";
				std::cin >> oszlopindex;

				while (!Inputell::indexell(oszlopindex))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << "Oszlop: ";
					std::cin >> oszlopindex;
				}

				while (!t.termek[teremindex - 1].ugyanodaFoglal(sorindex-1, oszlopindex-1))
				{
					t.termek[teremindex - 1].ulesKiir();
					std::cout << std::endl << "Sor: ";
					std::cin >> sorindex;

					while (!Inputell::indexell(sorindex))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Sor: ";
						std::cin >> sorindex;
					}
					std::cout << std::endl << "Oszlop: ";
					std::cin >> oszlopindex;

					while (!Inputell::indexell(oszlopindex))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Oszlop: ";
						std::cin >> oszlopindex;
					}
				}
				t.termek[teremindex - 1].ulesFoglal(sorindex-1, oszlopindex-1);

				Jegy jegy = Jegy(kodelotag + std::to_string(kodindex), sorindex, oszlopindex, ar, 1900 + ji->tm_year, 1 + ji->tm_mon, ji->tm_mday,t.filmek[filmindex-1]);
				
				jegyek.push_back(jegy);
			}
			std::cout << std::endl << "Kér számlát a vásárlásról? (I/N): ";
			std::cin >> szamlae;

			while (!Inputell::inell(szamlae))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Kér számlát a vásárlásról? (I/N): ";
				std::cin >> szamlae;
			}
			
			if (toupper(szamlae) == 'I')
			{
				Szamla::szamlaJegy(felh, jegyek, t.termek[teremindex-1]);
				std::cout << std::endl << "Számla kiadva!" << std::endl;
				std::cout << "Felhasználó maradék pénze: " << felh.getPenztarca();
			}
			else if (toupper(szamlae) == 'N')
			{
				std::cout << std::endl << "A vásárlás részletei: " << std::endl;
				for (Jegy j : jegyek)
					j.jegyKiir();
				
				std::cout << "Felhasználó maradék pénze: " << felh.getPenztarca();
			}
			std::cout << std::endl << std::endl << "A program leáll, megvan a kettes!"<< std::endl;
			exit(0);

			/*std::cout << std::endl;
			system("pause");
			system("cls");
			k.kezdooldal();*/

			//std::cin >> input;
		}
		else if (input == 3)
		{
			exit(0);
		}
		else
		{
			std::cout << "Válasszon (1,2,3): ";
			std::cin >> input;
		}
	}
}
