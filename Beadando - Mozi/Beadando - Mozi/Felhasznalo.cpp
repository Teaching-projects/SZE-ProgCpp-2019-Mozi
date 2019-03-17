#include <string.h>
#include <iostream>
#include "Felhasznalo.hpp"

bool felhasznalonevEll(std::string felhasznalonev)
{
	if (felhasznalonev.length() < 6)
	{
		std::cout << "Nem eleg hosszu a felhasznalonev!" << std::endl;
		return false;
	}
	else return true;
}

bool jelszoEll(std::string jelszo)
{
	/*for (int i = 0; i < jelszo.length(); i++)
	{
		if (isspace(jelszo[i])) 
		{
			std::cout << "Nem tartalmazhat szokozt!" << std::endl;
			return false;
		}
	}*/

	if (jelszo.length() < 8)
	{
		std::cout << "Nem eleg hosszu a jelszo!" << std::endl;
		return false;
	}

	int specdb = 0;
	for (int i = 0; i < jelszo.length(); i++)
	{
		if (!isalpha(jelszo[i]) && !isdigit(jelszo[i]))
		{
			specdb++;
		}
	}

	if (specdb < 1)
	{
		std::cout << "Legalabb egy specialis karaktert kell hogy tartalmazzon!" << std::endl;
		return false;
	}

	int nagybdb = 0;

	for (int i = 0; i < jelszo.length(); i++)
	{
		if (isupper(jelszo[i]))
		{
			nagybdb++;
		}
	}

	if (nagybdb < 1)
	{
		std::cout << "Legalabb egy nagybetut kell hogy tartalmazzon!" << std::endl;
		return false;
	}

	int szam = 0;

	for (int i = 0; i < jelszo.length(); i++)
	{
		if (isdigit(jelszo[i]))
		{
			szam++;
		}
	}

	if (szam < 1)
	{
		std::cout << "Legalabb egy szamot kell hogy tartalmazzon!" << std::endl;

		return false;
	}

	return true;
}
