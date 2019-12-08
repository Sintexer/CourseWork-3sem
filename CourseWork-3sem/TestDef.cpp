#include "TestDef.h"


void TestDef::addQst(Q_Cost qst)
{
	questions.push_back(qst);
}


void TestDef::putPersonDef()
{
	std::list<string>::iterator it = person_def.begin();
	while (it != person_def.end()) {
		cout << *it << endl;
		++it;
	}
}

void TestDef::setDefPath(string path)
{
	def_path = path;
}

string TestDef::getDefPath()
{
	return def_path;
}
