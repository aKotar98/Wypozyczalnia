#pragma once
#include <iostream>

class BaseClass
{protected:
	 int id;
	std::string name2;
	std::string name;
public:
	BaseClass();
	BaseClass(int idd, std::string namee, std::string namee2);
	~BaseClass();
	bool check_string(std::string chstring);
	void autoid();
	int CountLine(std::string nameoffile);
	void Delete(int id,std::string nameoffile);
	int GetId();
};

