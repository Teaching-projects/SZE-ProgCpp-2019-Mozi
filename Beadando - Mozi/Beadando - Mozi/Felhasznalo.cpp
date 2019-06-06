#include "Felhasznalo.hpp"

void Felhasznalo::felhasznaloKiir()
{
	std::cout << "Felhasználonév: " << getFelhasznalonev() << std::endl << "Jelszó: " << getJelszo() << std::endl
		<< "Név: " << getNev() << std::endl << "Születési dátum: " << getSzuldat() << std::endl
		<< "E-mail cím: " << getEmail() << std::endl;
}
