#ifndef HELYSZIN_HPP
#define HELYSZIN_HPP
#include <iostream>
#include <string>
#include "Terem.hpp"
#include <list>
#include <vector>
#include <algorithm>

class Helyszin
{
private:
	std::string nev;
	std::string cim;
	std::string nyitas;
	std::string zaras;
	std::vector<Terem> termek;

public:
	Helyszin(std::string nev, std::string cim, std::string nyitas, std::string zaras)
	{
		this->nev = nev;
		this->cim = cim;
		this->nyitas = nyitas;
		this->zaras = zaras;
	}

	Helyszin()
	{

	}
	
	void kiir();

	void hozzaad(Terem terem);

	void torol(Terem terem);
	
	std::string getNev()
	{
		return this->nev;
	}

	void setNev(std::string nev)
	{
		this->nev = nev;
	}

	std::string getCim()
	{
		return this->cim;
	}

	void setLeiras(std::string cim)
	{
		this->cim = cim;
	}

	std::string getNyitas()
	{
		return this->nyitas;
	}

	void setNyitas(std::string nyitas)
	{
		this->nyitas = nyitas;
	}

	std::string getZaras()
	{
		return this->zaras;
	}

	void setZaras(std::string zaras)
	{
		this->zaras = zaras;
	}
};
#endif