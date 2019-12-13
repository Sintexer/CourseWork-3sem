#pragma once
#include "Test.h"

class TestRating :						//���� �� ���������� ������ 
	public Test
{
protected:
	std::list<Q_OneAns> questions;		//������ �������� � ����� ���������� �������
public:

	TestRating() : Test() {};
	~TestRating() = default;

	virtual void start() = 0;			//������ �����
	virtual void check() = 0;			//�������� � ����� ����������
};

