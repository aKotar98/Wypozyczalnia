#pragma once
#include "Client.h"
#include "Product.h"

class Matches
{
private:
	int matchesId;
	int productId;
	int clientid;
	int day;
	int month;
	int year;
public:
	Matches();
	Matches(std::string nameoffile, int productIdd, int clientIdd, int dayy, int monthh,int yearr);
	void Upload_to_File(std::string nameoffile);
	bool Find(std::string nameoffile);
	int GetmatchesId();
	int Getmatchesday();
	int Getmatchesmonth();
	int Getmatchesyear();
	int GetclientId();
	int GetproductId();
	~Matches();
};

