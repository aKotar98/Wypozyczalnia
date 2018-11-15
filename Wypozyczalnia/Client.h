#pragma once
#include "BaseClass.h"
#include <iostream>

class Client : public BaseClass
{
private:
	std::string city;
	int day, month, year;

public:
	Client();
	Client(int idd, std::string namee, std::string namee2, std::string cityy, int dayy, int monthh, int yearr);
	~Client();
	void ShowObj();
	void AddClient(int count);
	void Upload_to_File(std::string nameoffile);
	bool Find(std::string nameoffile);
	void SaveTable(std::fstream &file);
	void SetInTheFile();
};

