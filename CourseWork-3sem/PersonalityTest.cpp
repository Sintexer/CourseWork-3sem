#include "PersonalityTest.h"
#include "Exc.h"
#include <sstream>


void PersTest::start()
{
	sum = 0;
	person_def.clear();
	getAnswers();
	// ������� ���������� ���������� �����, ���������� � ������� � �������� ������ �� �����
	if (sum)
	{
		if (user_answers.size() == questions.size()) {
			getPersonDef();
			cout << "�� ��� ��������� ���� ����" << endl;
			cout << "������� ������ ��� �����?" << endl;
			cout << "\n1: ������ ���� ������\n"
				<< "2: ���������� ����������\n"
				<< "3: ������� ���������� �����\n"
				<< "\n0: �����\n" << endl;
			size_t answer{};
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				user_answers.clear();
				system("cls");
				break;
			case 2:
				system("cls");
				putPersonDef();
				cout << endl;
				return;
			case 3:
				system("cls");
				clearAns();
				return;
			case 0:
				return;
			default:
				break;
			}
		}
		else {
			cout << "�� ��� ��������� ���� ����" << endl;
			cout << "������� ���������� ���?" << endl;
			cout << "\n1: ���������� ����\n"
				<< "2: ������ ������\n"
				<< "3: ������� ���������� ����������\n"
				<< "\n0: �����\n" << endl;
			size_t answer;
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				user_answers.clear();
				system("cls");
				break;
			case 3:
				clearAns();
				return;
			case 0:
				return;
			default:
				break;
			}
		}
	}
	else {
		user_answers.clear();
	}
	cout << name << "\n" << endl;
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");
	size_t answer{}, counter{ 1 };
	typename std::list<Q_Cost>::iterator it = questions.begin();
	size_t st = user_answers.size();
	while (st--) {
		++counter;
		++it;
	}
	while (it != questions.end()) {
		system("cls");
		cout << "������ " << counter << " �� " << questions.size() << endl;
		static_cast<Q_Cost>(*it).ask();
		cout << "\n" << dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1
			<< ": �������� ����\n" << endl;
		cout << "0: �����" << endl;
		cout << "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1);
		if (answer == 0) {
			if (it == questions.begin())
				return;
			--it;
			--counter;
			sum -= dynamic_cast<Q_Cost&>(*it).getCost(user_answers.back());
			user_answers.pop_back();
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) {
			system("cls");
			if (user_answers.size()) {
				cout << "������� ��������� ��� ���������?\n"
					<< "1: ��\n"
					<< "2: ���\n" << endl
					<< "0: �����" << endl;
				inputSafe(cin, answer, 0, 2);
				switch (answer)
				{
				case 1:
					putAnswers();
					return;
				case 2:
					return;
				case 0:
					continue;
					break;
				}
			}
			return;
		}
		user_answers.push_back(answer);
		sum += dynamic_cast<Q_Cost&>(*it).getCost(answer);
		++it;
		++counter;
	}
	system("cls");
	check();
}

void PersTest::check()
{
	getPersonDef();
	putPersonDef();
	cout << endl;
	system("pause");
	system("cls");
	cout << "������� ��������� ��� ���������?" << endl;
	cout << "1: ��\n"
		<< "2: ���\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if (answer == 1)
		putAnswers();
}

void PersTest::getPersonDef()
{
	File txt(def_path);
	txt.open_in();
	string temp{};
	size_t file_sum{};
	bool flag{};
	
	do {
		if (!txt.in())
			break;
		txt.readLine(temp);
		if (temp[0]>='0' && temp[0]<='9')
			flag = true;
		if (!flag)
			person_def.push_back(temp);
		else {
			std::istringstream iss(temp, std::istringstream::in);
			iss >> file_sum;
			if (sum > file_sum) {
				break;
			}
			person_def.clear();
			flag = false;
		}
	} while (!flag);

}

bool PersTest::putAnswers()
{
	File txt(answers_path);
	if (!txt.open_out())
		return false;
	txt.write(sum);
	txt.write(user_answers.size());
	std::vector<size_t>::iterator it = user_answers.begin();
	while(it != user_answers.end()) {
		txt.write(*it);
		++it;
	}
	return true;
}

bool PersTest::getAnswers()
{
	File txt(answers_path);
	if (!txt.open_in())
		return false;
	txt.read(sum);
	size_t sz{}, temp{};
	txt.read(sz);
	while (sz--) {
		txt.read(temp);
		user_answers.push_back(temp);
	}
	return true;
}

string PersTest::getPath()
{
	return path;
}

std::istream& operator>>(std::istream& in, PersTest& obj)
{
	if (in.eof())
		return in;
	while (in.peek() == '\n')
		in.get();

	getline(in, obj.name);
	getline(in, obj.test_def);
	size_t size{};
	in >> size;
	obj.questions.clear();
	while (size) {
		Q_Cost temp{};
		in >> temp;
		obj.questions.push_back(temp);
		--size;
	}
	while (in.peek() == '\n')
		in.get();
	getline(in, obj.def_path);
	getline(in, obj.answers_path);
	return in;
}
