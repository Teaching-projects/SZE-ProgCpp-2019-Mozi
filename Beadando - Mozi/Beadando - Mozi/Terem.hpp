#include <iostream>
#include <string>
#ifndef TEREM_HPP
#define TEREM_HPP

class Terem
{
private:
	int azonosito;
	std::string nev;
	int kapacitas;
	bool legkondizalte;
	char ulesek[10][10];

public:
	Terem(int azonosito, std::string nev, int kapacitas, bool legkondizalte)
	{
		this->azonosito = azonosito;
		this->nev = nev;
		this->kapacitas = kapacitas;
		this->legkondizalte = legkondizalte;
		ulesFeltolt();
	}

	void ulesKiir();

	void ulesFeltolt();

	void teremKiir();

	void ulesFoglal(int sor, int oszlop);

	bool ugyanodaFoglal(int sor, int oszlop);

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