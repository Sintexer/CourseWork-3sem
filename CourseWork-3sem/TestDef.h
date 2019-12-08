#pragma once
#include "Test.h"
class TestDef :
	public Test
{
protected:
	std::list<string> person_def{};
	std::list<Q_Cost> questions{};
	string def_path{};
	size_t last_question_index{};
public:
	TestDef() : Test() {};
	~TestDef() = default;

	void addQst(Q_Cost qst);
	void putPersonDef();
	void setDefPath(string path);
	string getDefPath();

	virtual void start() = 0;
	virtual void check() = 0;
};

