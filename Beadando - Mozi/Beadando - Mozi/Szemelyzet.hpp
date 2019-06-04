#ifndef SZEMELYZET_HPP
#define SZEMELYZET_HPP
#include <iostream>
#include <string>
#include "Felhasznalo.hpp"

class Szemelyzet : public Felhasznalo
{
private:
	/*std::string felhasznalonev;
	std::string jelszo;
	std::string nev;
	std::string szuldat;
	std::string email;*/
	std::string beosztas;
	//std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email
public:
	Szemelyzet(std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email, std::string beosztas) : Felhasznalo(felhasznalonev,jelszo,nev,szuldat,email)
	{
		this->beosztas = beosztas;
	}

	std::string getBeosztas()
	{
		return this->beosztas;
	}
	
};

#endif