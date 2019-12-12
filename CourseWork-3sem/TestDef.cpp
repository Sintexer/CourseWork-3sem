#include "TestDef.h"

void TestDef::putPersonDef()
{
	std::list<string>::iterator it = person_def.begin();
	while (it != person_def.end()) {
		cout << *it << endl;
		++it;
	}
}

string TestDef::getDefPath()
{
	return def_path;
}
