#pragma once
#include <string>
#include <iostream>

class Berlet
{
private:
	int evTol;
	int evIg;
	int honapTol;
	int honapIg;
	int napTol;
	int napIg;

public:
	Berlet(int evTol, int honapTol, int napTol, int evIg, int honapIg, int napIg)
	{
		
		this->evTol = evTol;
		this->evIg = evIg;
		this->honapTol = honapTol;
		this->honapIg = honapIg;
		this->napTol = napTol;
		this->napIg = napIg;
	}

	virtual std::string isErvenyes(int ev, int honap, int nap);


	
	int getEvTol()
	{
		return this->evTol;
	}

	void setEvTol(int evTol)
	{
		this->evTol = evTol;
	}

	int getEvIg()
	{
		return this->evIg;
	}

	void setEvIg(int evIg)
	{
		this->evIg = evIg;
	}

	int getHonapTol()
	{
		return this->honapTol;
	}

	void setHonapTol(int honapTol)
	{
		this->honapTol = honapTol;
	}

	int getHonapIg()
	{
		return this->honapIg;
	}

	void setHonapIg(int honapIg)
	{
		this->honapIg = honapIg;
	}

	int getNapTol()
	{
		return this->napTol;
	}

	void setNapTol(int napTol)
	{
		this->napTol = napTol;
	}

	int getNapIg()
	{
		return this->napIg;
	}

	void setNapIg(int napIg)
	{
		this->napIg = napIg;
	}

};

