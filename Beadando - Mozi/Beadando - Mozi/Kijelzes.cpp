#include "Kijelzes.hpp"

Kijelzes::Kijelzes(){}

void Kijelzes::kezdooldal()
{
	std::cout << "Mozi kezel� rendszer" << std::endl << "********************" << std::endl;
	std::cout << "[1] Jelenlegi filmek"<<std::endl;
	std::cout << "[2] Jegyv�s�rl�s" << std::endl;
	std::cout << "[3] Kil�p�s" << std::endl;
	std::cout<<"********************" << std::endl;
	std::cout << "V�lasszon (1,2,3): ";
}

void Kijelzes::jelenlegiFilmek(Tarolo t)
{
	std::cout << "Jelenlegi filmek" << std::endl << "****************" << std::endl;
	t.jelenlegiFilmek();
}

void Kijelzes::jegyVasarlas(Tarolo t)
{
	std::cout << "Jelenlegi filmek" << std::endl << "****************" << std::endl;
	t.filmKiir();
	std::cout << std::endl;
	std::cout << "V�lasszon egy filmet: ";
}

void Kijelzes::teremKiiras(Tarolo t)
{
	std::cout << std::endl;
	std::cout << "V�laszthat� termek" << std::endl << "****************" << std::endl;
	t.teremKiir();
	std::cout << std::endl;
	std::cout << "V�lasszon egy termet: ";
}
