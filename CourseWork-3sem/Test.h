#pragma once
#include "MostCommonHeaders.h"
#include "Question.h"
#include <list>

class Test
{
protected:
	std::wstring name{};
	//Название теста

	std::wstring test_def{};
	//Описание теста

	wstring answers_path{};
public:
	Test() = default;
	Test(std::wstring test_name) : name(test_name) {};
	~Test() = default;

	void setName(wstring test_name);
	void setDefinition(wstring definition);
	void setAnswersPath(wstring path);
	//void setQstAmount(size_t n);

	virtual void start() = 0;
	virtual void check() = 0;

	bool operator>(Test& another_test);
	bool operator<(Test& another_test);
	bool operator==(Test& another_test);
	bool operator!=(Test& another_test);

	friend std::wostream& operator<<(std::wostream& out, Test& test);

	wstring getName();	
	wstring getDefinition();
	wstring getAnswersPath();
	//size_t getQstQmount();
};

