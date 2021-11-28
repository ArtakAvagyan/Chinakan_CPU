#ifndef REG_P_H
#define REG_P_H

#include <iostream>
class RegP
{
public:
	RegP():pos{}{}
	RegP(size_t p):pos{p}{}	
public:
	size_t operator++();
	size_t operator++(int);
	size_t operator--();
	size_t operator--(int);
	operator int(){return pos;};
	const RegP operator-(const RegP&);
	const RegP operator+(const RegP&);
public:
	void setPos(size_t);
	size_t getPos()const;
private:
	size_t pos;
};/*End of RegP*/

#endif /*REG_P_H*/
