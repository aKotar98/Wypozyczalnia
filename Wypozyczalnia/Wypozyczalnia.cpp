// Wypozyczalnia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Menu.h"
#include <windows.h>

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
	int choice;
	SetWindowSize(250, 50);
	Menu m1;
	m1.ShowMenu();
	std::cin >> choice;
	while (choice != 11)
	{
		
		switch (choice) {
		case 1:
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
			//m1.ShowMenu();
			std::cout << "Podaj prawidlowy zakres [1-11]: ";
			std::cin >> choice;
		}

	}
	return 0;
}


