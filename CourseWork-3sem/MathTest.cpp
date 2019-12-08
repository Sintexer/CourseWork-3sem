#include "MathTest.h"
#include "Exc.h"
#include "OutputTable.h"

void MathTest::MakeTable() {
	OutputTable a("Ваш ответ|Правильно");
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc+1)+"|"+std::to_string(user_answers[vc])+")|";
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "Да";
			else
				temp += "Нет";
			a.add_str(temp);
		}
	cout << a << endl;
}

void MathTest::start()
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
				<< "3: Удалить предыдущие ответы\n"
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
				MakeTable();
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
		else
		{
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
	size_t answer{}, counter{1}; // answer - ответ пользователя, counter - номер текущего вопроса

	typename std::list<Q_OneAns>::iterator it = questions.begin();
	size_t st = user_answers.size();
	while (st--) {
		++it;
		++counter;
	}
	
	while(it!=questions.end()){
		system("cls");

		cout << "Вопрос " << counter << " из " << questions.size() << endl; 
		static_cast<Q_OneAns>(*it).ask();
		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1 
			<< ": Прервать тест\n" 
			<< "0: Назад\n"
			<< "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1);

		if (answer == 0) {
			if (it == questions.begin())
				return;
			if (user_answers.size())
				user_answers.pop_back();
			--it;
			--counter;
			continue;
		}
		if (answer == dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1) {
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
		++counter;
		++it;
	}
	system("cls");
	check();
}

void MathTest::check()
{
	MakeTable();
	result();
	system("pause");
	system("cls");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if(answer==1)
		putAnswers();

}

void MathTest::result()
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

std::istream& operator>> (std::istream& in, MathTest& obj)
{
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


bool MathTest::getAnswers()
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

bool MathTest::putAnswers()
{
	File txt(answers_path);
	if (!txt.open_out())
		return false;
	txt.write(user_answers.size());
	int sz = user_answers.size();
	std::vector<size_t>::iterator it;
	it = user_answers.begin();
	while (sz--) {
		txt.write(*it);
		++it;
	}
	return true;
}

string MathTest::getPath()
{
	return path;
}
