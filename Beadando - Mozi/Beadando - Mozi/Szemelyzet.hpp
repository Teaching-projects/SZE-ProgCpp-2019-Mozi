#ifndef SZEMELYZET_HPP
#define SZEMELYZET_HPP
#include "Felhasznalo.hpp"

class Szemelyzet : public Felhasznalo
{
private:
	std::string beosztas;
	int fizetes;

public:
	Szemelyzet(std::string felhasznalonev, std::string jelszo, std::string nev, std::string szuldat, std::string email, int penztarca, std::string beosztas, int fizetes) : Felhasznalo(felhasznalonev,jelszo,nev,szuldat,email,penztarca)
	{
		this->beosztas = beosztas;
		this->fizetes = fizetes;
	}

	void szemelyzetKiir();

	std::string getBeosztas()
	{
		return this->beosztas;
	}

	int getFizetes()
	{
		return this->fizetes;
	}
};
#endif