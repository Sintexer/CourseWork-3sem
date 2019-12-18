#include "TreeAlgorithm.h"

bool Comparator::operator()(Test& obj1, string sub_str)
{
	string temp_l{}, temp_r{}; //��������� ������	
	temp_l = obj1.getName(); //������� ��� ����� �� ��������� ��������� 
	if (temp_l.find(sub_str) != string::npos) //���� ��������� ������������� ��������� � ����� �����
		return true; //���� ��� �������� ��������� - ������� ���������� true
	temp_l = obj1.getDefinition(); //������� ����������� ����� �� ��������� ��������� 

	if (temp_l.find(sub_str) != string::npos)//������� ���� ��������� ������������� ��������� � ����� �����
		return true;//���� �������� ����� �������� ��������� - ������� ���������� true
	return false;//���� �� ��� �����, �� ��� �������� �� �������� ���������, �� ������� ���������� false
}
