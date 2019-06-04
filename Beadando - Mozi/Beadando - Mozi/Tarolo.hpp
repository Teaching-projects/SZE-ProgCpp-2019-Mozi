#pragma once
#include <iostream>
#include <string.h>
#ifndef TAROLO_HPP
#define TAROLO_HPP
#include "Film.hpp"
#include "Terem.hpp"
#include <vector>
class Tarolo
{
	

public:
	Tarolo();
	void filmKiir();
	void filmHozzaad(Film film);
	void filmTorol(Film film);
	void teremKiir();
	void teremHozzaad(Terem terem);
	void teremTorol(Terem terem);
	void jelenlegiFilmek();
	std::vector<Film> filmek;
	std::vector<Terem> termek;


	int i = 0;


	int getI()
	{
		return this->i;
	}

	

};
#endif

