#include "TeachingTest.h"
#include "OutputTable.h"

void TeachingTest::MakeTable() {//������� ������ ������������ �� ���� � ���� �������
	OutputTable a("����� �������|��� �����|���������");//������� ������ ������ OutputTable
	size_t vc{}; //������ � �������
	string temp{}; //������ ��� ���������� � �������
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc + 1) + "|" + std::to_string(user_answers[vc]) + ")|"; //������ � ������ ������� ����� ������� � ����� ������������
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "��"; //������� � ��������� ������� ��, ���� ������������ ������� ��������� �� ������
			else
				temp += "���"; //������� � ��������� ������� ���, ���� ������������ ����������� ������� �� ������
			a.add_str(temp); //��������� ������ � ������ �������
		}
	cout << a << endl; //������� ������� �� �����
}


bool TeachingTest::startTheory(){ //������� �� ����� ������������� ����� �����
	readTheory(); //������ ������ �� �����
	system("cls");
	cout << "������������� �����\n" << endl;
	system("pause");
	system("cls");
	typename std::list<string>::iterator it = theory.begin();

	size_t answer{};
	while (it != theory.end()) { //�������� �� ������ � �������
		system("cls");
		cout << *it << endl;	//����� ������
		cout << "\n1: ������\n"
			<< "2: ���������� ������\n\n" 
			<< "3: �������� ����\n"
			<< "0: �����" << endl;
		cout << "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, 3);
		if (answer == 0) { //���� ������������ ������ "�����"
			if (it == theory.begin()) //���� ��� ���� ������ ������
				return false; //����� � ����
			--it; 
			continue;
		}
		if (answer == 2) //���� ������������ ������ "���������� ������"
			break;
		if (answer == 3)
			return false; //����� � ����
		++it;
	}
	return true; //������� � ������������ ����� �����
}

void TeachingTest::check(){ //��������� � ��������� ���������� � ����
	result(); //����� ���������� �� �����
	system("pause");
	system("cls");
	cout << "������� ��������� ��� ���������?" << endl;
	cout << "1: ��\n"
		<< "2: ���\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if (answer == 1)
		putAnswers(); //���������� ������� � ����
}

void TeachingTest::result(){ //������� ��������� ����� �� �����
	MakeTable(); //������� ������ � ���� �������
	double correct{}; //����� ��������� ���������� ��������
	size_t vc{}; //������ � ������� �������
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc]) //���� ����� ����������
				++correct; //���������� ����� ��������� ���������� �������� �� 1
		}
	cout << "��� ������� ���������� ������� ����������: " << (int)((correct / questions.size()) * 100) << "%" << endl;
}

