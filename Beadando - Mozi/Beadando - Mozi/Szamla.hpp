#include <iostream>
#include <string>
#include <fstream>
#include "Felhasznalo.hpp"
#include "Jegy.hpp"
#include "Berlet.hpp"
#include "Terem.hpp"

class Szamla
{
	private:
		std::ofstream fajl;
		
	public:
		Szamla();	


		void szamlaJegy(Felhasznalo f, Jegy j, Terem t);
		void szamlaBerlet(Felhasznalo f, Berlet b, Terem t);

};
