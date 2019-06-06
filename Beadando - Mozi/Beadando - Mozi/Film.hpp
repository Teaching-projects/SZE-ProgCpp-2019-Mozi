#ifndef FILM_HPP
#define FILM_HPP
#include "Nyelv.cpp"
#include "Tipus.cpp"
#include "Ertekeles.hpp"
#include <vector>

class Film
{
private:
	std::string cim;
	std::string rendezo;
	Nyelv nyelv; //=Magyar
	Tipus tipus;
	std::vector<Ertekeles> ertekelesek;

public:
	Film(std::string cim, std::string rendezo, Nyelv nyelv, Tipus tipus)
	{
		this->cim = cim;
		this->rendezo = rendezo;
		this->nyelv = nyelv;
		this->tipus = tipus;
	}

	Film()
	{

	}

	void kiir();

	void ertekelesHozzaad(Ertekeles ertekeles);

	void filmKiir();

 std::string getCim()
	{
		return this->cim;
	}

	void setCim(std::string cim)
	{
		this->cim = cim;
	}

	std::string getRendezo()
	{
		return this->rendezo;
	}

	void setRendezo(std::string rendezo)
	{
		this->rendezo = rendezo;
	}

	std::string getTipus()
	{
		switch (this->tipus)
		{
		case 0: return "Akció";
		case 1: return "Vígjáték";
		case 2: return "Thriller";
		case 3: return "Horror";
		case 4: return "Misztikus";
		case 5: return "Romantikus";
		}
	}

	void setTipus(Tipus tipus)
	{
		this->tipus = tipus;
	}

	std::string getNyelv()
	{
		switch (this->nyelv)
		{
		case 0: return "Magyar";
		case 1: return "Angol";
		case 2: return "Német";
		case 3: return "Francia";
		case 4: return "Japán";
		}
	}

	void setNyelv(Nyelv nyelv)
	{
		this->nyelv = nyelv;
	}
};
#endif