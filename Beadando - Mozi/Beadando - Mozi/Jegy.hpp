#include <iostream>
#include <string>
#include "Napok.cpp"

class Jegy
{
private:
	std::string kod;
	Napok nap;
	int sor;
	int oszlop;
	
	int ar;

public:
	Jegy(std::string kod, Napok nap,int sor, int oszlop, int ar)
	{
		this->kod = kod;
		this->nap = nap;
		this->sor = sor;
		this->oszlop = oszlop;
		this->ar = ar;
	}

public:
	std::string getKod()
	{
		return this->kod;
	}

	std::string getNap()
	{
		switch (this->nap)
		{
		case 0: return "Hetfo";
		case 1: return "Kedd";
		case 2: return "Szerda";
		case 3: return "Csutortok";
		case 4: return "Pentek";
		case 5: return "Szombat";
		case 6:  return "Vasarnap";
		}
	}

	void setNap(Napok nap)
	{
		this->nap = nap;
	}

	int getSor()
	{
		return this->sor;
	}

	void setSor(int sor)
	{
		this->sor = sor;
	}

	int getOszlop()
	{
		return this->oszlop;
	}

	void setOszlop(int oszlop)
	{
		this->oszlop = oszlop;
	}

	int getAr()
	{
		return this->ar;
	}

	void setAr(int ar)
	{
		this->ar = ar;
	}


	

};
