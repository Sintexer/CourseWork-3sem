#pragma once
#include "TestRating.h"

class PhysTest : //���� �� ������
	public TestRating //���� �� ���������� ������
{
protected:
	std::vector<double> user_answers;  //������ ������ ������ ������������. ����� - ����� ������� double
	std::string path{ "..\\Resources\\Phys\\PhysTests.txt" }; //���� � ����� � ������� �� ������
public:

	PhysTest() : TestRating() {};
	~PhysTest() = default;

	void MakeTable(); //������� ������� � �������� ������������

	virtual void start(); //������ �����
	virtual void check(); //������� � ��������� ���������
	virtual void result(); //������� ��������� ������������

	void getAnswers(); //����� �������� ������ ������������ �� ����� � ��������, ���� ����� � �������� �������� � ����� � ������
	void putAnswers(); //����� ������� ������ ������������ � ����
	friend std::istream& operator>> (std::istream& in, PhysTest& obj); //�������� ����� ����� �� ������
	
	string getPath(); //����� ���������� ���� ����� � �������
};

template<typename T>//������� ��������� ����� ��� � ������ � ���������� ��
string toStr(T val) {
	std::ostringstream ost;
	ost << val;
	return ost.str();
}