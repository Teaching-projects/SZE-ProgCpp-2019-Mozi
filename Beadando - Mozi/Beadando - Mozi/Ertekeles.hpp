#include <iostream>
#include <string>


class Ertekeles
{
public:
	Ertekeles(std::string leiras, int csillagdb)
	{
		if (csillagdb > 10 || csillagdb < 0)
		{
			this->csillagdb = 5;
		}
		else
		{
			this->leiras = leiras;
			this->csillagdb = csillagdb;
		}
	};

private:
	std::string leiras;
	int csillagdb;
	

public:
	int getCsillagdb()
	{
		return csillagdb;
	}
	void setCsillagdb(int csillagdb) 
	{ 
		if (csillagdb <= 10 && csillagdb >= 1)
		{

			this->csillagdb = csillagdb;
		}
	}

	std::string getLeiras()
	{
		return this->leiras;
	}

	void setLeiras(std::string leiras)
	{
		this->leiras = leiras;
	}

	void csillagkiir();

};
