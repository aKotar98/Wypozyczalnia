#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <Windows.h>


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::ShowMenu() {
	char z;

	FILE *file;
	file = fopen("Menu.txt", "r");
	if (file == NULL) printf("Blad otwarcia pliku\n");
	else
	{
		while (true)
		{
			if (feof(file)) break; /*jeœli koniec pliku koniec dzia³ania*/
			fscanf(file, "%c", &z);
			printf(" %c", z);
			Sleep(1);
		}
		std::cout << "\n";
	}
}
