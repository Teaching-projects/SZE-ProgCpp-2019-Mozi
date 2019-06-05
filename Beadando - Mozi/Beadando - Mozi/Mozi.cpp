#include "Mozi.hpp"

void Mozi::kiir()
{
	std::cout << "Azonositó: "<< getAzonosito()<<std::endl;

	for (Helyszin h : helyszinek)
	{
		h.kiir();
	}
}

void Mozi::hozzaad(Helyszin helyszin)
{
	helyszinek.push_back(helyszin);
}

void Mozi::torol(Helyszin helyszin)
{
	for (int i = 0; i < helyszinek.size(); ++i)
	{
		if (helyszinek[i].getNev() == helyszin.getNev())
		{
			helyszinek.erase(helyszinek.begin() + i);
		}
	}
}