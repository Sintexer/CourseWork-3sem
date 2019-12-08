#pragma once
#include "TestDef.h"


class PersTest :
	public TestDef
{
protected:
	int sum{};
	std::string path{ "PersonalityTests.txt" };
	
public:

	PersTest() : TestDef() {};
	~PersTest() = default;

	//void MakeTable();

	virtual void start();
	virtual void check();
	void getPersonDef();
	
	//virtual void result();
	//virtual void continue();

	//friend std::ostream& operator<< (std::ostream& out, PersTest& obj);
	friend std::istream& operator>> (std::istream& in, PersTest& obj);
	bool putAnswers();
	bool getAnswers();
	string getPath();
};

