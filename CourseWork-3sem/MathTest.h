#pragma once
#include "TestRating.h"
#include "File.h"

class MathTest :
	public TestRating
{

protected:
	std::vector<size_t> user_answers;
	std::string path{"MathTests.txt"};
public:

	MathTest() : TestRating() {};
	~MathTest() = default;

	void AddUserAns(size_t ans);
	void MakeTable();

	virtual void start();
	virtual void check();
	virtual void result();

	//friend std::ostream& operator<< (std::ostream& out, MathTest& obj);
	friend std::istream& operator>> (std::istream& in, MathTest& obj);
	bool getAnswers();
	bool putAnswers();
	string getPath();
};