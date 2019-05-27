#include "Inputell.h"
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
		std::cout << std::endl << "Rossz index!" << std::endl;
		return false;
	}

	else return true;
}



