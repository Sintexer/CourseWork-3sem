#include "TreeAlgorithm.h"
#include <algorithm>//��� std::transform

bool Comparator::operator()(Test& obj1, string sub_str)
{
	string temp_l{}, temp_r{}; //��������� ������

	temp_l = obj1.getName(); //�������� �� ��������� ������ ��� �����
	temp_r = sub_str; //�������� �� ��������� ������ ��������� ������������� ���������
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower); //��������� ��������� ������ � ������ �������
	std::transform(temp_r.begin(), temp_r.end(), temp_r.begin(), tolower); //��������� ��������� ������ � ������ �������

	if (temp_l.find(temp_r) != string::npos) //���� ��������� ������������� ��������� � ����� �����
		return true; //���� ��� �������� ��������� - ������� ���������� true

	temp_l = obj1.getDefinition(); //������� ����������� ����� �� ��������� ��������� 
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower); //��������� ��������� ������ � ������ �������

	if (temp_l.find(temp_r) != string::npos)//������� ���� ��������� ������������� ��������� � ����� �����
		return true;//���� �������� ����� �������� ��������� - ������� ���������� true
	return false;//���� �� ��� �����, �� ��� �������� �� �������� ���������, �� ������� ���������� false
}
