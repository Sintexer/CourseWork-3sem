#pragma once
#include "Test.h"

class TeachingTest : //Обучающий тест, кроме вопросов содержит теорию
	public Test
{
protected:
	std::list<string> theory;
	//Список строк с теорией
	std::vector<size_t> user_answers;
	//Вектор ответов пользователя
	std::list<Q_OneAns> questions;
	//Список вопросов С одним ответом
	//Ответ - это номер ответа из списка
	std::string path{ "TeachingTests.txt" };
	//Путь к файлу с обучающими тестами
	std::string theory_path{};
	//Путь к файлу с теорией по тесту
public:
	TeachingTest() : Test() {};
	~TeachingTest() = default;

	void MakeTable();
	//Выводит таблицу с ответами пользователя

	virtual void start();
	//Начало теста
	bool startTheory();
	//Начало теории по тесту
	virtual void check();
	//Сверяем ответы пользователя с правильными ответами и выводим результат
	virtual void result();
	//Выводит результат пользователя

	void readTheory();
	//Метод считывает блок теории из файла с теорией
	bool getAnswers();
	//Метод получает ответы пользователя из файла с ответами, путь файла с ответами хранится в файле с тестом
	bool putAnswers();
	//Метод заносит ответы пользователя в файл
	friend std::istream& operator>> (std::istream& in, TeachingTest& obj);

	string getTheoryPath();
	//Возвращает путь к файлу с теорией
	string getPath();
	//Возвращает путь к файлу с обучающими тестами
};

