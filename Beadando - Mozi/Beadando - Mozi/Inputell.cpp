#include "Inputell.h"
#include "Tarolo.hpp"
#include <iostream>
#include <string>

//bool inputell::szamell(int szam)
//{
//	
//}

bool Inputell::indexell(int szam)
{
	

	if (szam < 1 || szam>10)
	{
		std::cout << std::endl << "Nincs ilyen lehetoseg!" << std::endl;
		return false;

	}

	else return true;
}

bool Inputell::inell(char karakter)
{
	if (toupper(karakter) == 'I' || toupper(karakter) == 'N')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Inputell::menuell(int szam)
{
	if (szam < 1 || szam >3)
	{
		std::cout<<"Nincs ilyen lehetoseg!"<<std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

//bool Inputell::filmszamell(int szam)
//{
//	int filmdb = 0;
//	filmdb = Tarolo::filmdb();
//	
//}



