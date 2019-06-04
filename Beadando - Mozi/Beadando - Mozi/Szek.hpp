#ifndef SZEK_HPP
#define SZEK_HPP
#pragma once
class Szek
{
private:
	int sor;
	int oszlop;

public:
	Szek(int sor, int oszlop)
	{
		this->sor = sor;
		this->oszlop = oszlop;
	}

	int getSor()
	{
		return this->sor;
	}

	int getOszlop()
	{
		return this->oszlop;
	}

	void setSor(int sor)
	{
		this->sor = sor;
	}
	void setOszlop(int oszlop)
	{
		this->oszlop = oszlop;
	}


};

#endif