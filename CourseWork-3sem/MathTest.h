#pragma once
#include "TestRating.h"
#include "File.h"

class MathTest :
	public TestRating
{

protected:
	std::vector<size_t> user_answers;
	string path{"MathTests.txt"};
public:

	MathTest() : TestRating() {};
	~MathTest() = default;

	void AddUserAns(size_t ans);

	virtual void start();
	virtual void check();
	//virtual void continue();

	bool writeFile(TextFile& txt);
	bool readFile(TextFile& txt);
	string getPath();
};