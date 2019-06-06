#include "Berlet.hpp"

std::string Berlet::isErvenyes(int ev, int honap, int nap)
{
	if (Berlet::getEvTol() <= ev && ev <= Berlet::getEvIg())
	{
		if (Berlet::getHonapTol() <= honap && honap <= Berlet::getHonapIg())
		{
			if (Berlet::getHonapTol() == Berlet::getHonapIg())
				return Berlet::getNapTol() <= nap && nap <= Berlet::getNapIg() ? "Érvényes" : "Nem érvényes";
			else if (Berlet::getHonapTol() == honap)
				return Berlet::getNapTol() <= nap ? "Érvényes" : "Nem érvényes";
			else if (Berlet::getHonapIg() == honap)
				return Berlet::getNapIg() >= nap ? "Érvényes" : "Nem érvényes";
			else
				return "Érvényes";
		}
	}
		return "Nem érvényes";		
}
