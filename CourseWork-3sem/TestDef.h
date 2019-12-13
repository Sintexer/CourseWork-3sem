#pragma once
#include "Test.h"

class TestDef :						//���� � ��������� ���� ��������� ������������
	public Test
{
protected:
	list<string> person_def{};		//� ���� ������ �������� ������ � ��������� ������������
	list<Q_Cost> questions{};		//���� ������ �������� ������� � ����� ������. ����� - ����� �������� �� ������ �������
	string def_path{};				//���� � ����� � ����������
public:
	TestDef() : Test() {};
	~TestDef() = default;

	void putPersonDef();			//������� �������� ������������ �� �����
	string getDefPath();			//���������� ���� � ����� � ����������

	virtual void start() = 0;		//������ �����
	virtual void check() = 0;		//�������� � ����� ����������
};

