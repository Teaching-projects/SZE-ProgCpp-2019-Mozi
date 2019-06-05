#ifndef MOZI_HPP
#define MOZI_HPP
#include "Helyszin.hpp"

class Mozi
{
private:
	std::string azonosito;
	std::vector<Helyszin> helyszinek;

public:
	Mozi(std::string azonosito)
	{
		this->azonosito = azonosito;
	}

	void kiir();
	void hozzaad(Helyszin helyszin);
	void torol(Helyszin helyszin);

	std::string getAzonosito()
	{
		return this->azonosito;
	}

	void setAzonosito(std::string azonosito)
	{
		this->azonosito = azonosito;
	}

};
#endif