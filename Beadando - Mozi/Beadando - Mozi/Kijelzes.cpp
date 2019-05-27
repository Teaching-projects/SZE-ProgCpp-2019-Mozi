
#include "Kijelzes.hpp"
#include <iostream>
#include <string.h>
#include "Tarolo.hpp"

Kijelzes::Kijelzes(){}

void Kijelzes::kezdooldal()
{
	std::cout << "Mozi kezelo rendszer" << std::endl << "********************" << std::endl;
	std::cout << "[1] Jelenlegi filmek"<<std::endl;
	std::cout << "[2] Jegyvasarlas" << std::endl;
	std::cout << "[3] Kilepes" << std::endl;
	std::cout<<"********************" << std::endl;
	std::cout << "Valasszon (1,2,3): ";

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
	std::cout << "Valasszon egy filmet: ";

}

void Kijelzes::teremKiiras(Tarolo t)
{
	std::cout << std::endl;
	std::cout << "Valaszthato termek" << std::endl << "****************" << std::endl;
	t.teremKiir();
	std::cout << std::endl;
	std::cout << "Valasszon egy termet: ";



}