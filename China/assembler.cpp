#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <string>
#include <algorithm>

#include "Alu.h"
#include "Registor.h"
#include "Reg_p.h"
#include "RAM.h"


std::ifstream fin;




class Cpu
{
	public:
		Cpu(std::string str):file_name{str}{}
		~Cpu(){}
		void read();

	private:
		int decide(std::string);
		Reg& find_reg(std::string);
	private:
		std::streampos oldpos;
		std::ofstream fout;
		std::vector<std::string> vec;
		RegP sp{};
		RegP cuc{};
		Reg reg[4]{};
		Ram Mem;
		std::string file_name;
};

Reg& Cpu::find_reg(std::string str)
{
	if(str == "ICH"){return reg[0];}
	else if(str == "NI"){return reg[1];}
	else if(str == "SAN"){return reg[2];}
	else if(str == "Shi"){return reg[3];}
	else
	{
		std::cout << "Bad Input" <<std::endl;
		exit(0);
	}
	return reg[0];
}

int Cpu::decide(std::string str)
{
	std::regex number ("^[1-9][0-9]+$");
	std::regex flot ("^[0-9]+/.[0-9]+$");
	std::regex address ("^0+[0-9]+$");

	if(std::regex_search(str, flot)){return 1;}
	else if(std::regex_search(str, number)) {return 0;}
	else if(std::regex_search(str, address)) {return -1;}
	return -100;
}


void Cpu::read()
{
	fin.open(file_name);
	if(!fin.is_open()) {
		std::cout << "Could not open file";
		exit(0);
	}
	else
	{
		while(!fin.eof()){
			std::string str;
			getline(fin, str);
			std::istringstream s(str);
			while(!s.eof())
			{
				s >> str;
				vec.push_back(str);
			}
			if(vec[0] == "OMAEVA")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(this->decide(vec[3]))
				{
					case 0:
						i.setVal(ALU::OMAEVA(std::stoi(i.getVal()),std::stoi(vec[3])));
						break;
					case 1:
						i.setVal(ALU::OMAEVA(std::stod(i.getVal()),std::stod(vec[3])));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(ALU::OMAEVA(std::stod(i.getVal()),std::stod(g.getVal())));
						break;
				}
			}
			else if(vec[0] == "MO")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(ALU::MO(std::stoi(i.getVal()),std::stoi(vec[3])));
						break;
					case 1:
						i.setVal(ALU::MO(std::stod(i.getVal()),std::stod(vec[3])));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(ALU::MO(std::stod(i.getVal()),std::stod(g.getVal())));
						break;
				}
			}
			else if(vec[0] == "SHIM")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(ALU::SHIM(std::stoi(i.getVal()),std::stoi(vec[3])));
						break;
					case 1:
						i.setVal(ALU::SHIM(std::stod(i.getVal()),std::stod(vec[3])));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(ALU::SHIM(std::stod(i.getVal()),std::stod(g.getVal())));
						break;
				}
			}
			else if(vec[0] == "DEYRU")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(ALU::DEYRU(std::stoi(i.getVal()),std::stoi(vec[3])));
						break;
					case 1:
						i.setVal(ALU::DEYRU(std::stod(i.getVal()),std::stod(vec[3])));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(ALU::DEYRU(std::stod(i.getVal()),std::stod(g.getVal())));
						break;
				}
			}
			else if(vec[0] == "NANI")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(std::to_string(ALU::NANI(std::stoi(i.getVal()),std::stoi(vec[3]))));
						break;
					case 1:
						i.setVal(std::to_string(ALU::NANI(std::stod(i.getVal()),std::stod(vec[3]))));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(std::to_string(ALU::NANI(std::stod(i.getVal()),std::stod(g.getVal()))));
						break;
				}
			}    
			else if(vec[0] == "JUCU") 
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(std::to_string(ALU::JUCU(std::stoi(i.getVal()),std::stoi(vec[3]))));
						break;
					case 1:
						i.setVal(std::to_string(ALU::JUCU(std::stod(i.getVal()),std::stod(vec[3]))));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						i.setVal(std::to_string(ALU::JUCU(std::stod(i.getVal()),std::stod(g.getVal()))));
						break;
				}
			}
			else if(vec[0] == "NOCU")
			{
				Reg& i = find_reg(vec[1]);
				auto tmp = i.getVal();
				i.setVal(std::to_string(ALU::NOCU(std::stoi(tmp))));
			}
			else if(vec[0] == "KIA")
			{
				Reg& i = find_reg(vec[1]);
				if(vec[2] != ","){exit(0);}
				auto i_t = i.getVal();
				switch(decide(vec[3]))
				{
					case 0:
						i.setVal(std::to_string(ALU::KIA(std::stoi(i_t),std::stoi(vec[3]))));
						break;
					case 1:
						i.setVal(std::to_string(ALU::KIA(std::stod(i_t),std::stod(vec[3]))));
						break;
					default:
						Reg& g = find_reg(vec[3]);
						auto g_t = g.getVal();
						i.setVal(std::to_string(ALU::KIA(std::stod(i_t),std::stod(g_t))));
						break;
				}
			}
			else if(vec[0] == "NARUTO")
			{
				if(vec[2] != ","){exit(0);}
				switch(decide(vec[1]))
				{
					case -1:
						Mem.writeMemory(std::stoi(vec[1]),vec[3]);
						break;
					case -100:
						Reg& i = find_reg(vec[1]);
						switch(decide(vec[3]))
						{
							case -1:
								i.setVal(Mem.readMemory(std::stoi(vec[3])));
								break;
							case 0:
								i.setVal(vec[3]);
								break;
							case 1:
								i.setVal(vec[3]);
								break;
							default:
								Reg& g = find_reg(vec[3]);
								i.setVal(g.getVal());
								break;
						}
				}
			}
			else if(vec[0] == "SASUKE")
			{
				Reg& i = find_reg(vec[1]);
				ALU::SASUKE<std::string>(i.getVal());
			}
			else if(vec[0] == "JUMPO>")
			{
				Reg& i = find_reg(vec[1]);
				Reg& g = find_reg(vec[3]);
				if(i.getVal()>g.getVal())
				{
					vec.clear();
					fin.seekg(oldpos);
					read(); 
				}

			}
			else if(vec[0] == "JUMPO<")
			{
				Reg& i = find_reg(vec[1]);
				Reg& g = find_reg(vec[3]);
				if(i.getVal()<g.getVal())
				{
					vec.clear();
					fin.seekg(oldpos);
					read(); 
				}
			}
			else if(vec[0] == "JUMPO=")
			{
				Reg& i = find_reg(vec[1]);
				Reg& g = find_reg(vec[3]);
				if(i.getVal()==g.getVal())
				{
					vec.clear();
					fin.seekg(oldpos);
					read(); 
				}
			}
			else if(vec[0] == "JUMPO!")
			{
				Reg& i = find_reg(vec[1]);
				Reg& g = find_reg(vec[3]);
				if(i.getVal()==g.getVal())
				{
					vec.clear();
					fin.seekg(oldpos);
					read(); 
				}
			}
			else 
			{
				if(vec[1] != ":"){exit(0);}
				oldpos = fin.tellg();
			}
			vec.clear();
		}
	}
}
int main( int argc ,char* argv[])
{
	if(argc = 1){
	Cpu obj(argv[1]);
	obj.read();
	}else
	{
		while(true){}
	}
}
