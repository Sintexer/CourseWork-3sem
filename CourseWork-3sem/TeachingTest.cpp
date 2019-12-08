#include "TeachingTest.h"
#include "Exc.h"
#include "OutputTable.h"

void TeachingTest::AddUserAns(size_t ans)
{
	user_answers.push_back(ans);
}

void TeachingTest::addQuestion(Q_OneAns qoa)
{
	questions.push_back(qoa);
}

void TeachingTest::addTheor(string theor)
{
	theory.push_back(theor);
}

void TeachingTest::setTheoryPath(string path)
{
	theory_path = path;
}

void TeachingTest::MakeTable() {
	OutputTable a("Ваш ответ|Правильно");
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc + 1) + "|" + std::to_string(user_answers[vc]) + ")|";
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "Да";
			else
				temp += "Нет";
			a.add_str(temp);
		}
	cout << a << endl;
}


bool TeachingTest::startTheory() 
{
	readTheory();
	system("cls");
	cout << "Теоритическая часть\n" << endl;
	system("pause");
	system("cls");
	typename std::list<string>::iterator it = theory.begin();

	size_t answer{};
	while (it != theory.end()) {
		system("cls");
		cout << *it << endl;	
		cout << "\n1: Вперед\n"
			<< "2: Пропустить теорию\n\n" 
			<< "3: Прервать тест\n"
			<< "0: Назад" << endl;
		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, 3);
		if (answer == 0) {
			if (it == theory.begin())
				return false;
			--it;
			continue;
		}
		if (answer == 2)
			break;
		if (answer == 3)
			return false;
		++it;
	}
	return true;
}

void TeachingTest::check()
{
	
	result();
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

void TeachingTest::result()
{
	MakeTable();
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

void TeachingTest::start()
{
	user_answers.clear();
	getAnswers();
	if (user_answers.size())
	{
		if (user_answers.size() == questions.size()) {
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете пройти его снова?" << endl;
			cout << "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить результаты теста\n"
				<< "\n0: Назад\n" << endl;
			size_t answer;
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				user_answers.clear();
				system("cls");
				break;
			case 2:
				system("cls");
				result();
				cout << endl;
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
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");

	if (!startTheory())
		return;

	size_t answer{}, counter{1};
	counter = user_answers.size();
	typename std::list<Q_OneAns>::iterator it = questions.begin();
	size_t st = user_answers.size();
	while (st--)
		++it;
	system("cls");
	cout << "Практическая часть\n" << endl;
	system("pause");
	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl;
		static_cast<Q_OneAns>(*it).ask();

		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1 
			<< ": Прервать тест\n"
			<< "0: Назад" << endl;

		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1);
		if (answer == 0) {
			if (it == questions.begin())
				if (!startTheory())
					return;
				else {
					if (it == questions.begin()) {
						system("cls");
						cout << "Практическая часть\n" << endl;
						system("pause");
					}
					continue;
				}
			if (user_answers.size())/////////////
				user_answers.pop_back();
			--it;
			--counter;
			continue;
		}
		if (answer == (dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1)) {
			system("cls");
			if (user_answers.size()) {
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
		user_answers.push_back(answer);
		++it;
		++counter;
	}
	system("cls");
	check();
}

string TeachingTest::getTheoryPath()
{
	return theory_path;
}

string TeachingTest::getPath()
{
	return path;
}

void TeachingTest::readTheory()
{
	File txt(getTheoryPath());
	string temp{};
	txt.open_in();
	theory.clear();
	while (txt.in()) {
		txt.readLine(temp);
		theory.push_back(temp);
	}
}

bool TeachingTest::putAnswers()
{
	File txt(answers_path);
	if (!txt.open_out())
		return false;
	txt.write(user_answers.size());
	std::vector<size_t>::iterator in = user_answers.begin();
	while (in != user_answers.end()) {
		txt.write(*in);
		++in;
	}
	return true;
}

bool TeachingTest::putTheory()
{
	File txt(theory_path);
	if(!txt.open_out())
		return false;
	std::list<string>::iterator in = theory.begin();
	while (in != theory.end()) {
		txt.write(*in);
		++in;
	}
	txt.close();
	return true;
}

bool TeachingTest::getAnswers()
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

std::istream& operator>>(std::istream& in, TeachingTest& obj)
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
	getline(in, obj.theory_path);
	getline(in, obj.answers_path);
	return in;
}
