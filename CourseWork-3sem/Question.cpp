#include "Question.h"
#include "Exc.h"

//
//Q_OneAns
//

double Q_OneAns::getCorrectAns(){ //���������� ���������� ����� �� ������
	return correct_ans;
}

size_t Q_OneAns::getAnswersSize(){ //���������� ����� ������� �� ������
	return answers.size();
}

void Q_OneAns::ask(){ //������� ������ � �������� ������� �� ����
	cout << question_def << endl << endl; //����� ������� 
	int counter{ 1 }; //����� ������
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl; //����� �������� ������
	}
}

std::istream& operator>>(std::istream& in, Q_OneAns& obj){ //����  ������� � ����� ������� �� ������
	while (in.peek() == '\n')//������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.question_def); //���� �������
	in >> obj.correct_ans; //���� ����������� ������
	if(in.peek()=='|')
		in.get();
	string temp; //��������� ��� �����
	while (in.peek() != '\n') {
		 //���� �������� ������
		getline(in, temp, '|');
		obj.answers.push_back(temp); //�������� �������� ������ � ������ ��������� ������
	} 
	return in;
}

//
//Q_Cost
//

size_t Q_Cost::getAnswersSize() { //���������� ����� ������� �� ������
	return answers.size();
}

void Q_Cost::ask() { //������� ������ � �������� ������� �� ����
	cout << question_def << endl << endl; //����� ������� 
	int counter{ 1 }; //����� ������
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl; //����� �������� ������
	}
}

int Q_Cost::getCost(int a) { //���������� ����� ������ �� ����� �� ������ a
	try {
		if (a<0 || a>(int(costs.size()) - 1)) //���� ����������� ������� �� ����������
			throw Exc("������ �� ��������� �������");
		return costs[--a]; //���������� ���� �� ������� a-1
	}
	catch (Exc& err) {
		unpackExc(cerr, err); //����� ����������
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
	return 0;
}

std::istream& operator>>(std::istream& in, Q_Cost& obj)
{
	while (in.peek() == '\n')//������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.question_def); //���� �������
	while (in.peek() == '\n')//������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	obj.answers.clear(); //������� ������� ��������� ������
	string temp; //��������� ��� �����
	while (in.peek() != '\n') {
		//���� �������� ������
		getline(in, temp, '|');
		obj.answers.push_back(temp); //�������� �������� ������ � ������ ��������� ������
	}
	int temp2; //��� ����� �����
	obj.costs.clear(); //������� ������� ������
	 do {
		in >> temp2; //���� �����
		obj.costs.push_back(temp2); //�������� ����� � ������
		in.get();
	}while (in.peek() != '\n');
	return in;
}

