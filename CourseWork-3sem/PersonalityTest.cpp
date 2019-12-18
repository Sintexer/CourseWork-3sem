#include "PersonalityTest.h"

void PersTest::start(){ //Начало теста
	sum = 0; //Обнуление суммы баллов
	person_def.clear(); //Очистка описания личности пользователя
	getAnswers(); //Получение ответов пользователя на тест
	if (sum){ //Если пользователь уже проходил тест
		if (user_answers.size() == questions.size()) { //Если пользователь проходил тест до конца
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете пройти его снова?\n"

				<< "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить результаты теста\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод в диапазоне от 0 до 3
			switch (answer){
			case 1:
				user_answers.clear(); //Очистка вектора ответов пользователя
				sum = 0;
				system("cls");
				break;
			case 2:
				getPersonDef(); //Получение описания пользователя из файйла в соответствии с набранными баллами
				system("cls");
				putPersonDef(); //Вывод описания личности пользователя
				cout << endl;
				return;
			case 3:
				system("cls");
				clearAns(); //Очищает файл с ответами пользователя
				return; //Выход в меню
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
		else { //Если пользователь прервал тест в прошлый раз
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете продолжить его?\n"

				<< "\n1: Продолжить тест\n"
				<< "2: Пройти заново\n"
				<< "3: Удалить предыдущие результаты\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод в диапазоне от 0 до 3
			switch (answer){
			case 1:
				system("cls"); 
				break; //Тест продолжается с вопроса, на котором пользователь прервал тест
			case 2:
				user_answers.clear(); //Очистка предыдущих ответов пользователя
				sum = 0;
				system("cls");
				break;
			case 3:
				clearAns(); //Очистка файла с ответами пользователя
				return; //Выход в меню
			case 0:
				return; //Выход в меню
			default:
				break;
			}
		}
	}
	else
		user_answers.clear(); //Очистка предыдущих ответов пользователя
	cout << name << "\n" << endl; //Вывод имени теста
	cout << test_def << "\n" << endl; //Вывод описания теста
	system("pause");
	system("cls");
	size_t answer{}, counter{user_answers.size()+1}; //answer для ввода пользователя, counter - номер текущего вопроса
	typename std::list<Q_Cost>::iterator it = questions.begin();
	size_t st{ user_answers.size() };
	while (st--)
		++it; //Переход к вопросу, на котором пользователь остановился в прошлый раз
	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl; //Вывод номера текущего вопроса
		static_cast<Q_Cost>(*it).ask(); //Вывод вопроса и вариантов ответа на него
		cout << "\n" << dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1
			<< ": Прервать тест\n"
			<< "\n0: Назад\n"
			<<"\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1); //Безопасный ввод в диапазоне
		if (answer == 0) { //Если пользователь выбрал "Назад"
			if (it == questions.begin()) //Если это был первый вопрос
				return; //Выход в меню
			--it; //Переход к предыдущему вопросу 
			--counter; //Декремент номера вопроса
			sum -= dynamic_cast<Q_Cost&>(*it).getCost(user_answers.back()); //Вычитание из суммы балла за предыдущий вопрос
			user_answers.pop_back(); //Удаление предыдущего ответа пользователя из вектора
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) { //Если пользователь выбрал "Прервать тест"
			system("cls");
			if (user_answers.size()) { //Если пользователь ответил хотя бы на один вопрос
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n"
					<< "\n0: Назад" << endl;
				inputSafe(cin, answer, 0, 2); //Безопасный ввод в диапазоне от 0 до 2
				switch (answer){
				case 1:
					putAnswers(); //Запись ответов пользователя в файл
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
		user_answers.push_back(answer); //Занесение ответа пользователя в вектор ответов
		sum += dynamic_cast<Q_Cost&>(*it).getCost(answer); //Добавить баллы за ответ на вопрос
		++it; //Переход к следующему вопросу
		++counter; //Инкремент номера вопроса
	}
	system("cls");
	check(); //Проверка ответов пользователя
}

void PersTest::check(){ //Проверка ответов пользователя
	getPersonDef(); //Получение описания пользователя из файла в соответствии с набранной по вопросам суммой
	putPersonDef(); //Выводит описание личности пользователя на экран
	cout << endl;
	system("pause");
	system("cls");
	cout << "Желаете сохранить ваш результат?" << endl;
	cout << "1: Да\n"
		<< "2: Нет\n" << endl;
	size_t answer{}; //Переменная для ввода пользователя
	inputSafe(cin, answer, 1, 2); //Безопасный ввод от 1 до 2
	if (answer == 1) 
		putAnswers(); //Сохранение ответов пользователя в файл
}

std::istream& operator>>(std::istream& in, PersTest& obj){ //Считывает тест из потока
	if (in.eof()) //Если поток пуст
		return in; //Конец чтения
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();

	getline(in, obj.name); //Чтение имени теста
	getline(in, obj.test_def); //Чтение описания теста
	size_t size{}; //Число вопросов
	in >> size; //Считывает число вопросов
	obj.questions.clear();
	while (size) {
		Q_Cost temp{}; 
		in >> temp; //Считывает вопрос
		obj.questions.push_back(temp); //Заносит ответ в список вопросов
		--size;
	}
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.def_path); //Чтение пути к файлу с описаниями личности
	getline(in, obj.answers_path); //Чтение пути к файлу с ответами
	return in;
}

void PersTest::getPersonDef(){ //Ввод описания личности пользователя из файла в соответствии с набранными им балами по тестам
	File txt(def_path); //Инициализация объекта файла
	txt.open_in(); //Открывает входной файловый поток
	string temp{}; //Строка для чтения файла по строкам
	int file_sum{}; //Число из файла для сравнения с суммой по баллам пользователя
	bool flag{}; //Флаг для определения строк с суммами баллов по тесту
	
	do {
		if (!txt.in()) //Если конец файла
			break;
		txt.readLine(temp); //Считывает строку
		if (temp[0]>='0' && temp[0]<='9')
			flag = true; //Если эта строка число
		if (!flag) //Если эта строка не число
			person_def.push_back(temp); ///Заносит строку в список с описанием личности пользователя
		else { //Если строка - число
			std::istringstream iss(temp, std::istringstream::in);
			iss >> file_sum; //Перевод строки с числом в целочисленный тип
			if (sum > file_sum) { //Если чисо в файле больше суммы пользователя
				break; //То берется текущее описание личности
			}
			person_def.clear(); //Иначе очищается список
			flag = false; //Считывание из файла продолжается
		}
	} while (!flag);
}

void PersTest::putAnswers(){ //Запись ответов пользователя в файл
	File txt(answers_path); //Инициализация объекта файла
	txt.open_out(); //Открытие выходного потока файла
	txt.write(sum, '|'); //Запись суммы баллов пользователя
	std::vector<size_t>::iterator it = user_answers.begin();
	while(it != user_answers.end()) {
		txt.write(*it, '|'); //Последовательная запись ответов пользователя в файл
		++it;
	}
}

void PersTest::getAnswers(){ //Чтение ответов пользователя из файла
	File txt(answers_path); //Инициализация объекта файла
	txt.open_in(); //Открытие входного потока файла
	txt.read(sum); //Чтение суммы баллов пользователя из файла
	txt.getFin().get();
	size_t temp{}; //temp - ответ пользователя
	while (txt.in()) {
		txt.read(temp); //Чтение ответа пользователя из файла
		user_answers.push_back(temp); //Внесение ответа пользователя в вектор
		txt.getFin().get();
	}
}

string PersTest::getPath() { //Возвращает путь к файлу с личностными тестами
	return path;
}