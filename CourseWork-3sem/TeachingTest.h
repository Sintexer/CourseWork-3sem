#pragma once
#include "Test.h"

class TeachingTest :														//��������� ����, ����� �������� �������� ������
	public Test
{
protected:
	std::list<string> theory;												//������ ����� � �������
	std::vector<size_t> user_answers;										//������ ������� ������������
	std::list<Q_OneAns> questions;											//������ �������� � ����� ���������� �������. ����� - ��� ����� ������ �� ������
	std::string path{ "..\\Resources\\Teach\\TeachingTests.txt" };			//���� � ����� � ���������� �������
	std::string theory_path{};												//���� � ����� � ������� �� �����
public:
	TeachingTest() : Test() {};
	~TeachingTest() = default;

	void MakeTable();														//������� ������� � �������� ������������

	virtual void start();													//������ �����
	bool startTheory();														//������ ������ �� �����
	virtual void check();													//��������� ������ ������������ �� ���������� ������� � ������� ���������
	virtual void result();													//������� ��������� ������������
	
	void readTheory();														//����� ��������� ���� ������ �� ����� � �������
	void getAnswers();														//����� �������� ������ ������������ �� ����� � ��������
	void putAnswers();														//����� ������� ������ ������������ � ����
	
	friend std::istream& operator>> (std::istream& in, TeachingTest& obj);	//�������� ����� ����� �� ������

	string getTheoryPath();													//���������� ���� � ����� � �������
	string getPath();														//���������� ���� � ����� � ���������� �������
};

