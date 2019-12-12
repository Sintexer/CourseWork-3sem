#pragma once
#include "Tree.h"
#include "TreeAlgorithm.h"
#include "File.h"

template<typename Ty>
class Interface
{
private:
	Tree<Ty> tr_tests{}; //������, � ������� ��������� �����
public:
	void init(); //����� ��������� �� ����� �����, ���� ����� �������� � �����
	void show(); //������� ���������� ������
	bool chooseTest(); //��������� ������ �����, ���� ������ ����� ������ �� ���������
};

template<typename Ty>
inline void Interface<Ty>::init(){
	Ty test;//��������� ������
	File txt(test.getPath());
	txt.open_in();
	while (txt.read(test)) { //���� ����� ��������� ����� �� �����
		tr_tests.insert(test);
	}
}

template<typename Ty>
inline void Interface<Ty>::show(){
	typename Tree<Ty>::iterator it = tr_tests.begin(); //������ �� ������ � ����� ������
	for (size_t i{2}; it != tr_tests.end(); ++it, ++i)//i - ����� ����� � ����
		cout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline bool Interface<Ty>::chooseTest(){ //���� ������ �����
	size_t answer{};//���������� ��� ����������������� �����
	do {
		system("cls");
		
		cout << "�������� ����� �����: \n\n"
		    << "1: ����� �� ������\n" << endl;
		show(); // ������� ����� � �������� ������
		cout << endl << tr_tests.size()+2 <<": �����" << endl;
		cout <<  "0: �����" << endl;

		inputSafe(cin, answer, 0, tr_tests.size()+2); //����� ����� ����� �� Exc.h

		if (answer == tr_tests.size() + 2)
			return true; // ���� ������� ����� �����, �� ������� � ����

		switch (answer) {	
		case 1: {
			system("cls");
			cout << "������� ����� ��� ������ ����� ������: " << endl;
			string temp{};//������, �� ������� ����� �������������� �����
			safeStr(cin, temp);//����� ����������� ����� ������ �� Exc.h
			std::list<Ty> found;//� ���� ������ �������� �����, ������� �������� ��������� ���������
			found = searchBySubstr(tr_tests, temp);//����� ��������� � ����� � �������� �����, ��� ����� ��������
			typename std::list<Ty>::iterator it;
			int counter{1};//����� ����� � ������, ������� ��������� �� �����
			
			if (!found.size()){//���� ������ �� �������
				system("cls");
				cout << "�� ������� ������� ������ �� �������" << endl;
				system("pause");
				break;
			}
			size_t answer{};//���������� ��� ����������������� �����
			do {
				it = found.begin();//�������� �� ������ ������ ������, ������� �������� ���������
				counter = 1;
				system("cls");
				while (it != found.end()) {
					cout << counter << ": " << *it << endl;
					++it;
					++counter;
				}
				cout << endl << found.size() + 1 << ": �����\n"
					<< "0: �����\n" << endl;
				cout << "�������� ���� �� ���������: \n" << endl;
				
				inputSafe(cin, answer, 0, found.size()+1);//����� ����� ����� �� Exc.h
				system("cls");
				if (!answer)//���� ������������ ������ ����� "�����"
					return false; //����� �� ���������
				if (answer == found.size() + 1)//���� ������� ����� "�����"
					break;
				counter = answer-1;//���� ������������ ������ ���� �� ������
				it = found.begin();
				while (counter--)//����������� ��������� �� ������ ���� � ������
					++it;
				static_cast<Test&>(*it).start();//������ �����
				system("pause");
			} while (answer);
			break;
		}
		case 0:
			return false;//����� �� ���������
		default:
			system("cls");//���� ������������ ������ ���� �� ������
			typename Tree<Ty>::iterator it = tr_tests.begin();
			it += answer - 2;//������� ��������� �� ���� �� ������
			Ty temp = *it;
			temp.start();//������ �����
			system("pause");
			break;
		}
	} while (answer);
	return true;//����� � ����
}
