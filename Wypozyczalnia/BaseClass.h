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
	int CountLine(std::string nameoffile);
	void Delete();
	void Show();
	void Find();
};

