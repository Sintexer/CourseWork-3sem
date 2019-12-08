#pragma once
#include "Exc.h" // Собственный класс исключений, для пользовательского ввода

class MainMenu
{
private:
public:
	void init();
	//Главвное меню, где выбирается вид тестов
	bool ratingTestMenu();
	//Подменю тестов оценки знаний
	bool psychoTestMenu();
	//Подменю психологических тестов
	bool teachingTestMenu();
	//Инициализация обучающих тестов
};

