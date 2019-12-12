#include "MathTest.h"
#include "OutputTable.h"

void MathTest::MakeTable() { //������� ������ ������������ �� ���� � ���� �������
	OutputTable a("��� �����|���������"); //������� ������ ������ OutputTable
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc+1)+"|"+std::to_string(user_answers[vc])+")|"; //������ � ������ ������� ����� ������� � ����� ������������
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "��"; //������� � ��������� ������� ��, ���� ������������ ������� ��������� �� ������
			else
				temp += "���"; //������� � ��������� ������� ���, ���� ������������ ����������� ������� �� ������
			a.add_str(temp); //��������� ������ � ������ �������
		}
	cout << a << endl; //������� ������� �� �����
}

void MathTest::start(){ //�������� ����
	user_answers.clear(); //������� ������ ������� ������������
	getAnswers(); //�������� ������ ������������ �� �����
	if (user_answers.size()){ //���� ������������ �������� ����
		if (user_answers.size() == questions.size()) { //���� ���� ������� �� �����
			cout << "�� ��� ��������� ���� ����\n"
				<< "������� ������ ��� �����?\n"

				<< "\n1: ������ ���� ������\n"
				<< "2: ���������� ����������\n"
				<< "3: ������� ���������� ������\n"

				<< "\n0: �����\n" << endl;
			size_t answer{}; //���� ������������
			inputSafe(cin, answer, 0, 3); //���������� ���� ����� � ��������� �� 0 �� 3
			switch (answer){
			case 1:
				user_answers.clear(); //������� ������� ������� ������������
				system("cls");
				break;
			case 2:
				system("cls");
				MakeTable(); //����� ������� ������������ �� ���� � ���� ������� �� �����
				result(); //����� �������� ���������� �������
				cout << endl;
				return; //����� � ����
			case 3:
				system("cls");
				clearAns(); //������� ����� � ����������� �������� ������������
				return; //����� � ����
			case 0:
				return; //����� � ����
			default:
				break;
			}
		}
		else //���� ���� ������� �� �� �����
		{
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
				return; //����� � ����
			case 3:
				system("cls");
				clearAns(); //������� ����� � ����������� �������� �������������
				return; //����� � ����
			case 0:
				return; //����� � ����
			default:
				break;
			}
		}
	}

	cout << name << "\n" << endl; //����� ����� �����
	cout << test_def << "\n" << endl; //����� �������� �����
	system("pause");
	system("cls");
	size_t answer{}, counter{user_answers.size()+1}; // answer - ����� ������������, counter - ����� �������� �������

	list<Q_OneAns>::iterator it = questions.begin();
	size_t st{ user_answers.size() };
	while (st--) //������� � �������, �� ������� ������������ ������� ���� � ������� ���
		++it;
	
	while(it!=questions.end()){
		system("cls");
		cout << "������ " << counter << " �� " << questions.size() << endl; //����� ������ �������� �������
		static_cast<Q_OneAns>(*it).ask(); //����� ������� � ��������� ������ �� ����
		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1 
			<< ": �������� ����\n" 
			<< "0: �����\n"
			<< "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1); //���������� ���� ����� � ���������
		if (answer == 0) { //���� ������������ ������ ����� �����
			if (it == questions.begin()) //���� ��� ������ ������
				return; //����� � ����
			if (user_answers.size()) //���� ���� ������ ������������ � ������� �������
				user_answers.pop_back(); //�������� ���������� ������ �� �������
			--it; //������� � ����������� �������
			--counter; //��������� ������ �������� �������
			continue;
		}
		if (answer == dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1) { //���� ������������ ������ "�������� ����"
			system("cls");
			if (user_answers.size()) { //���� ������������ ������� ���� �� �� 1 ������
				cout << "������� ��������� ��� ���������?\n"
					<< "1: ��\n"
					<< "2: ���\n" << endl
					<< "0: �����" << endl;
				inputSafe(cin, answer, 0, 2); //���������� ���� ����� � ��������� �� 0 �� 2
				switch (answer){
				case 1:
					putAnswers(); //������ ������� ������������ � ����
					return; //����� � ����
				case 2:
					return; //����� � ����
				case 0:
					continue; //����������� ����� � ����� �� �������
					break;
				}
			}
			return; //����� � ����
		}

		user_answers.push_back(answer); //�������� ������ ������������ � ������
		++counter; //��������� ������ �������� �������
		++it; //������� � ���������� �������
	}
	system("cls");
	check(); //�������� ����� �� ���������� �������
}
void MathTest::check(){ //�������� ����� �� ���������� �������
	MakeTable(); //������� ������� � �������� ������������ �� �����
	result(); //������� ������� ���������� �������
	system("pause");
	system("cls");
	cout << "������� ��������� ��� ���������?" << endl;
	cout << "1: ��\n"
		<< "2: ���\n" << endl;
	size_t answer{}; //���� ������������
	inputSafe(cin, answer, 1, 2); //���������� ���� � ��������� �� 1 �� 2
	if(answer==1)
		putAnswers(); //���������� ������ ������������ � ����
}

void MathTest::result(){ //������� ������� ���������� ������� �� �����
	double correct{}; //���������� ���������� �������
	size_t vc{}; //����� �������
	list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc]) //���� ����� ������������ ������ � ���������� �������
				++correct; //��������� ���������� ���������� ������� �� ������
		}
	cout << "��� ������� ���������� ������� ����������: " << (int)((correct / questions.size()) * 100) << "%" << endl;
}

std::istream& operator>> (std::istream& in, MathTest& obj){ //���� ����� �� ������
	if (in.eof()) //���� ����� ����
		return in; //����� ������ �������
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.name); //���� ����� �����
	getline(in, obj.test_def); //���� �������� �����
	size_t size{}; //����� ��������
	in >> size; //���� ����� ��������
	obj.questions.clear(); //������� ������ ��������
	while (size) {
		Q_OneAns temp{};
		in >> temp; //���� �������
		obj.questions.push_back(temp); //�������� ������� � ������ ��������
		--size;
	}
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.answers_path); //���� ���� � ������� ������������
	return in;
}


void MathTest::getAnswers(){ //�������� ������ ������������ �� �����
	File txt(answers_path); //������������� ������� �����
	txt.open_in(); //��������� ������� ����� ��������� �������
	size_t size{};
	txt.read(size);
	while (size) {
		size_t temp{};
		txt.read(temp);
		user_answers.push_back(temp); //������� ����� ������������ � ������ ��������
		--size;
	}
}

void MathTest::putAnswers(){ //������� ������ ������������ � ����
	File txt(answers_path); //������������� ������� �����
	txt.open_out(); //�������� ��������� ������ ������� �����
	txt.write(user_answers.size()); //���������� ���������� ������� ������������ � ����
	int sz = user_answers.size();
	std::vector<size_t>::iterator it;
	it = user_answers.begin();
	while (sz--) {
		txt.write(*it); //���������������� ������ ������� ������������ � ����
		++it;
	}
}

string MathTest::getPath(){
	return path; //���������� ���� �����
}
