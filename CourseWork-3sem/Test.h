#pragma once
#include "Question.h"

class Test																//����������� ����� �����, �������� ����� ���� �����, ��������, � ���� � �������
{
protected:
	string name{};														//�������� �����
	string test_def{};													//�������� �����
	string answers_path{};												//���� � ����� � �������� ������������
public:
	Test() = default;
	Test(std::string test_name) : name(test_name) {};
	~Test() = default;

	virtual void start() = 0;											//������ �����
	virtual void check() = 0;											//�������� ����� �� ���������� �������, ������� �������� � �������, � ����� ����������
	void clearAns();													//������� ���� � �������� ������������

	bool operator>(Test& another_test);									//��������� ���������, ��� �������� � ���������
	bool operator<(Test& another_test);									//������������ �� ����� �����
	bool operator==(Test& another_test);								//�������� ��������� ���������� ��� � �������� ������
	bool operator!=(Test& another_test);
	

	friend std::ostream& operator<<(std::ostream& out, Test& test);		//�������� ������ ����� � �������� ������ �����

	string getName();													//����� ���������� ��� �����
	string getDefinition();												//����� ���������� �������� �����
	string getAnswersPath();											//����� ���������� ���� � ������� ������������ �� ����
};

