#pragma once
#include "TestRating.h"
#include "File.h"

class MathTest :
	public TestRating
{

protected:
	std::vector<size_t> user_answers;
	std::wstring path{L"MathTests.txt"};
public:

	MathTest() : TestRating() {};
	~MathTest() = default;

	void AddUserAns(size_t ans);
	void MakeTable();

	virtual void start();
	virtual void check();
	virtual void result();
	//virtual void continue();

	bool writeFile(TextFile& txt);
	bool putAnswers();
	bool readFile(TextFile& txt);
	bool getAnswers();
	wstring getPath();
};