#pragma once
#include "BaseClass.h"
#include <iostream>

struct Date{
	int day, month, year;
};

class Client : public BaseClass
{
private:
	std::string city;
	Date date;

public:
	Client();
	~Client();
};

