#include "Tarolo.hpp"

Tarolo::Tarolo() {}

void Tarolo::filmKiir()
{
	i = 0;
	for (Film f : filmek)
	{
		std::cout << "[" << i + 1 << "] ";
		std::cout<<f.getCim();
		std::cout << std::endl;
		i++;
	}

}

void Tarolo::jelenlegiFilmek()
{
	i = 0;
	for (Film f : filmek)
	{
		

		f.filmKiir();

		std::cout << std::endl;
		i++;
	}

}


void Tarolo::filmHozzaad(Film film)
{
	filmek.push_back(film);

}
void Tarolo::filmTorol(Film film)
{
	for (int i = 0; i < filmek.size(); ++i)
	{
		if (filmek[i].getCim() == film.getCim())
		{
			filmek.erase(filmek.begin() + i);
		}
	}
}


void Tarolo::teremKiir()
{
	int i = 0;
	for (Terem t : termek)
	{
		std::cout << "[" << i + 1 << "] ";
		std::cout << t.getNev();
		std::cout << std::endl;
		i++;
	}

}
void Tarolo::teremHozzaad(Terem terem)
{
	termek.push_back(terem);

}
void Tarolo::teremTorol(Terem terem)
{
	for (int i = 0; i < termek.size(); ++i)
	{
		if (termek[i].getNev() == terem.getNev())
		{
			termek.erase(termek.begin() + i);
		}
	}
}
