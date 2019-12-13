#pragma once
#include "Test.h"

class TeachingTest :														//Обучающий тест, кроме вопросов содержит теорию
	public Test
{
protected:
	std::list<string> theory;												//Список строк с теорией
	std::vector<size_t> user_answers;										//Вектор ответов пользователя
	std::list<Q_OneAns> questions;											//Список вопросов с одним правильным ответом. Ответ - это номер ответа из списка
	std::string path{ "..\\Resources\\Teach\\TeachingTests.txt" };			//Путь к файлу с обучающими тестами
	std::string theory_path{};												//Путь к файлу с теорией по тесту
public:
	TeachingTest() : Test() {};
	~TeachingTest() = default;

	void MakeTable();														//Выводит таблицу с ответами пользователя

	virtual void start();													//Начало теста
	bool startTheory();														//Начало теории по тесту
	virtual void check();													//Проверяет ответы пользователя по правильным ответам и выводит результат
	virtual void result();													//Выводит результат пользователя
	
	void readTheory();														//Метод считывает блок теории из файла с теорией
	void getAnswers();														//Метод получает ответы пользователя из файла с ответами
	void putAnswers();														//Метод заносит ответы пользователя в файл
	
	friend std::istream& operator>> (std::istream& in, TeachingTest& obj);	//Оператор ввода теста из потока

	string getTheoryPath();													//Возвращает путь к файлу с теорией
	string getPath();														//Возвращает путь к файлу с обучающими тестами
};

