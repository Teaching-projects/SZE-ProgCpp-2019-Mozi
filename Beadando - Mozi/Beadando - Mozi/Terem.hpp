#include <iostream>
#include <string>
#ifndef TEREM_HEADER
#define TEREM_HEADER


class Terem
{
private:
	int azonosito;
	std::string nev;
	int kapacitas;
	bool legkondizalte;

public:
	Terem(int azonosito, std::string nev, int kapacitas, bool legkondizalte)
	{
		this->azonosito = azonosito;
		this->nev = nev;
		this->kapacitas = kapacitas;
		this->legkondizalte = legkondizalte;
	}

	void teremKiir();

	bool getLegkondizalte()
	{
		return legkondizalte;
	}

	void setLegkondizalte(bool legkondizalte)
	{
		this->legkondizalte = legkondizalte;
	}

	int getKapacitas()
	{
		return kapacitas;
	}

	void setKapacitas(int kapacitas)
	{
		this->kapacitas = kapacitas;
	}


	std::string getNev()
	{
		return nev;
	}

	void setNev(std::string nev)
	{
		this->nev = nev;
	}

	int getAzonosito()
	{
		return azonosito;
	}

	void setAzonosito(int azonosito)
	{
		this->azonosito = azonosito;
	}

};

#endif