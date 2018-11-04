// Wypozyczalnia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "BaseClass.h"
#include "Client.h"
#include "Product.h"
#include "Menu.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

//Ustawia rozmiar konsoli
bool SetWindowSize(size_t width, size_t height)
{
	HANDLE output_handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	if (output_handle == INVALID_HANDLE_VALUE)
		return false;

	COORD coord = {};
	coord.X = static_cast<SHORT>(width);
	coord.Y = static_cast<SHORT>(height);
	if (::SetConsoleScreenBufferSize(output_handle, coord) == FALSE)
		return false;

	SMALL_RECT rect = {};
	rect.Bottom = coord.X - 1;
	rect.Right = coord.Y - 1;
	return (::SetConsoleWindowInfo(output_handle, TRUE, &rect) != FALSE);
}    
void Show_all(std::string nameoffile) {

	std::fstream file(nameoffile);
	int count = 0;
	if (file.is_open()) {
		std::string line;

		while (!file.eof())
		{
			getline(file, line);
			std::cout << line << "\n";
		}
		file.close();
	}
}

/////main/////////
int main()
{
	
	SetWindowSize(250, 50); //ustawienie rozmiaru konsoli w celu wyswietlenia napisow w odpowiedni sposob 

	///////////////////Obsluga Programu////////////////////////////////////////////////////////////
	int choice;
	
	do
	{
		system("cls");
		Menu m1;
		m1.ShowMenu();
		std::cin >> choice;
		
		switch (choice) {
		case 1: 
		{
			
			int decyzja;
			do {
				system("cls");
				Client* c1 = new Client();
				int counter = c1->CountLine("Client.txt");
				c1->AddClient(counter);
				c1->Upload_to_File("Client.txt");
				delete c1;
				system("cls");
				std::cout << "[1] Dodanie kolejnego uzytkownika\n[2] Powrot do menu startowego\n Wybor:";
				std::cin >> decyzja;
			} while (decyzja == 1);
			
		}
		break;
		case 2:
		{ 
		system("cls");
		Client* c1 = new Client();
		c1->Find("Client.txt");
		

		}



			break;
		case 3:
			break;
		case 4:
		{
			std::string client = "Client.txt";
			Show_all(client);
			system("pause");
		}
			break;
		case 5:
		{
			Product* p1 = new Product();
			int counter = p1->CountLine("Product.txt");
			p1->Add(counter);
			p1->Upload_to_File("Product.txt");
			delete p1;
		}
			break;
		case 6:
			break;
		case 7:
		{
			std::string product = "Product.txt";
			Show_all(product);
			system("pause");
		}
			break;
		case 8:
		{
			system("cls");
			Product* c1 = new Product();
			c1->Find("Product.txt");
		}
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			std::cout << "Koniec dzialania programu";
			break;
		default:
			std::cout << "Podaj prawidlowy zakres [1-11]: ";
			std::cin >> choice;
		}

	} while (choice != 11);
	
	return 0;
}


