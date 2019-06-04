#ifndef ERVENYES_HPP
#define ERVENYES_HPP
#pragma once
#include <string>



class Ervenyes
{
	
public:

	virtual std::string isErvenyes(int ev, int honap, int nap)=0;
	// bool isErvenyes(int ev, int honap, int nap);
};

#endif