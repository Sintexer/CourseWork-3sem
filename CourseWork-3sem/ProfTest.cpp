#include "ProfTest.h"
#include "Exc.h"

int findMaxInVect(std::vector<int>& vc) {
	int prev{};
	int index{};
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] > prev) {
			index = counter;
			prev = vc[counter];
		}
	}
	return index;
}

int finMaxInVectLessThan(std::vector<int>& vc, int prev_max) {
	int prev{};
	int index{};
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] >= prev && counter != prev_max && vc[counter] <= vc[prev_max]) {
			prev = vc[counter];
			index = counter;
		}
	}
	return index;
}

void ProfTest::start()
{
	sum.clear();
	getAnswers();
	if (sum.size()){
		if (user_answers.size() == questions.size()) {
			getPersonDef();
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете пройти его снова?" << endl;
			cout << "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить предыдущие результаты\n"
				<< "\n0: Назад\n" << endl;
			size_t answer{};
			inputSafe(cin, answer, 0, 3);
			switch (answer){
			case 1:
				user_answers.clear();
				sum.clear();
				sum.resize(sz);
				system("cls");
				break;
			case 2:
				system("cls");
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
		else {
			cout << "Вы уже проходили этот тест" << endl;
			cout << "Желаете продолжить его?" << endl;
			cout << "\n1: Продолжить тест\n"
				<< "2: Пройти заново\n"
				<< "3: Удалить предыдущие результаты\n"
				<< "\n0: Назад\n" << endl;
			size_t answer{};
			inputSafe(cin, answer, 0, 3);
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				user_answers.clear();
				sum.clear();
				sum.resize(sz);
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
	else
		sum.resize(sz);
	cout << name << "\n" << endl;
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");
	
	typename std::list<Q_Cost>::iterator it = questions.begin();
	size_t answer{};
	size_t st{};
	size_t counter = user_answers.size()+1;
	while (st++<user_answers.size()) {
		++it;
	}
	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl;
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
			--counter;
			sum[relative[user_answers.size()-1]-1] -= dynamic_cast<Q_Cost&>(*it).getCost(user_answers.back());
			user_answers.pop_back();
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) {
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
		sum[relative[user_answers.back()]-1] += dynamic_cast<Q_Cost&>(*it).getCost(answer);
		++it;
		++counter;
	}
	system("cls");
	check();
}

void ProfTest::check()
{
	result();
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

void ProfTest::result()
{
	getPersonDef();
	std::list<string> temp{};
	string tp{};
	string def{ "Вы наиболее склонны к предмету " };
	int index = findMaxInVect(sum);
	int new_index = index;
	int te = index;
	std::list<string>::iterator it = person_def.begin();
	while (index) {
		++it;
		--index;
	}
	def += *it;
	def += ". Остальные склонности в порядке убывания:\n";
	temp.push_back(def);
	size_t size = sum.size() - 1;
	while (size) {

		new_index = finMaxInVectLessThan(sum, te);
		it = person_def.begin();
		te = new_index;
		while (new_index) {
			++it;
			--new_index;
		}
		temp.push_back(*it);
		--size;
	}
	person_def.clear();
	it = temp.begin();
	while (it != temp.end()) {
		person_def.push_back(*it);
		++it;
	}
	putPersonDef();
}

void ProfTest::getPersonDef()
{
	File txt(def_path);
	txt.open_in();
	string temp{};
	while (txt.in()) {
		txt.readLine(temp);
		person_def.push_back(temp);
	}
}

bool ProfTest::putAnswers()
{
	File txt(answers_path);
	if (!txt.open_out())
		return false;
	txt.write(sum.size());
	std::vector<int>::iterator it = sum.begin();
	while (it != sum.end()) {
		txt.write(*it);
		++it;
	}
	txt.write(user_answers.size());
	it = user_answers.begin();
	while (it != user_answers.end()) {
		txt.write(*it);
		++it;
	}
	return true;
}

bool ProfTest::getAnswers()
{
	File txt(answers_path);
	if (!txt.open_in())
		return false;
	int size{}, temp{};
	txt.read(size);
	sum.clear();
	while (size) {
		txt.read(temp);
		sum.push_back(temp);
		--size;
	}
	txt.read(size);
	while (size) {
		txt.read(temp);
		user_answers.push_back(temp);
		--size;
	}
	return true;
}

string ProfTest::getPath()
{
	return path;
}

std::istream& operator>>(std::istream& in, ProfTest& obj)
{
	if (in.eof())
		return in;
	while (in.peek() == '\n' || in.peek() == '\r')
		in.get();
	getline(in, obj.name);
	getline(in, obj.test_def);
	size_t size{};
	int temp{};
	in >> size;
	obj.relative.clear();
	obj.sum.clear();
	obj.sz = size;
	in >> size;
	obj.questions.clear();
	while (size--) {
		in >> temp;
		obj.relative.push_back(temp);
	}
	in >> size;
	while (size) {
		Q_Cost temp{};
		in >> temp;
		obj.questions.push_back(temp);
		--size;
	}
	while (in.peek() == '\n' || in.peek() == '\r')
		in.get();
	getline(in, obj.def_path);
	getline(in, obj.answers_path);
	return in;
}
