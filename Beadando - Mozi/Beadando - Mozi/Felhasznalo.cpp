#include "Felhasznalo.hpp"

void Felhasznalo::felhasznaloKiir()
{
	std::cout << "Felhaszn�lon�v: " << getFelhasznalonev() << std::endl << "Jelsz�: " << getJelszo() << std::endl
		<< "N�v: " << getNev() << std::endl << "Sz�let�si d�tum: " << getSzuldat() << std::endl
		<< "E-mail c�m: " << getEmail() << std::endl;
}
