#ifndef SZAMLA_HPP
#define SZAMLA_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "Felhasznalo.hpp"
#include "Jegy.hpp"
#include "Berlet.hpp"
#include "Terem.hpp"
static std::ofstream fajl;
class Szamla
{
	
		
		
	public:
		Szamla();	

		
		static void szamlaJegy(Felhasznalo f, std::vector<Jegy> jegyek, Terem t);
		static void szamlaBerlet(Felhasznalo f, Berlet b, Terem t);

};
#endif