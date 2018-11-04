#include "pch.h"
#include "BaseClass.h"
#include <iostream>
#include <fstream>
#include <string>


BaseClass::BaseClass()
{
}


BaseClass::~BaseClass()
{
}
int BaseClass::CountLine(std::string nameoffile) {


	std::fstream file(nameoffile);
	int count = 0;
	if (file.is_open()) {
		std::string line;

		while (!file.eof()) 
		{
			getline(file, line);
			count++;

		}
		file.close();
		
	
	}
	return count;
}

bool BaseClass::check_string(std::string chstring)
{
	bool check = false;

	for (int i = 0; i < chstring.size(); i++)
	{
		if ((chstring[i] > 32 && chstring[i] < 65) || (chstring[i] > 90 && chstring[i] < 97) || chstring[i] < 32)
		{
			check = true;
			break;
		}
		else check = false;
	}

	return check;
}


int  BaseClass::GetId() {
	return id;
}

