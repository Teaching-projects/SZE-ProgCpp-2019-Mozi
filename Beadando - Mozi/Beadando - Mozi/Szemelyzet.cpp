#include "Szemelyzet.hpp"

void Szemelyzet::szemelyzetKiir()
{
		std::cout << "Felhasználónév: " << getFelhasznalonev() << std::endl << "Jelszó: " << getJelszo() << std::endl 
		<< "Név: " << getNev() << std::endl << "Születési dátum: " << getSzuldat() << std::endl 
		<< "E-mail cím: " << getEmail() << std::endl << "Beosztás: " << getBeosztas() << std::endl 
		<< "Fizetés: " << getFizetes() << std::endl;;	
}
