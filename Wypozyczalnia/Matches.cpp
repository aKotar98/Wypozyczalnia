#include "pch.h"
#include "Matches.h"
#include <iostream>
#include <fstream>
#include <string>


Matches::Matches(std::string nameoffile, int productIdd, int clientIdd):productId(productIdd),clientid(clientIdd)
{

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
	if (count > 3)
		matchesId = count / 3;
	else matchesId = 1;
}

void Matches::Upload_to_File(std::string nameoffile) {
	std::fstream file(nameoffile, std::ios::app);
	if (file.good() == true)
	{
		file << matchesId << "\n";
		file << clientid << "\n";
		file << productId << "\n";
	

		file.close();
	}
}

bool Matches::Find(std::string nameoffile) {
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
		std::cout << "Cannot open the file FIND.\n";
		exit(0);
	}

	while (getline(file, line))
	{
		int helper = atoi(line.c_str());

		if ((id1 == helper))
		{
			matchesId = helper;
			getline(file, line);
			clientid = atoi(line.c_str());
			getline(file, line);
			productId = atoi(line.c_str());
			check = true;
			break;
		}
		for (int i = 0; i < 2; i++) {
			getline(file, line);
		}
	}
	file.close();
	return check;
}
Matches::~Matches()
{
}

int Matches::GetclientId() {
	return clientid;
}
int Matches::GetmatchesId(){

	return matchesId;
}

int Matches::GetproductId() {
	return productId;
}