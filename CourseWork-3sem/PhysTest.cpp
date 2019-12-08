#include "PhysTest.h"
#include "Exc.h"
#include "OutputTable.h"
#include <sstream>

void PhysTest::MakeTable() {
	OutputTable a("Ваш ответ|Правильно");
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc + 1) + "|" + toStr(user_answers[vc]) + "|";
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "Да";
			else
				temp += "Нет";
			a.add_str(temp);
		}
	cout << a << endl;
}

void PhysTest::start()
{
	user_answers.clear(); // очищаем буфер ответов
	getAnswers(); // Получаем ответы пользователя на тест из файла
	if (user_answers.size())
	{
		if (user_answers.size() == questions.size()) { // Если тест пройден до конца
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете пройти его снова?" << endl;
			cout << "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить предыдущие результаты\n"
				<< "\n0: Назад\n" << endl;
			size_t answer{}; // ввод пользователя
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				user_answers.clear();
				system("cls");
				break;
			case 2:
				system("cls");
				MakeTable();
				result();
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
		else { // Если тест пройден не до конца
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете продолжить его?" << endl;
			cout << "\n1: Продолжить тест\n"
				<< "2: Пройти заново\n"
				<< "3: Удалить предыдущие результаты\n"
				<< "\n0: Назад\n" << endl;
			size_t answer{}; // ввод пользователя
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				user_answers.clear();
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

	cout << name << "\n" << endl;
	cout << test_def << endl;
	system("pause");
	system("cls");

	double answer; // answer - ввод пользователя
	size_t counter{ 1 }; // Номер текущего вопроса
	typename std::list<Q_OneAns>::iterator it = questions.begin();

	size_t st = user_answers.size();
	while (st--) {
		//Продолжаем тест с того места, на котором закончили
		++it;
		++counter;
	}

	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl;
		static_cast<Q_OneAns>(*it).ask();
		cout << "\n" << "1: Прервать тест\n"
			 << "0: Назад" 
			 << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer);
		if (answer == 0) {
			if (it == questions.begin())
				return;
			if (!user_answers.size())
				user_answers.pop_back();
			--it;
			--counter;
			continue;
		}
		if (answer == 1) {
			if (user_answers.size()) {
				size_t ans{};
				system("cls");
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n" << endl
					<< "0: Назад" << endl;
				inputSafe(cin, ans, 0, 2);
				switch (ans)
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
		++counter;
		++it;
	}
	system("cls");
	check();
}

void PhysTest::check()
{
	MakeTable();
	result();
	system("pause");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if (answer == 1)
		putAnswers();
}

void PhysTest::result()
{
	double correct{};
	size_t vc{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				++correct;
		}
	cout << "Ваш процент правильных ответов составляет: " << (int)((correct / questions.size()) * 100) << "%" << endl;

}

bool PhysTest::putAnswers() {
	File txt(answers_path);
	if (!txt.open_out())
		return false;
	txt.write(user_answers.size());
	std::vector<double>::iterator in = user_answers.begin();
	while (in != user_answers.end()) {
		txt.write(*in);
		++in;
	}
	return true;
}

bool PhysTest::getAnswers()
{
	File txt(answers_path);
	if (!txt.open_in())
		return false;
	size_t size{};
	txt.read(size);
	while (size) {
		size_t temp{};
		txt.read(temp);
		user_answers.push_back(temp);
		--size;
	}
	return true;
}

string PhysTest::getPath()
{
	return path;
}

std::istream& operator>>(std::istream& in, PhysTest& obj)
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
		Q_OneAns temp{};
		in >> temp;
		obj.questions.push_back(temp);
		--size;
	}
	while (in.peek() == '\n')
		in.get();
	getline(in, obj.answers_path);
	return in;
}
