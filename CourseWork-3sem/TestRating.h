#pragma once
#include "Test.h"

class TestRating :						//Тест на оценивание знаний 
	public Test
{
protected:
	std::list<Q_OneAns> questions;		//Список вопросов с одним правильным ответом
public:

	TestRating() : Test() {};
	~TestRating() = default;

	virtual void start() = 0;			//Начало теста
	virtual void check() = 0;			//Проверка и вывод результата
};

