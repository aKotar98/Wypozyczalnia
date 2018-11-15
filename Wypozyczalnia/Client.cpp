#include "pch.h"
#include "Client.h"
#include <iostream>
#include <string>
#include <fstream>



Client::Client()
{
}


Client::~Client()
{
}

void Client::AddClient(int count)
{

	if (count >= 7) {
		id = (count / 7) + 1;
	}
	else id = 1;

	fflush;
	std::cin.get();

	std::cout << "Podaj Imie:";
	getline(std::cin, name);
	std::cout << "\n";
	while (check_string(name) == true)
	{
		std::cout << "You have to enter letters.\Podaj imie: ";
		getline(std::cin, name);
	}

	std::cout << "Podaj Nazwisko:";
	getline(std::cin, name2);
	std::cout << "\n";
	while (check_string(name2) == true)
	{
		std::cout << "You have to enter letters.\Podaj nazwisko: ";
		getline(std::cin, name2);
	}


	std::cout << "Podaj miasto:";
	getline(std::cin, city);
	std::cout << "\n";
	while (check_string(city) == true)
	{
		std::cout << "You have to enter letters.\Podaj miasto: ";
		getline(std::cin, city);
	}


	
	std::cout << "Podaj dzien urodzin";
	while (!(std::cin >> day))
	{
		std::cout << "Day has to be a number:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";

	

	std::cout << "Podaj miesiac urodzin:";
	while (!(std::cin >> month))
	{
		std::cout << "Month has to be a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";

	std::cout << "Podaj rok urodzin";
	while (!(std::cin >> year))
	{
		std::cout << "Year has to be a number:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fflush;
	std::cin.get();
	std::cout << "\n";
}

void Client::Upload_to_File(std::string nameoffile)
{
	std::fstream file(nameoffile, std::ios::app);
	if (file.good() == true)
	{
		file << id << "\n";
		file << name << "\n";
		file << name2 << "\n";
		file << city << "\n";
		file << day<< "\n";
		file << month << "\n";
		file << year << "\n";
	
		file.close();
	}

	
}




bool Client::Find(std::string nameoffile) {

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
	//file.open(nameoffile, std::ios::in);

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
				id = helper;

				getline(file, line);
				name = line;
				
				getline(file, line);
				name2 = line;
				
				getline(file, line);
				city = line;
				
				getline(file, line);
				day = atoi(line.c_str());
				
				getline(file, line);
				month = atof(line.c_str());
				
				getline(file, line);
				year = atoi(line.c_str());
				
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

void Client::ShowObj()
{
	std::cout << "  Id: " << id << "\n  Imie: " << name << "\n  Nazwisko: " << name2 << "\n  Miasto: " << city << "\n  Data urodzin: " << day << "." << month << "." << year << "\n";
}

void Client::SaveTable(std::ifstream &file) {
	
	
	int counter = 0;
	
	std::string line;
	

	if (file.good() == false)
	{
		std::cout << "Cannot open the file xxx.\n";
		exit(0);
	}

	while (getline(file, line))
	{

		std::cout << line;
			
			//if(counter==0)
			//	id = atoi(line.c_str());
	
			if (counter == 1)
			name = line;

			if (counter == 2)
			name2 = line;

			if (counter == 3)
			city = line;

			//if (counter == 4)
			//day = atoi(line.c_str());

			//if (counter == 5)
			//month = atof(line.c_str());

		//	if (counter == 6)
		//	year = atoi(line.c_str());
			
			if(counter == 7)
			break;

			counter++;
		}

}


/*
void Client::ChangeDate() 
{
	switch
	{
	case 1:
	case 2:
	case 3:
	case 4:
	}

}*/


/*WROC DO TEGO W WOLNEJ CHWILI !!!!!!!!!!!!!!!!!!!!!!!!!!!!
Date::Date(int day, int month, int year):day(day),month(month),year(year)
{
	char buff[100];
	sprintf(buff, "%d.%d.%d", day, month, year);
	std::string datestring(buff);
}
std::string Date::GetName()
{
	return datestring;
}
*/