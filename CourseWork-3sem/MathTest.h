#pragma once
#include "TestRating.h"
#include "File.h"

class MathTest : //Тест по математике
	public TestRating //Тест на оценивание знаний 
	
{

protected:
	std::vector<size_t> user_answers;
	//Вектор хранит ответы пользователя
	//Ответ - это номер из списка ответов
	std::string path{"MathTests.txt"};
	//Путь к файлу с математическими тестами
public:

	MathTest() : TestRating() {};
	~MathTest() = default;

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
	friend std::istream& operator>> (std::istream& in, MathTest& obj);
	//Оператор ввода теста из потока
	
	string getPath();
	//Метод возвращает путь файла с тестами
};