void TeachingTest::start(){ //������ �����
	user_answers.clear(); //������� ������� ������������
	getAnswers(); //������ ������� ������������ �� �����
	if (user_answers.size()) ////���� ������������ �������� ����
	{
		if (user_answers.size() == questions.size()) {//���� ���� ������� ���������
			cout << "�� ��� ��������� ���� ����\n"
				<< "������� ������ ��� �����?\n"

				<< "\n1: ������ ���� ������\n"
				<< "2: ���������� ����������\n"
				<< "3: ������� ���������� �����\n"

				<< "\n0: �����\n" << endl;
			size_t answer{}; //���� ������������
			inputSafe(cin, answer, 0, 3); //���������� ���� ����� � ��������� �� 0 �� 3
			switch (answer)
			{
			case 1:
				user_answers.clear(); //������� ������� ������� ������������
				system("cls");
				break;
			case 2:
				system("cls");
				result(); //����� ����������� ����� �� �����
				cout << endl;
				return;
			case 3:
				clearAns(); //������� ����� � ��������
				return;
			case 0:
				return; //����� � ����
			default:
				break;
			}
		}
		else { //���� ���� ��� ������� �� �� �����
			cout << "�� ��� ��������� ���� ����\n"
				<< "������� ���������� ���?\n"

				<< "\n1: ���������� ����\n"
				<< "2: ������ ������\n"
				<< "3: ������� ���������� ����������\n"

				<< "\n0: �����\n" << endl;
			size_t answer{}; //���� ������������
			inputSafe(cin, answer, 0, 3); //���������� ���� ����� � ��������� �� 0 �� 3
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				user_answers.clear(); //������� ������� ������� ������������
				system("cls");
				return;
			case 3:
				clearAns(); //������� ����� � ��������
				return; //����� � ����
			case 0:
				return; //����� � ����
			default:
				break;
			}
		}
	}
	cout << name << "\n" << endl;
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");

	if (!startTheory()) //������� ������ �� �����
		return; //����� � ����

	size_t answer{}, counter{ user_answers.size()+1 }; //answer - ���� ������������, counter - ����� �������
	typename std::list<Q_OneAns>::iterator it = questions.begin();
	size_t st = user_answers.size();
	while (st--)
		++it; //������� � �������, �� ������� ����������� ������������ � ���������� ���
	system("cls");
	cout << "������������ �����\n" << endl;
	system("pause");
	while (it != questions.end()) {
		system("cls");
		cout << "������ " << counter << " �� " << questions.size() << endl; //����� ������ �������� �������
		static_cast<Q_OneAns>(*it).ask(); //����� �������

		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1 
			<< ": �������� ����\n"
			<< "0: �����" << endl;

		cout << "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1);
		if (answer == 0) { //���� ������������ ������ "�����"
			if (it == questions.begin()) //���� ��� ��� ������ ������
				if (!startTheory()) //������ ������
					return; //���� ������������ ����� �� ������ - ����� � ����
				else {
					if (it == questions.begin()) { //���� ������������ ������� �� ������ � �����
						system("cls");
						cout << "������������ �����\n" << endl;
						system("pause");
					}
					continue;
				}
			if (user_answers.size()) 
				user_answers.pop_back();  //������� ���������� ����� ������������ �� �������
			--it; //������� � ����������� �������
			--counter; //��������� ������ �������
			continue;
		}
		if (answer == (dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1)) { //���� ������������ ������ "�������� ����"
			system("cls");
			if (user_answers.size()) { //���� ������������ ������� ���� �� �� ���� ������
				cout << "������� ��������� ��� ���������?\n"
					<< "1: ��\n"
					<< "2: ���\n" << endl
					<< "0: �����" << endl;
				inputSafe(cin, answer, 0, 2); 
				switch (answer)
				{
				case 1:
					putAnswers(); //��������� ������ ������������ � ����
					return; //����� � ����
				case 2:
					return; //����� � ����
				case 0:
					continue; //���������� ����
					break;
				}
			}
			return;
		}
		user_answers.push_back(answer); //������� ����� ������������ � ������
		++it; //������� � ���������� �������
		++counter; //��������� ������ �������
	}
	system("cls");
	check(); //�������� ������� ������������
}

string TeachingTest::getTheoryPath(){ //���������� ���� � ����� � �������
	return theory_path;
}

string TeachingTest::getPath(){//���������� ���� � ����� � �������
	return path;
}

void TeachingTest::readTheory(){ //������ ������ �� ����� � ������
	File txt(getTheoryPath()); //������������� ������� �����
	string temp{}; //������ ��� ������
	txt.open_in(); //������� ���� ��� ������
	theory.clear(); //�������� ������ � �������
	while (txt.in()) { //���� � ����� ���� ������
		txt.readLine(temp); //������ ������ ������
		theory.push_back(temp); //�������� ������ � ������ � �������
	}
}

void TeachingTest::putAnswers(){ //������� ������ ������������ � ����
	File txt(answers_path); //������������� ������� �����
	txt.open_out(); //�������� ��������� ������ ������� �����
	std::vector<size_t>::iterator it = user_answers.begin();
	while (it != user_answers.end()) { //�������� �� ������� ������� ������������
		txt.write(*it, '|'); //���������������� ������ ������� ������������ � ����
		++it;
	}
}

void TeachingTest::getAnswers()
{
	File txt(answers_path); //������������� ������� �����
	txt.open_in(); //��������� ������� ����� ��������� �������
	txt.getFin().peek();
	if (txt.getFin().eof()) //���� ���� ����
		return;
	size_t temp{}; //��������� ���������� ��� ������ �������
	while (txt.in()) { //���� �� ����� ����� ���-�� ���������
		txt.read(temp); //������ �����
		user_answers.push_back(temp); //������� ����� ������������ � ������ ��������
		txt.getFin().get(); //������� �������-�����������
	}
}

std::istream& operator>>(std::istream& in, TeachingTest& obj){ //������������� ������� ���������� ����� �� ������
	if (in.eof()) //���� ����� ����
		return in;
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.name); //������ ����� �����
	getline(in, obj.test_def); //������ �������� �����
	size_t size{}; //����� ��������
	in >> size;
	obj.questions.clear();
	while (size) {
		Q_OneAns temp{};
		in >> temp; //������ �������
		obj.questions.push_back(temp); //�������� ������� � ������ ��������
		--size;
	}
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.theory_path); //������ ���� � ����� � �������
	getline(in, obj.answers_path); //������ ���� � ����� � ��������
	return in; 
}
