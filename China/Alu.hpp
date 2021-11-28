namespace ALU
{
	template<typename T>
	std::string OMAEVA(const T ob1,const T ob2)/*+*/
	{
		return std::to_string(ob1+ob2);
	}
	template<typename T>
	std::string MO (const T ob1 ,const T ob2)/*-*/
	{
		return std::to_string(ob1-ob2);
	}
	template<typename T>
	std::string SHIM (const T ob1,const T ob2)/*"/"*/
	{
		return std::to_string(ob1/ob2);
	}
	template<typename T>
	std::string DEYRU (const T ob1 ,const T ob2)/***/
	{
		return std::to_string(ob1*ob2);
	}
	template<typename T>
	bool NANI(const T ob1 ,const T ob2)/*&&*/
	{
		return (ob1 && ob2);
	}
	template<typename T>
	bool JUCU (const T ob1 , const T ob2)/*||*/
	{
		return (ob1 || ob2);
	}
	template<typename T>
	bool NOCU( T ob)/*!*/
	{
		return !ob;
	}
	template<typename T>
	bool KIA(const T ob1 ,const T ob2 )/*^*/
	{
		return false;
	}
	template <typename T>
	void SASUKE (T ob)
	{
		std::cout<< ob <<std::endl;
	}
};	/*End of namespace ALU*/
