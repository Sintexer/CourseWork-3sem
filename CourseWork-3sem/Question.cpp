#include "Question.h"
#include "Exc.h"

void Question::setQuestionDef(string qstdef)
{
	question_def = qstdef;
}

string Question::getQuestionDef()
{
	return question_def;
}

void Q_OneAns::setCorrectAns(double ans)
{
	correct_ans= ans;
}

double Q_OneAns::getCorrectAns()
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


int Q_Cost::getCost(int a)
{
	try {
		if (a<0 || a>costs.size() - 1)
			throw Exc("Индекс за границами массива");
		return costs[--a];
	}
	catch (Exc& err) {
		unpackExc(cerr, err);
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
}

std::vector<int> Q_Cost::getCosts()
{
	return costs;
}

size_t Q_Cost::getAnswersSize()
{
	return answers.size();
}


void Q_Cost::ask()
{
	cout << getQuestionDef() << endl << endl;

	int counter = 1;
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl;
	}
}

std::istream& operator>>(std::istream& in, Q_OneAns& obj)
{
	while (in.peek() == '\n' ||in.peek() == '\r')
		in.get();
	getline(in, obj.question_def);
	in >> obj.correct_ans;
	size_t size;
	string temp;
	in >> size;
	while (size) {
		while (in.peek() == '\n' || in.peek() == '\r')
			in.get();
		getline(in, temp);
		obj.answers.push_back(temp);
		--size;
	}
	return in;
}

std::istream& operator>>(std::istream& in, Q_Cost& obj)
{
	while (in.peek() == '\n' || in.peek() == '\r')
		in.get();
	getline(in, obj.question_def);
	size_t size;
	string temp;
	in >> size;
	while (in.peek() == '\n' || in.peek() == '\r')
		in.get();
	obj.answers.clear();
	while (size) {
		getline(in, temp);
		obj.answers.push_back(temp);
		--size;
	}
	int temp2;
	in >> size;
	obj.costs.clear();
	while (size) {
		in >> temp2;
		obj.costs.push_back(temp2);
		--size;
	}
	return in;
}
