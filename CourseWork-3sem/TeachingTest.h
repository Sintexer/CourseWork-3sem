#pragma once
#include "Test.h"
class TeachingTest :
	public Test
{
protected:
	std::list<string> theory;
	std::vector<size_t> user_answers;
	std::string theory_path{};
	std::list<Q_OneAns> questions;
	std::string path{ "TeachingTests.txt" };
	
public:
	TeachingTest() : Test() {};
	~TeachingTest() = default;

	void AddUserAns(size_t ans);
	void addQuestion(Q_OneAns qoa);
	void addTheor(string theor);
	void setTheoryPath(string path);
	void MakeTable();

	virtual void start();
	bool startTheory();
	virtual void check();
	virtual void result();

	string getTheoryPath();
	string getPath();

	void readTheory();

	//friend std::ostream& operator<< (std::ostream& out, TeachingTest& obj);
	friend std::istream& operator>> (std::istream& in, TeachingTest& obj);
	bool putTheory();
	bool putAnswers();
	bool getAnswers();
	
};

