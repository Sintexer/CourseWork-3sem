#pragma once
#include "MostCommonHeaders.h"
#include "File.h"
#include <vector>

class Question
{//questin_def
protected:
	wstring question_def{};
	// ��� ������ �����, ������� ��������� �� �����

public:
	Question() = default;
	Question(wstring quest) : question_def(quest) {};
	Question(const Question& qst) : question_def(qst.question_def) {};
	~Question() = default;

	void setQuestionDef(wstring qstdef);
	wstring getQuestionDef();
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
	std::vector<wstring> answers{};
	//������, ������� �������� �������� ������ �� question_def
	
	size_t correct_ans{};
	//����� ������, ������� �������� ����������
public:
	Q_OneAns() = default;
	Q_OneAns(wstring qst) : Question(qst) {};
	Q_OneAns(const Q_OneAns& qoa) : Question(qoa.question_def), correct_ans(qoa.correct_ans), answers(qoa.answers) {};
	~Q_OneAns() = default;

	void setCorrectAns(size_t ans);
	size_t getCorrectAns();

	void addAnswer(wstring another_ans);
	std::vector<wstring> getAnswers();

	size_t getAnswersSize();

	void writeFile(TextFile& txt);
	void readFile(TextFile& txt);

	void ask();
};