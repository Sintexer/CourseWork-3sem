#include "Test.h"

void Test::setName(string test_name)
{
	name = test_name;
}

void Test::setDefinition(string definition)
{
	test_def = definition;
}

void Test::setAnswersPath(string path)
{
	answers_path = path;
}


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

string Test::getName()
{
	return name;
}

string Test::getDefinition()
{
	return test_def;
}

string Test::getAnswersPath()
{
	return answers_path;
}

void Test::clearAns()
{
	File txt(answers_path);
	txt.open_out();
}

std::ostream& operator<<(std::ostream& out, Test& test)
{
	out << test.getName() << endl << test.getDefinition() << endl;
	return out;
}
