#include "TeachingTest.h"
#include "OutputTable.h"

void TeachingTest::MakeTable() {//Выводит ответы пользователя на тест в виде таблицы
	OutputTable a("Номер вопроса|Ваш ответ|Правильно");//Создает объект класса OutputTable
	size_t vc{}; //Индекс в векторе
	string temp{}; //Строка для добавления в таблицу
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc + 1) + "|" + std::to_string(user_answers[vc]) + ")|"; //Вносит в строку таблицы номер вопроса и ответ пользователя
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "Да"; //Выводит в последней колонке Да, если пользователь ответил правильно на вопрос
			else
				temp += "Нет"; //Выводит в последней колонке Нет, если пользователь неправильно ответил на вопрос
			a.add_str(temp); //Добавляет строку в объект таблицы
		}
	cout << a << endl; //Выводит таблицу на экран
}


bool TeachingTest::startTheory(){ //Выводит на экран теоритическую часть теста
	readTheory(); //Чтение теории из файла
	system("cls");
	cout << "Теоритическая часть\n" << endl;
	system("pause");
	system("cls");
	typename std::list<string>::iterator it = theory.begin();

	size_t answer{};
	while (it != theory.end()) { //Итерация по списку с теорией
		system("cls");
		cout << *it << endl;	//Вывод теории
		cout << "\n1: Вперед\n"
			<< "2: Пропустить теорию\n\n" 
			<< "3: Прервать тест\n"
			<< "0: Назад" << endl;
		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, 3);
		if (answer == 0) { //Если пользователь выбрал "Назад"
			if (it == theory.begin()) //Если это было начало теории
				return false; //Выход в меню
			--it; 
			continue;
		}
		if (answer == 2) //Если пользователь выбрал "Пропустить теорию"
			break;
		if (answer == 3)
			return false; //Выход в меню
		++it;
	}
	return true; //Переход к практической части теста
}

void TeachingTest::check(){ //Проверяет и сохраняет результаты в файл
	result(); //Вывод результата на экран
	system("pause");
	system("cls");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if (answer == 1)
		putAnswers(); //Сохранение ответов в файл
}

void TeachingTest::result(){ //Выводит результат теста на экран
	MakeTable(); //Выводит ответы в виде таблицы
	double correct{}; //Число правильно отвеченных вопросов
	size_t vc{}; //Индекс в векторе ответов
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc]) //Если ответ правильный
				++correct; //Увеличение числа правильно отвеченных вопросов на 1
		}
	cout << "Ваш процент правильных ответов составляет: " << (int)((correct / questions.size()) * 100) << "%" << endl;
}

