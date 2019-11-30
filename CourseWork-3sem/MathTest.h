#pragma once
#include "TestRating.h"
class MathTest :
	public TestRating
{

protected:
	std::vector<size_t> user_answers;

public:

	MathTest() : TestRating() {};
	~MathTest() = default;

	void AddUserAns(size_t ans);

	virtual void start();
	virtual void check();
	//virtual void continue();
};