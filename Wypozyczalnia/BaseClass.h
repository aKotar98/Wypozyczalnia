#pragma once
#include <iostream>

class BaseClass
{private:
	unsigned int id;
	std::string name, name2;
public:
	BaseClass();
	~BaseClass();
	void Add(std::string nameoffile);
	void Delete();
	void Show();
	void Find();
};

