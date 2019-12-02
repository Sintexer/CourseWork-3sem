#include "Test.h"

void Test::setName(wstring test_name)
{
	name = test_name;
}

void Test::setDefinition(wstring definition)
{
	test_def = definition;
}

void Test::setAnswersPath(wstring path)
{
	answers_path = path;
}

//void Test::setQstAmount(size_t n)
//{
//	qst_amount = n;
//}


bool Test::operator>(Test& another_test)
{
	return name>another_test.name;
}

bool Test::operator<(Test& another_test)
{
	return name < another_test.name;
}

bool Test::operator==(Test& another_test)
{
	return (name == another_test.name) && (test_def == another_test.test_def);
}

bool Test::operator!=(Test& another_test)
{
	return !(*this == another_test);
}

wstring Test::getName()
{
	return name;
}

wstring Test::getDefinition()
{
	return test_def;
}

wstring Test::getAnswersPath()
{
	return answers_path;
}

std::wostream& operator<<(std::wostream& out, Test& test)
{
	out << test.getName() << endl << test.getDefinition() << endl;
	return out;
}
