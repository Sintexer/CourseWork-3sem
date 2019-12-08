#pragma once
#include "MostCommonHeaders.h"
#include "File.h"
#include <vector>

	class Question
	{//questin_def
	protected:
		string question_def{};
		// 

	public:
		Question() = default;
		Question(string quest) : question_def(quest) {};
		Question(const Question& qst) : question_def(qst.question_def) {};
		~Question() = default;

		void setQuestionDef(string qstdef);
		string getQuestionDef();
	};

	//
	//
	//
	//
	//

	class Q_OneAns :
		public Question
	{//questin_def, answers, correct_ans
	protected:
		std::vector<string> answers{};
		

		double correct_ans{};
		
	public:
		Q_OneAns() = default;
		Q_OneAns(string qst) : Question(qst) {};
		Q_OneAns(const Q_OneAns& qoa) : Question(qoa.question_def), correct_ans(qoa.correct_ans), answers(qoa.answers) {};
		~Q_OneAns() = default;

		void setCorrectAns(double ans);
		double getCorrectAns();

		void addAnswer(string another_ans);
		std::vector<string> getAnswers();
		size_t getAnswersSize();

		friend std::istream& operator>> (std::istream& in, Q_OneAns& obj);

		void ask();
	};

	class Q_Cost :
	public Question
	{//questin_def, answers, correct_ans
	protected:
		std::vector<string> answers{"Очень часто", "Часто", "Иногда", "Редко", "Никогда"};
		//Вектор, который содержит варианты ответа на question_def
		std::vector<int> costs{5,4,3,2,1};
		//Вектор содержит кол-во баллов, которые дает каждый ответ
	public:
		Q_Cost() = default;
		Q_Cost(string qst) : Question(qst) {};
		Q_Cost(const Q_Cost& qoa) : Question(qoa.question_def), answers(qoa.answers), costs(qoa.costs) {};
		~Q_Cost() = default;


		void addAnswer(string another_ans);
		std::vector<string> getAnswers();

		void addCost(int cost);
		int getCost(int a);
		std::vector<int> getCosts();
		size_t getAnswersSize();

		friend std::istream& operator>> (std::istream& in, Q_Cost& obj);

		void ask();
	};
