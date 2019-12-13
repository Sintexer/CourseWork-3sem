#include "MainMenu.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	MainMenu mm;
	mm.init();
}