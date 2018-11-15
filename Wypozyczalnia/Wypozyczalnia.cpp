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
bool reset(std::fstream & file) //resetuj konfiguracje sciezek
{
	if (file)
		file.close();

	file.open("Client.txt", std::ios::out | std::ios::trunc);
	file.clear();
	if (!file) return false;

	//file << DEFAULT_PATH;
	file.flush();

	return true;
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
			int decyzja;
			
			do {
			system("cls");
			Client* c1 = new Client();
			if ((c1->Find("Client.txt")) == true)
			{
				std::cout << "\nUzytkownik w bazie: ";
				c1->ShowObj();
			}
			else
				std::cout << "\nBrak uzytkownika w bazie";
			system("pause");
			std::cout << "[1] Sprawdz kolejnego uzytkownika\n[2] Powrot do menu startowego\n Wybor:";
			std::cin >> decyzja;
		} while (decyzja == 1);
		
		}
		break;
			

		case 3:
		{	
			int decyzja;
			do {
			bool check = false;
			int helper;
			system("cls");
			Client* c1 = new Client();
			if (c1->Find("Client.txt"))
			{
				check = true;
				helper = c1->GetId();
			}
			int count = c1->CountLine("Client.txt");

			delete c1;

			if (check == true) {

				std::fstream file("Client.txt");
				std::fstream *pointer = &file;

				Client **base2 = new Client*[count / 7];

				for (int i = 0; i < count / 7; i++) {
					int pom1, pom2, pom3, pom4;
					std::string s1, s2, s3;
					file >> pom1;
					file >> s1;
					file >> s2;
					file >> s3;
					file >> pom2;
					file >> pom3;
					file >> pom4;
					base2[i] = new Client(pom1, s1, s2, s3, pom2, pom3, pom4);
				}

				reset(*pointer);
				file.close();

				for (int i = 0; i < helper - 1; i++)
				{
					base2[i]->Upload_to_File("Client.txt");
				}
				for (int i = helper; i < count / 7; i++)
				{
					base2[i]->autoid();
					base2[i]->Upload_to_File("Client.txt");
				}
				system("pause");
				delete[] base2;
			}
			system("cls");
			std::cout << "[1] Usuniecie kolejnego uzytkownika \n[2] Powrot do menu startowego\n Wybor:";
			std::cin >> decyzja;
		} while (decyzja == 1);
		}


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
			int decyzja;
			do {
				Product* p1 = new Product();
				int counter = p1->CountLine("Product.txt");
				p1->Add(counter);
				p1->Upload_to_File("Product.txt");
				delete p1;
				std::cout << "[1] Dodanie kolejnego produktu\n[2] Powrot do menu startowego\n Wybor:";
				std::cin >> decyzja;
			} while (decyzja == 1);
		}
			break;
		case 6:
		{
			int decyzja;
			do {
				bool check = false;
				int helper;
				system("cls");
				Product* p1 = new Product();
				if (p1->Find("Product.txt"))
				{
					check = true;
					helper = p1->GetId();
				}
				int count = p1->CountLine("Product.txt");

				delete p1;

				if (check == true) {

					std::fstream file("Product.txt");
					std::fstream *pointer = &file;

					Product **base2 = new Product*[count / 7];

					for (int i = 0; i < count / 7; i++) {
						
						std::string s1, s2, s3,s4;
						float f1;
						bool b1;
						int pom2, pom1;
						file >> pom1;
						file >> s1;
						file >> s2;
						file >> s3;
						file >> f1;
						file >> s4;
						if (s4 == "Dostepny")
							b1 = true;
						else b1 = false;
						file >> pom2;
						base2[i] = new Product(pom1, s1, s2, s3, f1,b1, pom2);
					}

					reset(*pointer);
					file.close();

					for (int i = 0; i < helper - 1; i++)
					{
						base2[i]->Upload_to_File("Product.txt");
					}
					for (int i = helper; i < count / 7; i++)
					{
						base2[i]->autoid();
						base2[i]->Upload_to_File("Product.txt");
					}
					system("pause");
					delete[] base2;
				}
				system("cls");
				std::cout << "[1] Usuniecie kolejnego produktu \n[2] Powrot do menu startowego\n Wybor:";
				std::cin >> decyzja;
			} while (decyzja == 1);
		}
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
	
			int decyzja;
			do {
				system("cls");
				Product* p1 = new Product();
				if ((p1->Find("Product.txt")) == true)
				{
					std::cout << "\nUzytkownik w bazie:";
					p1->ShowObj();
				}
				else
					std::cout << "\nBrak uzytkownika w bazie\n";
				system("pause");
				std::cout << "[1] Sprawdz kolejny produkt\n[2] Powrot do menu startowego\n Wybor:";
				std::cin >> decyzja;
			} while (decyzja == 1);
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


