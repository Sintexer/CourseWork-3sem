#include "Question.h"

void Question::setQuestionDef(string qstdef)
{
	question_def = qstdef;
}

string Question::getQuestionDef()
{
	return question_def;
}

void Q_OneAns::setCorrectAns(size_t ans)
{
	correct_ans= ans;
}

size_t Q_OneAns::getCorrectAns()
{
	return correct_ans;
}

void Q_OneAns::addAnswer(string another_ans)
{
	answers.push_back(another_ans);
}

std::vector<string> Q_OneAns::getAnswers()
{
	return answers;
}

size_t Q_OneAns::getAnswersSize()
{
	return answers.size();
}

void Q_OneAns::ask()
{
	cout <<getQuestionDef() << endl << endl;

	int counter = 1;
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl;
	}
}
