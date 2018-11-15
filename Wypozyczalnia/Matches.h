#pragma once
#include "Client.h"
#include "Product.h"

class Matches
{
private:
	int matchesId;
	int productId;
	int clientid;
public:
	Matches();
	Matches(std::string nameoffile, int productIdd, int clientIdd);
	void Upload_to_File(std::string nameoffile);
	bool Find(std::string nameoffile);
	int GetmatchesId();
	int GetclientId();
	int GetproductId();
	~Matches();
};

