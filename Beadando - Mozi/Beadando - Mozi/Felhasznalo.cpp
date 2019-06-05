#include "Felhasznalo.hpp"

void Felhasznalo::felhasznaloKiir()
{
	std::cout << "Felhasznalonev: " << getFelhasznalonev() << std::endl << "Jelszo: " << getJelszo() << std::endl
		<< "Nev: " << getNev() << std::endl << "Szuletesi datum: " << getSzuldat() << std::endl
		<< "e-mail cim: " << getEmail() << std::endl;
}

