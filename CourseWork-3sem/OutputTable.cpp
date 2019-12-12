#include "OutputTable.h"
#include <utility>

int OutputTable::getSize() { //Возвращает число строк
	return str_num;
}

OutputTable::OutputTable(std::string str) : head(str), strokes(nullptr), str_num(0), col_num(1) {
	int pos{};
	int prev{};
	while ((pos = head.find('|', pos + 1)) != std::string::npos)  //Поиск разделителя
		++col_num; //Подсчет колонок в таблице

	sizes = new int[size = col_num]; //Ввыделяем память под массив размеров колонок
	int i{};
	pos = 0; //Позиция на начало строки
	while ((pos = head.find('|', pos + 1)) != std::string::npos){ //Поиск раздеелителя и подсчет ширины колонки
		sizes[i++] = head.substr(prev, pos - prev).length();
		prev = pos;
	}
	sizes[i++] = head.length() - prev;
}

OutputTable::~OutputTable() {
	delete[] strokes;
	delete[] sizes;
}

void OutputTable::add_str(std::string ns) { //Добавляет строку в таблицу
	++str_num; //Инкремент числа строк
	if (size == 0) size = str_num; //Если это первая строка
	if (str_num > size) //Если теперь строк больше, чем под них выделенно памяти
		size *= 2; //Увеличивает размер массива вдвое
	std::string* temp = nullptr; //Массив строк для перевыделения памяти
	if (strokes) { //если есть строки
		temp = new std::string[str_num - 1];
		for (int i = 0; i < str_num - 1; ++i) //Копирует строки во временный массив
			temp[i] = strokes[i];
	}
	delete[] strokes; //Очистка массива строк
	strokes = new std::string[size]; //Перевыделение памяти
	int i{};
	if (temp)
		for (i = 0; i < str_num - 1; ++i)
			strokes[i] = temp[i];
	strokes[i] = std::move(ns); //Перенос памяти в массив строк
	this->set_sizes(); //Перерасчет ширины каждой колонки
}

std::ostream& operator<<(std::ostream& out, OutputTable& tb) { //Выводит таблицу на экран
	if (!tb.str_num) { //Если строк нет
		out << "None";
	}
	else {
		tb.outHead(out); //Вывести шапку
		tb.outStrokes(out); //Вывести строки
	}
	return out << endl;
}

void OutputTable::set_sizes() { //Расчитывает ширину каждой колонки
	int pos{}, prev{};
	for (int i = 0; i < str_num; ++i) {
		prev = 0;
		for (int j = 0; j < col_num; ++j) {
			if ((pos = strokes[i].find('|', prev + 1)) == std::string::npos)
				pos = strokes[i].length();
			if (strokes[i].substr(prev, pos - prev).length() > sizes[j]) //Если ширина колонки больше ширины в массиве
				sizes[j] = strokes[i].substr(prev, pos - prev).length(); //Устанавливает новое значение ширины колонки
			prev = pos;
		}
	}
}

void OutputTable::clear() { //Очистка таблицы
	head.clear(); //Очистка шапки
	delete[] strokes; //Удаление массива строк
	strokes = nullptr;
	delete[] sizes; //Удаление массива размеров
	sizes = nullptr;
	str_num = 0;
	col_num = 1;
	size = 0;

}

void makeDelim(const int* sizes_arr, const int col_num, std::ostream& out) { //Создает строку раздеелитель
	out << "+-";
	for (int i = 0; i < col_num; ++i)
		out << std::string(sizes_arr[i] - 1, '-') + '+';
	out << endl;
}

void OutputTable::outHead(std::ostream& out) { //Выводит шапку таблицы
	makeDelim(sizes, col_num, out); //+---+---+---+
	out << '|';
	int prev{}, pos{}, j{};
	for (j = 0; j < col_num; ++j) {
		if ((pos = head.find('|', prev + 1)) == std::string::npos)
			pos = strokes[j].length();
		out << std::setiosflags(std::ios::left) << setw(sizes[j])
			<< head.substr(prev, pos - prev); //Выводит каждую колонку в соответствии с шириной из массива размеров
		prev = pos;
	}
	out << "|" << endl;
	makeDelim(sizes, col_num, out); //+---+---+---+
}

void OutputTable::outStrokes(std::ostream& out) {  //Выводит строки таблицы
	if (!str_num) //Если строк нет
		return;
	int prev{}, pos{}, j{};
	for (int i = 0; i < str_num; ++i) {
		prev = 0;
		out << "|";
		for (j = 0; j < col_num; ++j) {
			if ((pos = strokes[i].find('|', prev + 1)) == std::string::npos)
				pos = strokes[i].length(); 
			out << std::setiosflags(std::ios::left) << setw(sizes[j])
				<< strokes[i].substr(prev, pos - prev); //Выводит каждую колонку в соответствии с шириной из массива размеров
			prev = pos;
		}
		out << "|" << endl;
		makeDelim(sizes, col_num, out); //+---+---+---+
	}
}