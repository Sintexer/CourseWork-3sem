#pragma once
#include "Test.h"

class TestRating :
	public Test
{
protected:
	std::list<Q_OneAns> questions;
	//Список вопросов типа Q_OneAns - с одним ответом
public:

	TestRating() : Test() {};
	~TestRating() = default;

	void addQuestion(Q_OneAns qoa);

	virtual void start() = 0;
	virtual void check() = 0;
};

