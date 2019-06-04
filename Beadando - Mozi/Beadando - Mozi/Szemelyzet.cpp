#include "Szemelyzet.hpp"

void Szemelyzet::szemelyzetKiir()
{

		std::cout << "Felhasznalonev: " << getFelhasznalonev() << std::endl << "Jelszo: " << getJelszo() << std::endl 
		<< "Nev: " << getNev() << std::endl << "Szuletesi datum: " << getSzuldat() << std::endl 
		<< "e-mail cim: " << getEmail() << std::endl << "Beosztas: " << getBeosztas() << std::endl 
		<< "Fizetes: " << getFizetes() << std::endl;;
	
}