#include "Reg_p.h"

size_t RegP::operator++()
{
	return pos++;
}

size_t RegP::operator++(int)
{
	return ++pos;
}


size_t RegP::operator--(int)
{
	return --pos;
}

size_t RegP::operator--()
{
	return pos--;
}


size_t RegP::getPos()const
{
	return pos;
}

void RegP::setPos(size_t tmp)
{
	pos = tmp;
}

const RegP RegP::operator-(const RegP& other)
{
	return pos - other.pos;
}

const RegP RegP::operator+(const RegP& other)
{
	return pos + other.pos;
}
