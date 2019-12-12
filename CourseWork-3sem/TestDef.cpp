#include "TestDef.h"

void TestDef::putPersonDef(){ //Выводит описание личности пользователя на экран
	std::list<string>::iterator it = person_def.begin();
	while (it != person_def.end()) {
		cout << *it << endl;
		++it;
	}
}

string TestDef::getDefPath(){ //Возвращает путь к файлу с описанием
	return def_path;
}
