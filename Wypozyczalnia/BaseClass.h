#pragma once
#include <iostream>

class BaseClass
{protected:
	unsigned int id;
	std::string name2;
	std::string name;
public:
	BaseClass();
	~BaseClass();
	bool check_string(std::string chstring);
	int CountLine(std::string nameoffile);
	
	int GetId();
};

