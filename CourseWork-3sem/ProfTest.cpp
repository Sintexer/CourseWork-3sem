#include "ProfTest.h"

int findMaxInVect(std::vector<int>& vc) { //����� ������������� ����� � �������
	int max{}; //���������� ��������
	int index{}; //������ ������������� ��������
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] > max) { //���� ������� ������� ������� ������ �������������
			index = counter; //������ ������������ ����� ������� ��������
			max = vc[counter]; //�������� ����� �������� ��������
		}
	}
	return index; //���������� ������ ���������
}

int finMaxInVectLessThan(std::vector<int>& vc, int prev_max) { //����� ������������� ����� � �������, ������� ������ �������� �� ����������� �������
	int prev{}; //���������� ��������
	int index{}; //������ ������������� ��������
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] >= prev && counter != prev_max && vc[counter] <= vc[prev_max]) { //���� ������� ������� ������� ������ ������������� � ������ �������� �� ����������� �������
			prev = vc[counter]; //������ ������������ ����� ������� ��������
			index = counter; //�������� ����� �������� ��������
		}
	}
	return index; //���������� ������ ���������
}

void ProfTest::start(){ //������ �����
	sum.clear(); //������� ������� ���� ������ �� ��������
	person_def.clear(); //������� �������� �������� ������������
	getAnswers();  //��������� ������� ������������ �� ����
	if (sum.size()){ //���� ������������ ��� �������� ����
		if (user_answers.size() == questions.size()) { //���� ������������ �������� ���� �� �����
			cout << "�� ��� ��������� ���� ����\n"
				<< "������� ������ ��� �����?\n"

				<< "\n1: ������ ���� ������\n"
				<< "2: ���������� ����������\n"
				<< "3: ������� ���������� ����������\n"

				<< "\n0: �����\n" << endl;
			size_t answer{}; //���� ������������
			inputSafe(cin, answer, 0, 3); //���������� ���� � ��������� �� 0 �� 3
			switch (answer){
			case 1:
				user_answers.clear(); //������� ������� ������� ������������
				sum.clear(); //������� ������� ���� ������
				sum.resize(sz); //���������� ������� ������� ����
				system("cls");
				break;
			case 2:
				getPersonDef(); //��������� �������� ������������ �� ������ � ������������ � ���������� �������
				system("cls");
				result(); //����� ����������
				cout << endl;
				return;
			case 3:
				system("cls");
				clearAns(); //������� ���� � �������� ������������
				return; //����� � ����
			case 0:
				return; //����� � ����
			default:
				break;
			}
		}
		else { //���� ������������ ������� ���� � ������� ���
			cout << "�� ��� ��������� ���� ����\n"
				<< "������� ���������� ���?\n"

				<< "\n1: ���������� ����\n"
				<< "2: ������ ������\n"
				<< "3: ������� ���������� ����������\n"

				<< "\n0: �����\n" << endl;
			size_t answer{}; //���� ������������
			inputSafe(cin, answer, 0, 3); //���������� ���� � ��������� �� 0 �� 3
			switch (answer){
			case 1:
				system("cls"); //���� ������������ � �������, �� ������� ������������ ������� ����
				break;
			case 2:
				user_answers.clear(); //������� ���������� ������� ������������
				sum.clear(); //������� ������� ���� ������
				sum.resize(sz); //���������� ������� ������� ����
				system("cls");
				break;
			case 3:
				clearAns(); //������� ����� � �������� ������������
				return; //����� � ����
			case 0:
				return; //����� � ����
			default: 
				break;
			}
		}
	}
	else
		sum.resize(sz); //���������� ������� ������� ����
	cout << name << "\n" << endl; //����� ����� �����
	cout << test_def << "\n" << endl; //����� �������� �����
	system("pause");
	system("cls");
	size_t answer{}, counter{ user_answers.size() + 1 }; //answer ��� ����� ������������, counter - ����� �������� �������
	list<Q_Cost>::iterator it = questions.begin();
	size_t st{};
	while (st++<user_answers.size())
		++it; //������� � �������, �� ������� ������������ ����������� � ������� ���
	while (it != questions.end()) {
		system("cls");
		cout << "������ " << counter << " �� " << questions.size() << endl; //����� ������ �������� �������
		static_cast<Q_Cost>(*it).ask(); //����� ������� � ��������� ������ �� ����
		cout << "\n" << dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1
			<< ": �������� ����\n" << endl;
		cout << "0: �����" << endl;
		cout << "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1); //���������� ���� � ���������
		if (answer == 0) { //���� ������������ ������ "�����"
			if (it == questions.begin()) //���� ��� ��� ������ ������
				return; //����� � ����
			--it; //������� � ����������� ������� 
			--counter; //��������� ������ �������
			sum[relative[user_answers.size()-1]-1] -= dynamic_cast<Q_Cost&>(*it).getCost(user_answers.back()); //��������� �� ��������������� ����� ����� �� ���������� ������
			user_answers.pop_back(); //�������� ����������� ������ ������������ �� �������
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) { //���� ������������ ������ "�������� ����"
			system("cls");
			if (user_answers.size()) { //���� ������������ ������� ���� �� �� ���� ������
				cout << "������� ��������� ��� ���������?\n"
					<< "1: ��\n"
					<< "2: ���\n" << endl
					<< "0: �����" << endl;
				inputSafe(cin, answer, 0, 2); //���������� ���� � ��������� �� 0 �� 2
				switch (answer){
				case 1:
					putAnswers(); //������ ������� ������������ � ����
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
		user_answers.push_back(answer); //��������� ������ ������������ � ������ �������
		sum[relative[user_answers.back()]-1] += dynamic_cast<Q_Cost&>(*it).getCost(answer); //���������� ������ �� ����� �� ������ � ��������������� �����
		++it; //������� � ���������� �������
		++counter; //��������� ������ �������
	}
	system("cls");
	check(); //�������� ������� ������������
}

void ProfTest::check(){ //�������� ������� ������������
	result(); //����� ���������� ���������
	cout << endl;
	system("pause");
	system("cls");
	cout << "������� ��������� ��� ���������?" << endl;
	cout << "1: ��\n"
		<< "2: ���\n" << endl;
	size_t answer{}; //���������� ��� ����� ������������
	inputSafe(cin, answer, 1, 2); //���������� ���� �� 1 �� 2
	if (answer == 1)
		putAnswers(); //���������� ������� ������������ � ����
}

void ProfTest::result(){ //��������� �� �����
	getPersonDef(); //��������� ��������� �� �����
	list<string> temp{}; //������ ���������
	string def{ "�� �������� ������� � �������� " }; //���������� ����������
	int index = findMaxInVect(sum); //������� ������ ������������ ����� � �������
	int new_index = index; //������ ������ ����������� ���������
	int te = index; //������ ���������� ������
	std::list<string>::iterator it = person_def.begin();
	while (index) { //������� � ��������, ���������������� �����
		++it;
		--index;
	}
	def += *it; //������ ���������� ���������� � ������
	def += ". ��������� ���������� � ������� ��������:\n";
	temp.push_back(def); //�������� ���������� ���������� � ������ � ���� �����������
	size_t size = sum.size() - 1; //����� ��������� ���������
	while (size) {
		new_index = finMaxInVectLessThan(sum, te); //����� �������� � ������� ������ �����������
		it = person_def.begin();
		te = new_index; //���������� �������
		while (new_index) { //������� � ������ ������
			++it;
			--new_index;
		}
		temp.push_back(*it); //�������� ������ � ��������
		--size;
	}
	person_def.clear(); //������� ������ ����� � ��������� ��������
	it = temp.begin();
	while (it != temp.end()) { //������� ����� �� ���������� ������� � ������ � ��������� ��������
		person_def.push_back(*it);
		++it;
	}
	putPersonDef(); //����� �������� ��������
}

std::istream& operator>>(std::istream& in, ProfTest& obj){ //��������� ���� �� ������
	if (in.eof()) //���� ����� ����
		return in; //����� ������
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.name); //������ ����� �����
	getline(in, obj.test_def); //������ �������� �����
	size_t size{}; //��������� ����������
	int temp{}; //��������� ����������
	in >> size; //������ ����� ����
	obj.relative.clear(); //������� ������� ��������� ����� �������� � ������
	obj.sum.clear(); //������� ������� ����
	obj.sz = size; //��������� ����� ����
	in >> size; //������ ����� ��������
	obj.questions.clear(); //������� ������� ��������
	while (size--) {
		in >> temp; //������ ������ �����, � ������� ��������� ������
		obj.relative.push_back(temp); //�������� ������ ����� � ������ ���������
	}
	in >> size; //������ ����� �������� 
	while (size) {
		Q_Cost temp{};
		in >> temp; //������ �������
		obj.questions.push_back(temp); //�������� ������� � ������
		--size;
	}
	while (in.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		in.get();
	getline(in, obj.def_path); //������ ���� � ����� � ���������� ��������
	getline(in, obj.answers_path); //������ ���� � ����� � ��������
	return in;
}

void ProfTest::getPersonDef(){ //���� �������� �������� ������������ �� ����� � ������������ � ���������� �� ������ �� ������
	File txt(def_path); //������������� ������� �����
	txt.open_in(); //��������� ������� �������� �����
	string temp{}; //������ ��� ������ ����� �� �������
	while (txt.in()) { //���� ���� ������ � �����
		txt.readLine(temp); //���������� ������
		person_def.push_back(temp); //�������� ������ � ������ � ��������� ��������
	}
}

void ProfTest::putAnswers(){ //������ ������� ������������ � ����
	File txt(answers_path); //������������� ������� �����
	txt.open_out(); //�������� ��������� ������ �����
	txt.write(sum.size()); //������ ����� ���� ������ ������������
	std::vector<int>::iterator it = sum.begin();
	while (it != sum.end()) { //���������������� ������ ����
		txt.write(*it);
		++it;
	}
	txt.write(user_answers.size()); //������ ����� ������� ������������
	it = user_answers.begin();
	while (it != user_answers.end()) {
		txt.write(*it); //���������������� ������ ������� ������������ � ����
		++it;
	}
}

void ProfTest::getAnswers(){ //������ ������� ������������ �� �����
	File txt(answers_path); //������������� ������� �����
	txt.open_in(); //�������� �������� ������ �����
	int size{}, temp{}; //size - ����� ����, temp - ���������� ��� ������ �����
	txt.read(size); //������ ����� ����
	sum.clear();
	while (size) {
		txt.read(temp); //������ �����
		sum.push_back(temp); //�������� ����� � ������ ����
		--size;
	}
	txt.read(size); //������ ����� �������
	while (size) {
		txt.read(temp); //������ ������ ������������ �� ������
		user_answers.push_back(temp); //�������� ������ ������������ � ������ ��������
		--size;
	}
}

string ProfTest::getPath(){ //���������� ���� � ����� � ����������� �������
	return path;
}