void TeachingTest::start(){ //Начало теста
	user_answers.clear(); //Очистка ответов пользователя
	getAnswers(); //Чтение ответов пользователя из файла
	if (user_answers.size()) ////Если пользователь проходил тест
	{
		if (user_answers.size() == questions.size()) {//Если тест пройден полностью
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете пройти его снова?\n"

				<< "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить результаты теста\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод числа в диапазоне от 0 до 3
			switch (answer)
			{
			case 1:
				user_answers.clear(); //Очистка вектора ответов пользователя
				system("cls");
				break;
			case 2:
				system("cls");
				result(); //Вывод результатов теста на экран
				cout << endl;
				return;
			case 3:
				clearAns(); //Очистка файла с ответами
				return;
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
		else { //Если тест был пройден не до конца
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
				return;
			case 3:
				clearAns(); //Очистка файла с ответами
				return; //Выход в меню
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
	}
	cout << name << "\n" << endl;
	cout << test_def << "\n" << endl;
	system("pause");
	system("cls");

	if (!startTheory()) //Вывести теорию по тесту
		return; //Выход в меню

	size_t answer{}, counter{ user_answers.size()+1 }; //answer - ввод пользователя, counter - номер вопроса
	typename std::list<Q_OneAns>::iterator it = questions.begin();
	size_t st = user_answers.size();
	while (st--)
		++it; //Переход к вопросу, на котором остановился пользователь в предыдущий раз
	system("cls");
	cout << "Практическая часть\n" << endl;
	system("pause");
	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl; //Вывод номера текущего вопроса
		static_cast<Q_OneAns>(*it).ask(); //Вывод вопроса

		cout << "\n" << dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1 
			<< ": Прервать тест\n"
			<< "0: Назад" << endl;

		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize()+1);
		if (answer == 0) { //Если пользователь выбрал "Назад"
			if (it == questions.begin()) //Если это был первый вопрос
				if (!startTheory()) //Начать теорию
					return; //Если пользователь вышел из теории - выйти в меню
				else {
					if (it == questions.begin()) { //Если пользователь перешел от теории к тесту
						system("cls");
						cout << "Практическая часть\n" << endl;
						system("pause");
					}
					continue;
				}
			if (user_answers.size()) 
				user_answers.pop_back();  //Удалить предыдущий ответ пользователя из вектора
			--it; //Переход к предыдущему вопросу
			--counter; //Декремент номера вопроса
			continue;
		}
		if (answer == (dynamic_cast<Q_OneAns&>(*it).getAnswersSize() + 1)) { //Если пользователь выбрал "Прервать тест"
			system("cls");
			if (user_answers.size()) { //Если пользователь ответил хотя бы на один вопрос
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n" << endl
					<< "0: Назад" << endl;
				inputSafe(cin, answer, 0, 2); 
				switch (answer)
				{
				case 1:
					putAnswers(); //Сохранить ответы пользователя в файл
					return; //Выход в меню
				case 2:
					return; //Выход в меню
				case 0:
					continue; //Продолжить тест
					break;
				}
			}
			return;
		}
		user_answers.push_back(answer); //Занести ответ пользователя в вектор
		++it; //Перейти к следующему вопросу
		++counter; //Инкремент номера вопроса
	}
	system("cls");
	check(); //Проверка ответов пользователя
}

string TeachingTest::getTheoryPath(){ //Возвращает путь к файлу с теорией
	return theory_path;
}

string TeachingTest::getPath(){//Возвращает путь к файлу с тестами
	return path;
}

void TeachingTest::readTheory(){ //Читает теорию из файла в список
	File txt(getTheoryPath()); //Инициализация объекта файла
	string temp{}; //Строка для чтения
	txt.open_in(); //Открыть файл для чтения
	theory.clear(); //Очистить список с теорией
	while (txt.in()) { //Пока в файле есть теория
		txt.readLine(temp); //Чтение строки теории
		theory.push_back(temp); //Внесение строки в список с теорией
	}
}

void TeachingTest::putAnswers(){ //Заносит ответы пользователя в файл
	File txt(answers_path); //Инициализация объекта файла
	txt.open_out(); //Открытие выходного потока объекта файла
	std::vector<size_t>::iterator it = user_answers.begin();
	while (it != user_answers.end()) { //Итерация по массиву ответов пользователя
		txt.write(*it, '|'); //Последовательная запись ответов пользователя в файл
		++it;
	}
}

void TeachingTest::getAnswers()
{
	File txt(answers_path); //Инициализация объекта файла
	txt.open_in(); //Открывает входной поток файлового объекта
	txt.getFin().peek();
	if (txt.getFin().eof()) //Если файл пуст
		return;
	size_t temp{}; //Временная переменная для чтения ответов
	while (txt.in()) { //Пока из файла можно что-то прочитать
		txt.read(temp); //Чтение числа
		user_answers.push_back(temp); //Заносит ответ пользователя в вектор объектов
		txt.getFin().get(); //Пропуск символа-разделителя
	}
}

std::istream& operator>>(std::istream& in, TeachingTest& obj){ //Инициализация объекта обучающего теста из потока
	if (in.eof()) //Если поток пуст
		return in;
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.name); //Чтение имени теста
	getline(in, obj.test_def); //Чтение описания теста
	size_t size{}; //Число вопросов
	in >> size;
	obj.questions.clear();
	while (size) {
		Q_OneAns temp{};
		in >> temp; //Чтение вопроса
		obj.questions.push_back(temp); //Внесение вопроса в список вопросов
		--size;
	}
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.theory_path); //Чтение пути к файлу с теорией
	getline(in, obj.answers_path); //Чтение пути к файлу с ответами
	return in; 
}
