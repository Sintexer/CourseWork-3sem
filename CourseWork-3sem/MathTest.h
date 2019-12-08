#pragma once
#include "TestRating.h"
#include "File.h"

class MathTest : //���� �� ����������
	public TestRating //���� �� ���������� ������ 
	
{

protected:
	std::vector<size_t> user_answers;
	//������ ������ ������ ������������
	//����� - ��� ����� �� ������ �������
	std::string path{"MathTests.txt"};
	//���� � ����� � ��������������� �������
public:

	MathTest() : TestRating() {};
	~MathTest() = default;

	void MakeTable();
	//������� ������� � �������� ������������

	virtual void start();
	//������ �����
	virtual void check();
	//������� ������ ������������ � ����������� �������� � ������� ���������
	virtual void result();
	//������� ��������� ������������

	bool getAnswers();
	//����� �������� ������ ������������ �� ����� � ��������, ���� ����� � �������� �������� � ����� � ������
	bool putAnswers();
	//����� ������� ������ ������������ � ����
	friend std::istream& operator>> (std::istream& in, MathTest& obj);
	//�������� ����� ����� �� ������
	
	string getPath();
	//����� ���������� ���� ����� � �������
};