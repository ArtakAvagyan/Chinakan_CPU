#include <iostream>

#include "RAM.h"

int main()
{
	Ram r;
	r.writeMemory(std::stoi("01"),"es im anush hayastani");
	std::cout<< r.readMemory(std::stoi("01"));

}
