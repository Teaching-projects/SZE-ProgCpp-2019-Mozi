#include "Szemelyzet.hpp"

void Szemelyzet::szemelyzetKiir()
{
		std::cout << "Felhaszn�l�n�v: " << getFelhasznalonev() << std::endl << "Jelsz�: " << getJelszo() << std::endl 
		<< "N�v: " << getNev() << std::endl << "Sz�let�si d�tum: " << getSzuldat() << std::endl 
		<< "E-mail c�m: " << getEmail() << std::endl << "Beoszt�s: " << getBeosztas() << std::endl 
		<< "Fizet�s: " << getFizetes() << std::endl;;	
}
