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
void BaseClass::Add(std::string nameoffile) {


	std::fstream file(nameoffile);
	if (file.is_open()) {
		std::string line;
		int count = 0;
		while (!file.eof()) {
			getline(file, line);
			count++;
		}
		file.close();
		std::cout << count;
		
	}
	
}
