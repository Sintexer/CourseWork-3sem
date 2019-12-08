#include "MostCommonHeaders.h"
#pragma once

class OutputTable { //Класс таблицы
private:
	std::string head;
	std::string* strokes;
	int* sizes{};
	int str_num;
	int col_num;
	int size;

	void set_sizes(); //set size_t size for each column according to the longest str in column
public:
	OutputTable() = default;
	explicit OutputTable(std::string str);
	~OutputTable();

	void add_str(std::string ns);
	void setHead(std::string hd);

	friend std::ostream& operator<<(std::ostream& out, OutputTable& tb);

	void outHead(std::ostream& out);
	void outStrokes(std::ostream& out);
	void clear();
	int getSize();
};

void makeDelim(const int* sizes_arr, int col_num, std::ostream& out);