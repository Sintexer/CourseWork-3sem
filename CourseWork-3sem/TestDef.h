#pragma once
#include "Test.h"

class TestDef : //���� � ��������� ���� ��������� ������������
	public Test
{
protected:
	std::list<string> person_def{};
	//� ���� ������ �������� ������ � ��������� ������������
	std::list<Q_Cost> questions{};
	//���� ������ �������� ������� � ����� ������
	//����� - ��� ����� �������� �� ������ �������
	string def_path{};
	//���� � ����� � ����������
public:
	TestDef() : Test() {};
	~TestDef() = default;

	void putPersonDef();
	//������� �������� ������������ �� ������ �� �������� person_def
	string getDefPath();
	//���������� ���� � ����� � ����������

	virtual void start() = 0;
	//������ �����
	virtual void check() = 0;
	//�������� � ����� ����������
};

