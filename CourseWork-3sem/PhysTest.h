#pragma once
#include "TestRating.h"
class PhysTest :
	public TestRating
{
protected:
	std::vector<double> user_answers;
	std::string path{ "PhysTests.txt" };
public:

	PhysTest() : TestRating() {};
	~PhysTest() = default;

	void AddUserAns(double ans);
	void MakeTable();

	virtual void start();
	virtual void check();
	virtual void result();

	//friend std::ostream& operator<< (std::ostream& out, PhysTest& obj);
	friend std::istream& operator>> (std::istream& in, PhysTest& obj);
	bool putAnswers();
	bool getAnswers();
	string getPath();
};

string toStr(double val);