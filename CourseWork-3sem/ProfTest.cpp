#include "ProfTest.h"

int findMaxInVect(std::vector<int>& vc) { //Поиск максимального числа в векторе
	int max{}; //Предыдущий максимум
	int index{}; //Индекс максимального элемента
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] > max) { //Если текущий элемент вектора больше максимального
			index = counter; //Индекс максмального равен индексу текущего
			max = vc[counter]; //Максимум равен текущему элементу
		}
	}
	return index; //Возвращает индекс максимума
}

int finMaxInVectLessThan(std::vector<int>& vc, int prev_max) { //Поиск максимального числа в векторе, который меньше элемента по переданному индексу
	int prev{}; //Предыдущий максимум
	int index{}; //Индекс максимального элемента
	for (size_t counter{}; counter < vc.size(); ++counter) {
		if (vc[counter] >= prev && counter != prev_max && vc[counter] <= vc[prev_max]) { //Если текущий элемент вектора больше максимального и меньше элемента по переданному индексу
			prev = vc[counter]; //Индекс максмального равен индексу текущего
			index = counter; //Максимум равен текущему элементу
		}
	}
	return index; //Возвращает индекс максимума
}

void ProfTest::start(){ //Начало теста
	sum.clear(); //Очистка массива сумм баллов по вопросам
	person_def.clear(); //Очистка описания личности пользователя
	getAnswers();  //Получение ответов пользователя на тест
	if (sum.size()){ //Если пользователь уже проходил тест
		if (user_answers.size() == questions.size()) { //Если пользователь проходил тест до конца
			cout << "Вы уже проходили этот тест\n"
				<< "Желаете пройти его снова?\n"

				<< "\n1: Пройти тест заново\n"
				<< "2: Посмотреть результаты\n"
				<< "3: Удалить предыдущие результаты\n"

				<< "\n0: Назад\n" << endl;
			size_t answer{}; //Ввод пользователя
			inputSafe(cin, answer, 0, 3); //Безопасный ввод в диапазоне от 0 до 3
			switch (answer){
			case 1:
				user_answers.clear(); //Очистка вектора ответов пользователя
				sum.clear(); //Очистка массива сумм баллов
				sum.resize(sz); //Перерасчет размера вектора сумм
				system("cls");
				break;
			case 2:
				getPersonDef(); //Получение описания пользователя из файйла в соответствии с набранными баллами
				system("cls");
				result(); //Вывод результата
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
				system("cls"); //Тест продолжается с вопроса, на котором пользователь прервал тест
				break;
			case 2:
				user_answers.clear(); //Очистка предыдущих ответов пользователя
				sum.clear(); //Очистка массива сумм баллов
				sum.resize(sz); //Перерасчет размера вектора сумм
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
		sum.resize(sz); //Перерасчет размера вектора сумм
	cout << name << "\n" << endl; //Вывод имени теста
	cout << test_def << "\n" << endl; //Вывод описания теста
	system("pause");
	system("cls");
	size_t answer{}, counter{ user_answers.size() + 1 }; //answer для ввода пользователя, counter - номер текущего вопроса
	list<Q_Cost>::iterator it = questions.begin();
	size_t st{};
	while (st++<user_answers.size())
		++it; //Переход к вопросу, на котором пользователь остановился в прошлый раз
	while (it != questions.end()) {
		system("cls");
		cout << "Вопрос " << counter << " из " << questions.size() << endl; //Вывод номера текущего вопроса
		static_cast<Q_Cost>(*it).ask(); //Вывод вопроса и вариантов ответа на него
		cout << "\n" << dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1
			<< ": Прервать тест\n" << endl;
		cout << "0: Назад" << endl;
		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1); //Безопасный ввод в диапазоне
		if (answer == 0) { //Если пользователь выбрал "Назад"
			if (it == questions.begin()) //Если это был первый вопрос
				return; //Выход в меню
			--it; //Переход к предыдущему вопросу 
			--counter; //Декремент номера вопроса
			sum[relative[user_answers.size()-1]-1] -= dynamic_cast<Q_Cost&>(*it).getCost(user_answers.back()); //Вычитание из соответствующей суммы балла за предыдущий вопрос
			user_answers.pop_back(); //Удаление предыдущего ответа пользователя из вектора
			continue;
		}
		if (answer == dynamic_cast<Q_Cost&>(*it).getAnswersSize() + 1) { //Если пользователь выбрал "Прервать тест"
			system("cls");
			if (user_answers.size()) { //Если пользователь ответил хотя бы на один вопрос
				cout << "Желаете сохранить ваш результат?\n"
					<< "1: Да\n"
					<< "2: Нет\n" << endl
					<< "0: Назад" << endl;
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
		sum[relative[user_answers.back()]-1] += dynamic_cast<Q_Cost&>(*it).getCost(answer); //Добавление баллов за ответ на вопрос в соответствующую сумму
		++it; //Переход к следующему вопросу
		++counter; //Инкремент номера вопроса
	}
	system("cls");
	check(); //Проверка ответов пользователя
}

void ProfTest::check(){ //Проверка ответов пользователя
	result(); //Вывод подходящих профессий
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

void ProfTest::result(){ //Результат по тесту
	getPersonDef(); //Получение профессий из файла
	list<string> temp{}; //Список профессий
	string def{ "Вы наиболее склонны к предмету " }; //Наибольшпя склонность
	int index = findMaxInVect(sum); //Находит индекс максимальной суммы в векторе
	int new_index = index; //Хранит индекс предыдущего максимума
	int te = index; //Хранит предыдущий индекс
	std::list<string>::iterator it = person_def.begin();
	while (index) { //Переход к предмету, соответствующего сумме
		++it;
		--index;
	}
	def += *it; //Запись наибольшей склонности в строку
	def += ". Остальные склонности в порядке убывания:\n";
	temp.push_back(def); //Внесение наибольшей склонности в список с проф ориентацией
	size_t size = sum.size() - 1; //Число остальных предметов
	while (size) {
		new_index = finMaxInVectLessThan(sum, te); //Поиск элемента в векторе меньше предыдущего
		it = person_def.begin();
		te = new_index; //Сохранение индекса
		while (new_index) { //Переход к нужной строке
			++it;
			--new_index;
		}
		temp.push_back(*it); //Внесение строки в описание
		--size;
	}
	person_def.clear(); //Очистка списка строк с описанием личности
	it = temp.begin();
	while (it != temp.end()) { //Перенос строк из временного массива в массив с описанием личности
		person_def.push_back(*it);
		++it;
	}
	putPersonDef(); //Вывод описания личности
}

std::istream& operator>>(std::istream& in, ProfTest& obj){ //Считывает тест из потока
	if (in.eof()) //Если поток пуст
		return in; //Конец чтения
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.name); //Чтение имени теста
	getline(in, obj.test_def); //Чтение описания теста
	size_t size{}; //Временная переменная
	int temp{}; //Временная переменная
	in >> size; //Чтение числа сумм
	obj.relative.clear(); //Очистка вектора отношений между вопросом и суммой
	obj.sum.clear(); //Очистка вектора сумм
	obj.sz = size; //Установка числа сумм
	in >> size; //Чтение числа вопросов
	obj.questions.clear(); //Очистка вектора вопросов
	while (size--) {
		in >> temp; //Чтение номера суммы, к которой относится вопрос
		obj.relative.push_back(temp); //Внесение номера суммы в массив отношений
	}
	in >> size; //Чтение числа вопросов 
	while (size) {
		Q_Cost temp{};
		in >> temp; //Чтение вопроса
		obj.questions.push_back(temp); //Внесение вопроса в массив
		--size;
	}
	while (in.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.def_path); //Чтение пути к файлу с описаниями личности
	getline(in, obj.answers_path); //Чтение пути к файлу с ответами
	return in;
}

void ProfTest::getPersonDef(){ //Ввод описания личности пользователя из файла в соответствии с набранными им балами по тестам
	File txt(def_path); //Инициализация объекта файла
	txt.open_in(); //Открывает входной файловый поток
	string temp{}; //Строка для чтения файла по строкам
	while (txt.in()) { //Пока есть строки в файле
		txt.readLine(temp); //Считывание строки
		person_def.push_back(temp); //Внесение строки в список с описанием личности
	}
}

void ProfTest::putAnswers(){ //Запись ответов пользователя в файл
	File txt(answers_path); //Инициализация объекта файла
	txt.open_out(); //Открытие выходного потока файла
	txt.write(sum.size()); //Запись числа сумм баллов пользователя
	std::vector<int>::iterator it = sum.begin();
	while (it != sum.end()) { //Последовательная запись сумм
		txt.write(*it);
		++it;
	}
	txt.write(user_answers.size()); //Запись числа ответов пользователя
	it = user_answers.begin();
	while (it != user_answers.end()) {
		txt.write(*it); //Последовательная запись ответов пользователя в файл
		++it;
	}
}

void ProfTest::getAnswers(){ //Чтение ответов пользователя из файла
	File txt(answers_path); //Инициализация объекта файла
	txt.open_in(); //Открытие входного потока файла
	int size{}, temp{}; //size - число сумм, temp - переменная для чтения чисел
	txt.read(size); //Чтение числа сумм
	sum.clear();
	while (size) {
		txt.read(temp); //Чтение суммы
		sum.push_back(temp); //Внесение суммы в вектор сумм
		--size;
	}
	txt.read(size); //Чтение числа ответов
	while (size) {
		txt.read(temp); //Чтение ответа пользователя на вопрос
		user_answers.push_back(temp); //Внесение ответа пользователя в вектор вопросов
		--size;
	}
}

string ProfTest::getPath(){ //Возвращает путь к файлу с личностными тестами
	return path;
}