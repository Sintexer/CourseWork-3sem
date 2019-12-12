#include "MathTest.h"
#include "OutputTable.h"

void MathTest::MakeTable() { //Выводит ответы пользователя на тест в виде таблицы
	OutputTable a("Ваш ответ|Правильно"); //Создает объект класса OutputTable
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc+1)+"|"+std::to_string(user_answers[vc])+")|"; //Вносит в строку таблицы номер вопроса и ответ пользователя
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "Да"; //Выводит в последней колонке Да, если пользователь ответил правильно на вопрос
			else
				temp += "Нет"; //Выводит в последней колонке Нет, если пользователь неправильно ответил на вопрос
			a.add_str(temp); //Добавляет строку в объект таблицы
		}
	cout << a << endl; //Выводит таблицу на экран
}

void MathTest::start(){ //Проводит тест
	user_answers.clear(); //Очищает вектор ответов пользователя
	getAnswers(); //Получает ответы пользователя из файла
	if (user_answers.size()){ //Если пользователь проходил тест
		if (user_answers.size() == questions.size()) { //Если тест пройден до конца
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете пройти его снова?\n"

				<< "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить предыдущие ответы\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод числа в диапазоне от 0 до 3
			switch (answer){
			case 1:
				user_answers.clear(); //Очистка вектора ответов пользователя
				system("cls");
				break;
			case 2:
				system("cls");
				MakeTable(); //Вывод ответов пользователя на тест в виде таблицы на экран
				result(); //Вывод процента правильных ответов
				cout << endl;
				return; //Выход в меню
			case 3:
				system("cls");
				clearAns(); //Очистка файла с предыдущими ответами пользователя
				return; //Выход в меню
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
		else //Если тест пройден не до конца
		{
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете продолжить его?\n"

				<< "\n1: Продолжить тест\n"
				<< "2: Пройти заново\n"
				<< "3: Удалить предыдущие результаты\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод числа в диапазоне от 0 до 3
			switch (answer)
			{
			case 1:
				system("cls");
				break;
			case 2:
				user_answers.clear(); //Очистка вектора ответов пользователя
				system("cls");
				return; //Выход в меню
			case 3:
				system("cls");
				clearAns(); //Очистка файла с предыдущими ответами пользоватееля
				return; //Выход в меню
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
	}

	cout << name << "\n" << endl; //Вывод имени теста
	cout << test_def << "\n" << endl; //Вывод описанич теста
	system("pause");
	system("cls");
	size_t answer{}, counter{user_answers.size()+1}; // answer - ответ пользователя, counter - номер текущего вопроса

	list<Q_OneAns>::iterator it = questions.begin();
	size_t st{ user_answers.size() };
	while (st--) //Переход к вопросу, на котором пользователь прервал тест в прошлый раз
		++it;
	
	while(it!=questions.end()){
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl; //Вывод номера текущего вопроса
		static_cast<Q_OneAns>(*it).ask(); //Вывод вопроса и вариантов ответа на него
		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1 
			<< ": Прервать тест\n" 
			<< "0: Назад\n"
			<< "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1); //Безопасный ввод числа в диапазоне
		if (answer == 0) { //Если пользователь выбрал пункт назад
			if (it == questions.begin()) //Если это первый вопрос
				return; //Выход в меню
			if (user_answers.size()) //Если есть ответы пользователя в векторе ответов
				user_answers.pop_back(); //Удаление последнего ответа из вектора
			--it; //Переход к предыдущему вопросу
			--counter; //Декремент номера текущего вопроса
			continue;
		}
		if (answer == dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1) { //Если пользователь выбрал "Прервать тест"
			system("cls");
			if (user_answers.size()) { //Если пользователь ответил хотя бы на 1 вопрос
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n" << endl
					<< "0: Назад" << endl;
				inputSafe(cin, answer, 0, 2); //Безопасный ввод числа в диапазоне от 0 до 2
				switch (answer){
				case 1:
					putAnswers(); //Запись ответов пользователя в файл
					return; //Выход в меню
				case 2:
					return; //Выход в меню
				case 0:
					continue; //Продолжение теста с этого же вопроса
					break;
				}
			}
			return; //Выход в меню
		}

		user_answers.push_back(answer); //Внесение ответа пользователя в вектор
		++counter; //Инкремент номера текущего вопроса
		++it; //Переход к следующему вопросу
	}
	system("cls");
	check(); //Проверка теста по правильным ответам
}
void MathTest::check(){ //Проверка теста по правильным ответам
	MakeTable(); //Выводит таблицу с ответами пользователя на экран
	result(); //Выводит процент правильных ответов
	system("pause");
	system("cls");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
	size_t answer{}; //Ввод пользователя
	inputSafe(cin, answer, 1, 2); //Безопасный ввод в диапазоне от 1 до 2
	if(answer==1)
		putAnswers(); //Записывает ответы пользователя в файл
}

void MathTest::result(){ //Выводит процент правильных ответов на экран
	double correct{}; //Количество правильных ответов
	size_t vc{}; //Номер вопроса
	list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc]) //Если ответ пользователя совпал с правильным ответом
				++correct; //Инкремент количества правильных ответов на вопрос
		}
	cout << "Ваш процент правильных ответов составляет: " << (int)((correct / questions.size()) * 100) << "%" << endl;
}

std::istream& operator>> (std::istream& in, MathTest& obj){ //Ввод теста из потока
	if (in.eof()) //Если поток пуст
		return in; //Конец работы функции
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.name); //Ввод имени теста
	getline(in, obj.test_def); //Ввод описания теста
	size_t size{}; //Число вопросов
	in >> size; //Ввод числа вопросов
	obj.questions.clear(); //Очистка списка вопросов
	while (size) {
		Q_OneAns temp{};
		in >> temp; //Ввод вопроса
		obj.questions.push_back(temp); //Внесение вопроса в список вопросов
		--size;
	}
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.answers_path); //Ввод пути к ответам пользователя
	return in;
}


void MathTest::getAnswers(){ //Получает ответы пользователя из файла
	File txt(answers_path); //Инициализация объекта файла
	txt.open_in(); //Открывает входной поток файлового объекта
	size_t size{};
	txt.read(size);
	while (size) {
		size_t temp{};
		txt.read(temp);
		user_answers.push_back(temp); //Заносит ответ пользователя в вектор объектов
		--size;
	}
}

void MathTest::putAnswers(){ //Заночит ответы пользователя в файл
	File txt(answers_path); //Инициализация объекта файла
	txt.open_out(); //Открытие выходного потока объекта файла
	txt.write(user_answers.size()); //Записывает количество ответов пользователя в файл
	int sz = user_answers.size();
	std::vector<size_t>::iterator it;
	it = user_answers.begin();
	while (sz--) {
		txt.write(*it); //Последовательная запись ответов пользователя в файл
		++it;
	}
}

string MathTest::getPath(){
	return path; //Возвращает путь файла
}
