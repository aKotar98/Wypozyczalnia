#pragma once
#include "BaseClass.h"
class Product :	public BaseClass
{private:
	std::string type;
	float PricepD;
	bool accessibility;
	int YearP;

public:
	Product();
	~Product();
	void Add(int count);
	void Upload_to_File(std::string nameoffile);

};
