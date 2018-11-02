#pragma once
#include "BaseClass.h"
#include <iostream>
/*WROC DO TEGO W WOLNEJ CHWILI
struct Date{

	int day, month, year;
	std::string datestring;
	
	Date(int day, int month, int year);
	std::string GetName();
	};
*/

class Client : public BaseClass
{
private:
	std::string city;
	int day, month, year;

public:
	Client();
	~Client();
};

