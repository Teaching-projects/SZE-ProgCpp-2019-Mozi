#ifndef FELHASZNALO_HPP
#define FELHASZNALO_HPP
#include <iostream>
#include <string>

class Felhasznalo
{
private:
	std::string felhasznalonev;
	std::string jelszo;
	std::string nev;
	std::string szuldat;
	std::string email;
	int penztarca;

public:
	Felhasznalo(std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email, int penztarca)
	{
		this->felhasznalonev = felhasznalonev;
		this->jelszo = jelszo;
		this->nev = nev;
		this->szuldat = szuldat;
		this->email = email;
		this->penztarca = penztarca;
	}

	void felhasznaloKiir();

	void setPenztarca(int penztarca)
	{
		this->penztarca = penztarca;
	}

	int getPenztarca()
	{
		return this->penztarca;
	}

	std::string getFelhasznalonev()
	{
		return this->felhasznalonev;
	}

	std::string getJelszo()
	{
		return this->jelszo;
	}

	std::string getNev()
	{
		return this->nev;
	}

	std::string getSzuldat()
	{
		return this->szuldat;
	}

	std::string getEmail()
	{
		return this->email;
	}
};
#endif