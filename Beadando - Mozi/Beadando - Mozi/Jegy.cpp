#include <iostream>
#include <string>
#include "Jegy.hpp"

// std::string Jegy::isErvenyes(int ev, int honap, int nap)
//{
//	return (Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap) ? "Ervenyes" : "Nem ervenyes";
//
//	/*if (Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap)
//	{
//		return true;
//	}
//	else return false;*/
//}

std::string Jegy::isErvenyes(int ev, int honap, int nap)
{
	return(Jegy::getEv() == ev && Jegy::getHonap() == honap && Jegy::getNap() == nap) ? "Ervenyes" : "Nem ervenyes";
}

