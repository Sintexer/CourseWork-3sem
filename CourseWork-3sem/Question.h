#pragma once
#include "File.h"

	class Question //Родительский класс вопроса без специализации
	{
	protected:
		string question_def{}; //Здесь хранится условие вопроса
	public:
		Question() = default;
		Question(string question) : question_def(question) {};
		Question(const Question& qst) : question_def(qst.question_def) {};
		~Question() = default;

		virtual void ask() = 0; //Метод выводит вопрос и варианты ответа на него
	};

	class Q_OneAns : //Вопрос с одним ответом
		public Question
	{
	protected:
		vector<string> answers{}; //Вектор вариантов ответа на вопрос
		double correct_ans{}; //Правильный ответ
	public:
		Q_OneAns() = default;
		Q_OneAns(string qst) : Question(qst) {};
		Q_OneAns(const Q_OneAns& qoa) : Question(qoa.question_def), correct_ans(qoa.correct_ans), answers(qoa.answers) {};
		~Q_OneAns() = default;

		virtual void ask() override; //Метод выводит вопрос и варианты ответа на него

		double getCorrectAns(); //Возвращает правильный ответ на вопрос
		size_t getAnswersSize(); //Возвращает количество ответов на вопрос

		friend std::istream& operator>> (std::istream& in, Q_OneAns& obj); //Оператор ввода вопроса из потока ввода
	};

	class Q_Cost : //Вопрос, где у каждого варианта ответа есть цена
	public Question
	{
	protected:
		vector<string> answers{"Очень часто", "Часто", "Иногда", "Редко", "Никогда"}; //Вектор, который содержит варианты ответа на вопрос
		vector<int> costs{5,4,3,2,1}; //Вектор содержит кол-во баллов, которые дает каждый ответ
	public:
		Q_Cost() = default;
		Q_Cost(string qst) : Question(qst) {};
		Q_Cost(const Q_Cost& qoa) : Question(qoa.question_def), answers(qoa.answers), costs(qoa.costs) {};
		~Q_Cost() = default;

		virtual void ask() override; //Метод выводит вопрос и варианты ответа на него
		
		int getCost(int a);//Возвращает цену из вектора costs по переданному индексу
		size_t getAnswersSize(); //Возвращает количество ответов на вопрос
		
		friend std::istream& operator>> (std::istream& in, Q_Cost& obj); //Оператор ввода вопроса из потока ввода
	};
