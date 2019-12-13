#pragma once
#include "Exc.h"
class MainMenu
{
public:
	void init();					//Главное меню, где выбирается вид тестов
	bool ratingTestMenu();			//Подменю тестов оценки знаний
	bool psychoTestMenu();			//Подменю психологических тестов
	bool teachingTestMenu();		//Инициализация обучающих тестов
};

