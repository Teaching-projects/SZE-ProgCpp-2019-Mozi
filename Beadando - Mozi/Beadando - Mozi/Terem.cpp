#include "Terem.hpp"

void Terem:: teremKiir()
{

	std::cout << "Azonosito: " << getAzonosito() << std::endl << "Nev: " << getNev() << std::endl << "Kapacitas: " << getKapacitas() << std::endl;
	if (getLegkondizalte() == true)
	{
		std::cout << "Legkondizalt";
	}
	else
	{
		std::cout << "Nem legkondizalt";
	}
	std::cout << std::endl;
}

void Terem::ulesFeltolt()
{
	int i; 
	int j;
	for (i=0; i < 10; i++)
	{
		for (j=0; j < 10; j++)
		{
			ulesek[i][j] = '*';
		}
	}
}

void Terem::ulesKiir()
{

	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ". ";
	}

	for (i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		for (j = 0; j < 10; j++)
		{
			std::cout << ulesek[i][j] << "  ";
			if (j == 9) std::cout << i + 1 << ". sor";
		}
	}
}



void Terem::ulesFoglal(int sor, int oszlop)
{
	ulesek[sor][oszlop] = 'X';
}

bool Terem::ugyanodaFoglal(int sor, int oszlop)
{
	if (ulesek[sor][oszlop] == 'X')
	{
		std::cout <<std::endl<< "Ez a hely mar foglalt, valassz masikat!" << std::endl << std::endl;
		return false;
	}
	return true;
}



