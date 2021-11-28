#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <map>
#include <string>


class Ram
{
public:
    Ram() = default;
    ~Ram() = default;
public:
    std::string readMemory(int address)
    {
        auto it = this->Memory.find(address);
        if(it == Memory.end() ){
            std::cout << "Segmantation fault";
            std::exit(0);    
        }
            return it->second;
        
    }
    void writeMemory(int address,std::string value)
    {
        this->Memory[address] = value;
    }

private:
    std::map<int,std::string> Memory;
};
#endif /* RAM_H */
