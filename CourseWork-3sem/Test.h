#pragma once
#include "MostCommonHeaders.h"
#include "Question.h"
#include <list>

class Test
{
protected:
	string name{};
	//Название теста

	string test_def{};
	//Описание теста
public:
	Test() = default;
	Test(string test_name) : name(test_name) {};
	~Test() = default;

	void setName(string test_name);
	void setDefinition(string definition);
	//void setQstAmount(size_t n);

	virtual void start() = 0;
	virtual void check() = 0;

	bool operator>(Test& another_test);
	bool operator<(Test& another_test);
	bool operator==(Test& another_test);
	bool operator!=(Test& another_test);

	friend std::ostream& operator<<(std::ostream& out, Test& test);

	string getName();	
	string getDefinition();
	//size_t getQstQmount();
};

