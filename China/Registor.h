#ifndef REGISTOR_H
#define REGISTOR_H

#include <iostream>
#include <string>


class Reg
{
public:
	void setVal(const std::string&);
	std::string getVal()const;
private:
	std::string val;
};/*End of Reg*/
#endif /*REGISTOR_H*/
