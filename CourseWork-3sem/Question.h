#pragma once
#include "MostCommonHeaders.h"
#include <vector>

class Question
{//questin_def
protected:
	string question_def{};
	// —ам вопрос теста, который выводитс€ на экран

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

class Q_OneAns:
	public Question
{//questin_def, answers, correct_ans
protected:
	std::vector<string> answers{};
	//¬ектор, который содержит варианты ответа на question_def
	
	size_t correct_ans{};
	//номер ответа, который €вл€етс€ правильным
public:
	Q_OneAns() = default;
	Q_OneAns(string qst) : Question(qst) {};
	Q_OneAns(const Q_OneAns& qoa) : Question(qoa.question_def), correct_ans(qoa.correct_ans), answers(qoa.answers) {};
	~Q_OneAns() = default;

	void setCorrectAns(size_t ans);
	size_t getCorrectAns();

	void addAnswer(string another_ans);
	std::vector<string> getAnswers();

	size_t getAnswersSize();

	void ask();
};