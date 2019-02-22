#include <iostream>
#include <string>


class Ertekeles
{
public:
	Ertekeles(std::string leiras, int csillagdb)
	{
		this->leiras = leiras;
		this->csillagdb = csillagdb;
	};

private:
	std::string leiras;
	int csillagdb;
	

public:
	int getCsillagdb()
	{
		return csillagdb;
	}
	void setCsillagdb(int csillagdb) { this->csillagdb = csillagdb; }

	std::string getLeiras()
	{
		return this->leiras;
	}

	void setLeiras(std::string leiras)
	{
		this->leiras = leiras;
	}

	void csillagkiir(int csillagdb);

};
