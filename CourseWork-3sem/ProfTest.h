#pragma once
#include "TestDef.h"

class ProfTest :														//���� �� ���� �����������
	public TestDef														//���� � ��������� ���� ��������� ������������
{
protected:
	std::vector<int> sum{};												/*������ � �������, ������� ��������� ������ �� ������� ������������
																		���� �� ����� �������� � ������� �������.	����� ����� ��������� � ������ ����� ��������� ������� relative
																		������ ������� relative - ��� ����� �������, � ��,
																		��� �������� � ���� ������� - ������ � ������� sum, ���� ����� ��������
																		���� ������ ������������*/
	int sz{};															//� ��� ���������� ��������� ������ ������� sum �� �����
	std::vector<int> relative{};										//������, � ������� �������� ������� � ������� sum, � ������� ��������� �������
	std::vector<int> user_answers{};									//������ ������ ������ ������������. ����� - ��� ����� �� ������ �������
	std::string path{ "..\\Resources\\Prof\\ProfessionTests.txt" };		//���� � ����� � ������� �� ���� �����������
public:
	ProfTest() : TestDef() {};
	~ProfTest() = default;

	virtual void start();												//������ �����
	virtual void check();												//������� � ��������� ���������
	void result();														//������� ��������� ������������
	
	void getPersonDef();												//����� �������� �������� ������������ �� �����
	void getAnswers();													//����� �������� ������ ������������ �� ����� � ��������
	void putAnswers();													//����� ������� ������ ������������ � ����
	friend std::istream& operator>> (std::istream& in, ProfTest& obj);	//�������� ����� ����� �� ������
	
	string getPath();													//����� ���������� ���� ����� � �������
};

