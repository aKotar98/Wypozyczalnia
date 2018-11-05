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




bool Product::Find(std::string nameoffile) {

	int id1;
	std::string line;
	bool check = false;

	std::cout << "Wprowadz ID:";
	while (!(std::cin >> id1))
	{
		std::cout << "ID has to be a number:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";
	system("cls");
	std::fstream file(nameoffile);

	if (file.good() == false)
	{
		std::cout << "Cannot open the file.\n";
		exit(0);
	}

	while (getline(file, line))
	{
		int helper = atoi(line.c_str());

		if ((id1 == helper))
		{

			id = helper;

			getline(file, line);
			name = line;

			getline(file, line);
			name2 = line;

			getline(file, line);
			type = line;

			getline(file, line);
			PricepD = atof(line.c_str());
			getline(file, line);

			//accessability
			if (line == "Dostepny")
				accessibility = true;
			else accessibility = false;

			getline(file, line);
			YearP = atoi(line.c_str());

			check = true;
			break;

		}
			for (int i = 0; i < 6; i++) {
				getline(file, line);
			}
	}
	
	file.close();
	
	return check;
}

void Product::ShowObj() {
	std::cout << "\n  Id: " << id << "\n  Marka: " << name << "\n  Model: " << name2 << "\n  Typ: " << type << "\n  Cena za dzien: " << PricepD << "\n";
	if (accessibility = true)
		std::cout << "  Stan w magazynie: Dostepny\n";
	else std::cout << "Stan w magazynie: Niedostepny\n";
	std::cout << "  Rok produkcji: " << YearP<<"\n";
}