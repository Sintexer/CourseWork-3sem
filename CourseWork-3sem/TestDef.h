#pragma once
#include "Test.h"

class TestDef :						//Тест с описанием черт характера пользователя
	public Test
{
protected:
	list<string> person_def{};		//В этом списке хранятся строки с описанием пользователя
	list<Q_Cost> questions{};		//Этот список содержит вопросы с ценой ответа. Ответ - номер варианта из списка ответов
	string def_path{};				//Путь к файлу с описаниями
public:
	TestDef() : Test() {};
	~TestDef() = default;

	void putPersonDef();			//Выводит описание пользователя на экран
	string getDefPath();			//Возвращает путь к файлу с описаниями

	virtual void start() = 0;		//Начало теста
	virtual void check() = 0;		//Проверка и вывод результата
};

