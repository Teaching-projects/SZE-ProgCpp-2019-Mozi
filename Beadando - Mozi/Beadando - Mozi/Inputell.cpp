#include "Inputell.h"





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
		std::cout << std::endl << "Nincs ilyen lehetoseg!";
		return false;
	}
}

bool Inputell::menuell(int szam)
{
	if (szam < 1 || szam >3 )
	{
		std::cout<<"Nincs ilyen lehetoseg!"<<std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

