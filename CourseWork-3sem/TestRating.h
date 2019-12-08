#pragma once
#include "Test.h"

class TestRating : //���� �� ���������� ������ 
	public Test
{
protected:
	std::list<Q_OneAns> questions;
	//������ �������� ���� Q_OneAns - � ����� �������
public:

	TestRating() : Test() {};
	~TestRating() = default;

	virtual void start() = 0;
	//������ �����
	virtual void check() = 0;
	//�������� � ����� ����������
};

