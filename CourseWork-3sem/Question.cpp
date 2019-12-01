#include "Question.h"

void Question::setQuestionDef(wstring qstdef)
{
	question_def = qstdef;
}

wstring Question::getQuestionDef()
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

void Q_OneAns::addAnswer(wstring another_ans)
{
	answers.push_back(another_ans);
}

std::vector<wstring> Q_OneAns::getAnswers()
{
	return answers;
}

size_t Q_OneAns::getAnswersSize()
{
	return answers.size();
}

void Q_OneAns::writeFile(TextFile& txt)
{
	txt.fout << question_def << endl;
	txt.fout << correct_ans << endl;
	txt.fout << answers.size() << endl;
	for (std::vector<wstring>::iterator it = answers.begin(); it != answers.end(); ++it) {
		txt.fout << *it << endl;
	}
}

void Q_OneAns::readFile(TextFile& txt) {
	txt.fin >> question_def;
	txt.fin >> correct_ans;
	size_t size;
	wstring temp;
	txt.fin >> size;
	while (size) {
		txt.fin >> temp;
		answers.push_back(temp);
		--size;
	}
}


void Q_OneAns::ask()
{
	wcout <<getQuestionDef() << endl << endl;

	int counter = 1;
	for (typename std::vector<wstring>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		wcout << counter << ": " << *it << endl;
	}
}
