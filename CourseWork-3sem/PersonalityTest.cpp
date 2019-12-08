#include "PersonalityTest.h"
#include "Exc.h"
#include <sstream>
#include <stack>

void PersTest::start()
{
	sum = 0;
	person_def.clear();
	getAnswers();
	std::stack<int> prev{};
	if (sum)
	{
		if (last_question_index == questions.size()) {
			getPersonDef();
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете пройти его снова?" << endl;
			cout << "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить результаты теста\n"
				<< "\n0: Назад\n" << endl;
			size_t answer;
			inputSafe(cin, answer, 0, 2);
			switch (answer)
			{
			case 1:
				last_question_index = 0;
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
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете продолжить его?" << endl;
			cout << "\n1: Продолжить тест\n"
				<< "2: Пройти заново\n"
				<< "3: Удалить предыдущие результаты\n"
				<< "\n0: Назад\n" << endl;
			size_t answer;
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				last_question_index = 0;
				system("cls");
				return;
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
		last_question_index = 0;
	}
	cout << name << "\n" << endl;
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");
	size_t answer;
	typename std::list<Q_Cost>::iterator it = questions.begin();
	size_t st = last_question_index;
	while (st--)
		++it;
	while (it != questions.end()) {
		system("cls");
		static_cast<Q_Cost>(*it).ask();
		cout << "\n" << dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1
			<< ": Прервать тест\n" << endl;
		cout << "0: Назад" << endl;
		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1);
		if (answer == 0) {
			if (it == questions.begin())
				return;
			--it;
			--last_question_index;
			sum -= prev.top();
			prev.pop();
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) {
			system("cls");
			if (last_question_index) {
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n" << endl
					<< "0: Назад" << endl;
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
		prev.push(dynamic_cast<Q_Cost&>(*it).getCost(answer));
		sum += dynamic_cast<Q_Cost&>(*it).getCost(answer);
		++it;
		++last_question_index;
	}
	system("cls");
	check();
}

void PersTest::check()
{
	putPersonDef();
	cout << endl;
	system("pause");
	system("cls");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
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
		while (txt.fin.peek() == '\n')
			txt.fin.get();
		if (!txt.fin)
			break;
		getline(txt.fin, temp);
		if (isalnum(temp[0]))
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
	txt.fout << sum << endl;
	txt.fout << last_question_index << endl;
	return true;
}

bool PersTest::getAnswers()
{
	File txt(answers_path);
	if (!txt.open_in())
		return false;
	txt.fin >> sum;
	txt.fin >> last_question_index;
	return true;
}

string PersTest::getPath()
{
	return path;
}

//std::ostream& operator<<(std::ostream& out, PersTest& obj)
//{
//	out << obj.sum << endl;
//	out << obj.last_question_index << endl;
//	return out;
//}

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
