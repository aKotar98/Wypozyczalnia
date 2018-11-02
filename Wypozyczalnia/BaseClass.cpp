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
