#include "Kijelzes.hpp"

Kijelzes::Kijelzes(){}

void Kijelzes::kezdooldal()
{
	std::cout << "Mozi kezelõ rendszer" << std::endl << "********************" << std::endl;
	std::cout << "[1] Jelenlegi filmek"<<std::endl;
	std::cout << "[2] Jegyvásárlás" << std::endl;
	std::cout << "[3] Kilépés" << std::endl;
	std::cout<<"********************" << std::endl;
	std::cout << "Válasszon (1,2,3): ";
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
	std::cout << "Válasszon egy filmet: ";
}

void Kijelzes::teremKiiras(Tarolo t)
{
	std::cout << std::endl;
	std::cout << "Választható termek" << std::endl << "****************" << std::endl;
	t.teremKiir();
	std::cout << std::endl;
	std::cout << "Válasszon egy termet: ";
}
