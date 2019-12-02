#include "MostCommonHeaders.h"
#pragma once

class OutputTable {
private:
    std::string head;
    std::string* strokes;
	size_t* sizes{};
    int str_num;
    int col_num;
    size_t size;

    void set_sizes(); //set size_t size for each column according to the longest str in column
public:
	OutputTable() = default;
    explicit OutputTable (std::string str);
    ~OutputTable();

    void add_str(std::string ns);
    void setHead(std::string hd);

    friend std::ostream& operator<<(std::ostream& out, OutputTable& tb);

    void outHead(std::ostream& out);
    void outStrokes(std::ostream& out);
    void clear();
	size_t getSize();
};

void makeDelim(const size_t* sizes_arr, int col_num, std::ostream& out);