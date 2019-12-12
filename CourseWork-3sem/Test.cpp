#include "Test.h"

bool Test::operator>(Test& another_test){ //Сравнение тестов по имени
	return name>another_test.name;
}

bool Test::operator<(Test& another_test){ //Сравнение тестов по имени
	return name < another_test.name;
}

bool Test::operator==(Test& another_test){ //Сравнение тестов по имени и описанию
	return (name == another_test.name) && (test_def == another_test.test_def);
}

bool Test::operator!=(Test& another_test){ //Сравнение тестов по имени и описанию
	return !(*this == another_test);
}

string Test::getName(){ //Возвращает имя теста
	return name;
}

string Test::getDefinition(){ //Возвращает описание теста
	return test_def;
}

string Test::getAnswersPath(){ //Возвращает путь к файлу с ответами
	return answers_path;
}

void Test::clearAns(){ //Очищает файл с ответами
	File txt(answers_path);
	txt.open_out();
}

std::ostream& operator<<(std::ostream& out, Test& test){ //Вывод имени и описания теста на экран
	out << test.getName() << endl << test.getDefinition() << endl;
	return out;
}
