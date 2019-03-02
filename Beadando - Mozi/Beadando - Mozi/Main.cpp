#include <iostream>
#include "Ertekeles.hpp"
#include "Film.hpp"
#include <string>
#include "Jegy.hpp"
#include "Akcio.hpp"

int main() {
	
	

	Film f = Film("Asd","Dsa",Nyelv::Angol,Tipus::Misztikus);

		Ertekeles e1 = Ertekeles("Teszt", 5);

		
		
		Jegy j = Jegy("asd",Napok::Hetfo,3,5,5000);

		//std::cout << j.getKod() << j.getNap() << j.getSor() << j.getOszlop() << j.getAr() << std::endl;
		
		std::cout << Akcio::getAkciosAr(j.getAr());
		
	
		/*std::cout << f.getCim() << f.getRendezo() << f.getNyelv() << f.getTipus();
		
		std::cout << std::endl;
		f.setNyelv(Nyelv::Japan);
		std::cout << f.getNyelv();*/

		std::cin.ignore();

	/*std::cout<<e1.getLeiras()<<std::endl;
	e1.csillagkiir();

	e1.setLeiras("asd");
	e1.setCsillagdb(11);
	std::cout << e1.getLeiras() << std::endl << e1.getCsillagdb();
	e1.csillagkiir();
	std::cin.ignore();*/

	return 0;
}
