#ifndef JEGY_HPP
#define JEGY_HPP
#include <iostream>
#include <string>
#include "Napok.cpp"
#include "Film.hpp"
#include "Helyszin.hpp"



class Jegy 
{
private:
	std::string kod;
	//Napok nap;
	int sor;
	int oszlop;
	int ev;
	int honap;
	int nap;
	Film f;
	//Helyszin h;   kesobb kell majd
	
	int ar;

public:
	Jegy(std::string kod, int sor, int oszlop, int ar, int ev, int honap, int nap, Film f)
	{
		this->kod = kod;
		this->sor = sor;
		this->oszlop = oszlop;
		this->ar = ar;
		this->ev = ev;
		this->honap = honap;
		this->nap = nap;
		this->f = f;
		//this->h = h;
	}


public:

	void jegyKiir();

	std::string getKod()
	{
		return this->kod;
	}

	 //std::string isErvenyes(int ev, int honap, int nap);

	virtual std::string isErvenyes(int ev, int honap, int nap);

	/*{
		return this->ev == ev && this->honap == honap && this->nap == nap;
	}*/


	/*std::string getNap()
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
	}*/

	/*void setNap(Napok nap)
	{
		this->nap = nap;
	}*/

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

	 int getEv()
	{
		return this->ev;
	}
	
	void setEv(int ev)
	{
		this->ev = ev;
	}

	int getHonap()
	{
		return this->honap;
	}

	void setHonap(int honap)
	{
		this->honap = honap;
	}

	int getNap()
	{
		return this->nap;
	}

	void setNap(int nap)
	{
		this->nap = nap;
	}
	

};
#endif