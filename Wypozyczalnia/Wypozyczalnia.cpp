// Wypozyczalnia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "BaseClass.h"
#include "Client.h"
#include "Product.h"
#include "Menu.h"
#include <windows.h>
#include <iostream>

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


/////main/////////
int main()
{
	
	SetWindowSize(250, 50); //ustawienie rozmiaru konsoli w celu wyswietlenia napisow w odpowiedni sposob 

	///////////////////Obsluga Programu////////////////////////////////////////////////////////////
	int choice,imie;                                        
	Menu m1;
	m1.ShowMenu();                         
	
	do
	{
		std::cin >> choice;
		switch (choice) {
		case 1: 
		{
			Product p1;
			p1.Add("Product.txt");
			
		}
		break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
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


