#pragma once
#include "Test.h"
#include "Tree.h"

class Comparator {
	//����� ����������� ���� ��������� � ����� � �������� �����, ���������� true, ���� ������ �������
public:
	Comparator() = default;
	bool operator()(Test& obj1, string sub_str);
};

template <typename T>
std::list<T> searchBySubstr(Tree<T>& tr, std::string sub_str);
//����� � ����� �� ���������
//���� ���������� ������ � �������� � �������� �����, ��� ����� ��������


template<typename T>
std::list<T> searchBySubstr(Tree<T>& tr, std::string sub_str) {
	Comparator comp;
	list<T> ans;//���� ������, ������� �������� ���������� ���������
	typename Tree<T>::iterator it;
	it = tr.begin();//�������� �� ������ ������
	for (it; it != tr.end(); ++it) { //����� ����� ������
		if (comp(*it, sub_str)) { //���� �������� ��� ��� �������� ���������
			ans.push_back(*it); //��������� ���� � ������ ����������
		}
	}
	return ans; //���������� ������ ������, � �������� ��� �������� ������� ���� ��������� ���������
}