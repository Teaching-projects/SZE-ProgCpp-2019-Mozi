#include "Berlet.hpp"

std::string Berlet::isErvenyes(int ev, int honap, int nap)
{
	if (Berlet::getEvTol() <= ev && ev <= Berlet::getEvIg())
	{
		if (Berlet::getHonapTol() <= honap && honap <= Berlet::getHonapIg())
		{
			if (Berlet::getHonapTol() == Berlet::getHonapIg())
				return Berlet::getNapTol() <= nap && nap <= Berlet::getNapIg() ? "�rv�nyes" : "Nem �rv�nyes";
			else if (Berlet::getHonapTol() == honap)
				return Berlet::getNapTol() <= nap ? "�rv�nyes" : "Nem �rv�nyes";
			else if (Berlet::getHonapIg() == honap)
				return Berlet::getNapIg() >= nap ? "�rv�nyes" : "Nem �rv�nyes";
			else
				return "�rv�nyes";
		}
	}
		return "Nem �rv�nyes";		
}
