#pragma once
#include "TestRating.h"

class PhysTest : //Тест по физике
	public TestRating //Тест на оценивание знаний
{
protected:
	std::vector<double> user_answers;  //Вектор хранит ответы пользователя. Ответ - число формата double
	std::string path{ "..\\Resources\\Phys\\PhysTests.txt" }; //Путь к файлу с тестами по физике
public:

	PhysTest() : TestRating() {};
	~PhysTest() = default;

	void MakeTable(); //Вывести таблицу с ответами пользователя

	virtual void start(); //Начало теста
	virtual void check(); //Выводит и сохраняет результат
	virtual void result(); //Выводит результат пользователя

	void getAnswers(); //Метод получает ответы пользователя из файла с ответами, путь файла с ответами хранится в файле с тестом
	void putAnswers(); //Метод заносит ответы пользователя в файл
	friend std::istream& operator>> (std::istream& in, PhysTest& obj); //Оператор ввода теста из потока
	
	string getPath(); //Метод возвращает путь файла с тестами
};

template<typename T>//Функция переводит любой тип в строку и возвращает ее
string toStr(T val) {
	std::ostringstream ost;
	ost << val;
	return ost.str();
}