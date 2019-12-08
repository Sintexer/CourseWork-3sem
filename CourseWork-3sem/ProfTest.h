#pragma once
#include "TestDef.h"
class ProfTest :
	public TestDef
{
protected:
	std::vector<int> sum{};
	int sz{};
	std::string path{ "ProfessionTests.txt" };
	std::vector<int> relative{};
	std::vector<int> user_answers{};
public:

	ProfTest() : TestDef() {};
	~ProfTest() = default;

	//void MakeTable();

	virtual void start();
	virtual void check();
	void result();
	void getPersonDef();

	//virtual void result();
	//virtual void continue();

	//friend std::ostream& operator<< (std::ostream& out, ProfTest& obj);
	friend std::istream& operator>> (std::istream& in, ProfTest& obj);
	bool putAnswers();
	bool getAnswers();
	string getPath();
};

