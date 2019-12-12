#pragma once
#include "TestDef.h"

class PersTest : //Личностный тест
	public TestDef //Тест с описанием черт характера пользователя
{
protected:
	int sum{};
	//Сумма баллов по ответам пользователя
	//Эта сумма используется для выбора описания пользователя из файла с описаниями
	//Баллы по каждому ответу хранятся в вопросе
	std::vector<size_t> user_answers{};
	//Вектор ответов пользователя
	//Ответ - это номер из списка ответов
	std::string path{ "PersonalityTests.txt" };
	//Путь к личностным тестам

public:

	PersTest() : TestDef() {};
	~PersTest() = default;

	virtual void start();
	//Начало теста
	virtual void check();
	//Сверяем ответы пользователя с правильными ответами и выводим результат

	void getPersonDef();
	//Метод получает описание пользователя из файла с описаниями
	void putAnswers();
	//Метод заносит ответы пользователя в файл
	void getAnswers();
	//Метод получает ответы пользователя из файла
	friend std::istream& operator>> (std::istream& in, PersTest& obj);
	//Оператор ввода теста из потока

	string getPath();
	//Метод возвращает путь файла с личностными тестами
};

