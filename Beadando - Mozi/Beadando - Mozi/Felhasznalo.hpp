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

public:
	Felhasznalo(std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email)
	{
		this->felhasznalonev = felhasznalonev;
		this->jelszo = jelszo;
		this->nev = nev;
		this->szuldat = szuldat;
		this->email = email;
	}

	bool felhasznalonevEll(std::string felhasznalonev);
	bool jelszoEll(std::string jelszo);

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