#pragma once
#include "TestDef.h"

class PersTest : //���������� ����
	public TestDef //���� � ��������� ���� ��������� ������������
{
protected:
	int sum{};
	//����� ������ �� ������� ������������
	//��� ����� ������������ ��� ������ �������� ������������ �� ����� � ����������
	//����� �� ������� ������ �������� � �������
	std::vector<size_t> user_answers{};
	//������ ������� ������������
	//����� - ��� ����� �� ������ �������
	std::string path{ "PersonalityTests.txt" };
	//���� � ���������� ������

public:

	PersTest() : TestDef() {};
	~PersTest() = default;

	virtual void start();
	//������ �����
	virtual void check();
	//������� ������ ������������ � ����������� �������� � ������� ���������

	void getPersonDef();
	//����� �������� �������� ������������ �� ����� � ����������
	void putAnswers();
	//����� ������� ������ ������������ � ����
	void getAnswers();
	//����� �������� ������ ������������ �� �����
	friend std::istream& operator>> (std::istream& in, PersTest& obj);
	//�������� ����� ����� �� ������

	string getPath();
	//����� ���������� ���� ����� � ����������� �������
};

