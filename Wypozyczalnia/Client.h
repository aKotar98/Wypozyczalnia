#pragma once
#include "BaseClass.h"
#include <iostream>
/*WROC DO TEGO W WOLNEJ CHWILI
struct Date{

	int day, month, year;
	std::string datestring;
	
	Date(int day, int month, int year);
	std::string GetName();
	};
*/

class Client : public BaseClass
{
private:
	std::string city;
	int day, month, year;

public:
	Client();
	~Client();
	void Showobj();
	void AddClient(int count);
	void Upload_to_File(std::string nameoffile);
	void Find(std::string nameoffile);
};

