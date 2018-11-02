#include "pch.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <fstream>

Product::Product()
{
}


Product::~Product()
{
	
}

void Product::Add(int count) {

	if (count >= 7) {
		id = (count / 7) +1;
	}
	else id = 1;

	fflush;
	std::cin.get();

	std::cout << "Podaj marke:";
	getline(std::cin, name);
	std::cout << "\n";

	std::cout << "Podaj model:";
	getline(std::cin, name2);
	std::cout << "\n";

	std::cout << "Podaj typ urzadzenia:";
	getline(std::cin, type);
	std::cout << "\n";

	std::cout << "Podaj cene wypozyczenia za dzien:";
	while (!(std::cin >> PricepD))
	{
		std::cout << "Price has to be a number:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";

	accessibility = true;


	std::cout << "Podaj rok produkcji:";
	while (!(std::cin >> YearP))
	{
		std::cout << "Year has to be a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";

}

void Product::Upload_to_File(std::string nameoffile) {
	std::fstream file(nameoffile, std::ios::app);
	if (file.good() == true)
	{
		file << id << "\n";
		file <<  name << "\n";
		file << name2 << "\n";
		file << type << "\n";
		file << PricepD << "\n";
		if (accessibility = true) {
			file <<  "Dostepny\n";
		}
		else 
			file << "Niedostepny\n";
		file << YearP << "\n";

		file.close();
	}
}
