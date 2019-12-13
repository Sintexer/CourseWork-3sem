#include "MostCommonHeaders.h"
#pragma once

class OutputTable {															//Класс таблицы
private:
	std::string head;														//Шапка таблицы
	std::string* strokes;													//Массив строк таблицы
	int* sizes{};															//Массив, в котором хранится и обновляется ширина каждой колонки
	int str_num;															//Число строк
	int col_num;															//Число столбцов
	int size;																//Размер выделенной памяти в массиве строк
	void set_sizes();														//Метод устанавливает ширину каждой колонки в зависимости от самой длинной строки в колонке
public:
	OutputTable() = default;
	explicit OutputTable(std::string str);
	~OutputTable();

	void add_str(std::string ns);											//Добавить строку в таблицу

	friend std::ostream& operator<<(std::ostream& out, OutputTable& tb);	//Оператор вывода таблицы в поток
	void outHead(std::ostream& out);										//Метод выводит шапку в поток
	void outStrokes(std::ostream& out);										//Метод выводит строки таблицы в поток
	void clear();															//Метод очищает все строки и шапку таблицы
	int getSize();															//Возвращает число строк в таблице
};

void makeDelim(const int* sizes_arr, int col_num, std::ostream& out);		//Создает тестовый разделитель строк таблицы типа +-----+-----+---+	