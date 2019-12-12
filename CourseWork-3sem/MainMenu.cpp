#include "MainMenu.h"
#include "Interface.h"
#include "PhysTest.h"
#include "MathTest.h"
#include "PersonalityTest.h"
#include "ProfTest.h"
#include "TeachingTest.h"

void MainMenu::init() //����� ������ ���� �� ����� ������������ � ������ � ���
{
	size_t answer{}; //���������� ��� ����� ������������
	do {
		system("cls");
		cout << "������� ����\n\n"

			<< "�������� ��� ������:\n"
			<< "1: ��������������� �����\n"
			<< "2: ����� �� ��������� ��������\n"
			<< "3: ����� ���������\n\n"

			<< "0: �����" << endl;
		inputSafe(cin, answer, 0, 3); //����� ����������� ����� ����� � ���������
		switch (answer){
		case 1:
			if (!psychoTestMenu()) //���� ��������������� ������, ������ false, ���� ������������ ����� �����
				return; //����� �� ���� 
			break;
		case 2:
			if (!ratingTestMenu()) //���� ������ ���������� ������, ������ false, ���� ������������ ����� �����
				return; //����� �� ���� 
			break;
		case 3:
			if (!teachingTestMenu()) //���� ��������� ������, ������ false, ���� ������������ ����� �����
				return; //����� �� ���� 
			break;
		case 0:
			return;//����� �� ���������
		default:
			cout << "������������ ����, �������� ����� �� ����\n" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
}

bool MainMenu::psychoTestMenu()
{
	size_t answer{};//���������� ��� ����� ������������
	do {
		system("cls");
		cout << "��������������� �����\n\n"

			<< "�������� ��� ������:\n"
			<< "1: ����������\n"
			<< "2: ����� �� ���� �����������\n\n"

			<< "3: ������� ����\n"
			<< "0: �����" << endl;
		inputSafe(cin, answer, 0, 3);//����� ����������� ����� ����� � ���������
		switch (answer){
		case 1: {
			Interface<PersTest> inter;//������������� ���������� ���������� ������
			inter.init(); //������ ����� �� ����� � ������
			if (!inter.chooseTest()) //������ false, ���� ������������ ����� ����� �� ���������
				return false;
			break;
		}
		case 2: {
			Interface<ProfTest> inter;//������������� ���������� ������ �� ���� �����������
			inter.init(); //������ ����� �� ����� � ������
			if (!inter.chooseTest()) //������ false, ���� ������������ ����� ����� �� ���������
				return false;
		}
		case 3:
			return true; //������� � ������� ����
			break;
		case 0:
			return false; //����� �� ���������
			break;
		default:
			cout << "������������ ����, �������� ����� �� ����" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;//����� �� ���������
}

bool MainMenu::ratingTestMenu()
{
	size_t answer{};//���������� ��� ����� ������������
	do {
		system("cls");
		cout << "����� �� ��������� ��������\n\n"

			<< "�������� �������:\n"
			<< "1: ����������\n"
			<< "2: ������\n\n"

			<< "3: ������� ����\n"
			<< "0: �����" << endl;
		inputSafe(cin, answer, 0, 3);//����� ����������� ����� ����� � ���������
		switch (answer){
		case 1: {
			Interface<MathTest> inter; //������������� ���������� ������ �� ����������
			inter.init(); //������ ����� �� ����� � ������
			if (!inter.chooseTest()) //������ false, ���� ������������ ����� ����� �� ���������
				return false;
			break;
		}
		case 2: {
			Interface<PhysTest> inter;
			inter.init(); //������������� ���������� ������ �� ������
			if (!inter.chooseTest()) //������ false, ���� ������������ ����� ����� �� ���������
				return false;//����� �� ���������
			break;
		}
		case 3:
			return true;//������� � ������� ����
		case 0:
			return false;//����� �� ���������
		default:
			cout << "������������ ����, �������� ����� �� ����" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;//����� �� ���������
}

bool MainMenu::teachingTestMenu()
{
		Interface<TeachingTest> inter;
		inter.init(); //������ ����� �� ����� � ������
		if (!inter.chooseTest()) //������ false, ���� ������������ ����� ����� �� ���������
			return false;
		return true;//������� � ������� ����
}