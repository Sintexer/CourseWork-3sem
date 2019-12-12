#pragma once
#include "TestRating.h"

class PhysTest : //Тест по физике
	public TestRating //Тест на оценивание знаний
{
protected:
	std::vector<double> user_answers;
	//Вектор хранит ответы пользователя
	//Ответ - это число формата double
	std::string path{ "PhysTests.txt" };
	//Путь к файлу с тестами по физике
public:

	PhysTest() : TestRating() {};
	~PhysTest() = default;

	void MakeTable();
	//Вывести таблицу с ответами пользователя

	virtual void start();
	//Начало теста
	virtual void check();
	//Сверяем ответы пользователя с правильными ответами и выводим результат
	virtual void result();
	//Выводит результат пользователя

	bool getAnswers();
	//Метод получает ответы пользователя из файла с ответами, путь файла с ответами хранится в файле с тестом
	bool putAnswers();
	//Метод заносит ответы пользователя в файл
	friend std::istream& operator>> (std::istream& in, PhysTest& obj);
	//Оператор ввода теста из потока
	
	string getPath();
	//Метод возвращает путь файла с тестами
};

template<typename T>//Функция переводит любой тип в строку и возвращает ее
string toStr(T val) {
	std::ostringstream ost;
	ost << val;
	return ost.str();
}