#pragma once
#include "Question.h"

class Test //Абстрактный класс теста, содержит общие поля имени, описания, и пути к ответам
{
protected:
	string name{};
	//Название теста
	string test_def{};
	//Описание теста
	string answers_path{};
	//Путь к ответам пользователя, которые были сохранены в файл
public:
	Test() = default;
	Test(std::string test_name) : name(test_name) {};
	~Test() = default;

	virtual void start() = 0;
	//Начало теста
	virtual void check() = 0;	
	//Проверка теста по правильным ответам, которые хранятся в вопросе, и вывод результата
	void clearAns();
	//Очищает файл с ответами пользователя

	bool operator>(Test& another_test);
	bool operator<(Test& another_test);
	bool operator==(Test& another_test);
	bool operator!=(Test& another_test);
	//Операторы сравнения, для занесения в контейнер

	friend std::ostream& operator<<(std::ostream& out, Test& test);
	//Оператор вывода имени и описания любого теста

	string getName();	
	//Метод возвращает имя теста
	string getDefinition();
	//Метод возвращает Описание теста
	string getAnswersPath();
	//Метод возвращает путь к ответам пользователя на тест
};

