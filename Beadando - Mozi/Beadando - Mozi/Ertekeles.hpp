#ifndef ERTEKELES_HPP
#define ERTEKELES_HPP
#include <iostream>
#include <string>

class Ertekeles
{
private:
	std::string leiras;
	int csillagdb;

public:
	Ertekeles(std::string leiras, int csillagdb)
	{
		if (csillagdb > 10 || csillagdb < 0)
		{
			std::cout << "Hibás érték lett megadva, alapértemezett lett beállítva!" << std::endl;
			this->csillagdb = 5;
		}
		else
		{
			this->leiras = leiras;
			this->csillagdb = csillagdb;
		}
	};

public:
	int getCsillagdb()
	{
		return csillagdb;
	}

	void setCsillagdb(int csillagdb) 
	{ 
		if (csillagdb <= 10 && csillagdb >= 1)
			this->csillagdb = csillagdb;
	}

	std::string getLeiras()
	{
		return this->leiras;
	}

	void setLeiras(std::string leiras)
	{
		this->leiras = leiras;
	}

	void csillagKiir();

	void ertekelesKiir();
};
#endif