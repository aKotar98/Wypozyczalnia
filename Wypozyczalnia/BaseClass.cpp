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


void BaseClass::Find(std::string nameoffile) {

	int id;
	std::string line;
	bool check = true;

	std::cout << "Wprowadz ID:";
	while (!(std::cin >> id))
	{
		std::cout << "Price has to be a number:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";

	std::fstream file(nameoffile);

	if (file.good() == true)
	{
		while (getline(file, line))
		{
			int helper = atoi(line.c_str());
			
			if ((id == helper))
			{
				std::cout << "W bazie.\n";
				check = false;
				break;
			}
		}
		if (check == true)
			std::cout << ".\n";
	}
	else
	{
		std::cout << "Cannot open the file.\n";
	}
}