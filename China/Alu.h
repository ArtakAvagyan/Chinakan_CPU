#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>

namespace ALU
{
	template<typename T>
	std::string OMAEVA(const T,const T);/*+*/
	template<typename T>
	std::string MO (T,const T);/*-*/
	template<typename T>
	std::string SHIM (const T,const T);/*"/"*/
	template<typename T>
	std::string DEYRU (const T,const T);/***/
	template<typename T>
	bool NANI(const T,const T);/*&&*/
	template<typename T>
	bool JUCU (const T,const T);/*||*/
	template<typename T>
	bool NOCU(T);/*!*/
	template<typename T>
	bool KIA(const T,const T);/*^*/
	template <typename T>
	void SASUKE (T ob);
};	/*End of namespace ALU*/
#include "Alu.hpp"
#endif	/*ALU_H*/
