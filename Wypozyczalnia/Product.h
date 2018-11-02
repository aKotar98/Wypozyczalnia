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
	//void Add();

};

