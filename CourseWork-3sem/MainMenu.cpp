#include "MainMenu.h"
#include "Interface.h"

void MainMenu::init()
{
	size_t answer{};
	do {
		system("cls");

		cout << "������� ����\n\n"

			<< "�������� ��� ������:\n"
			<< "1: ��������������� �����\n"
			<< "2: ����� �� ��������� ��������\n"
			<< "3: ����� ���������\n\n"

			<< "0: �����" << endl;

		inputSafe(cin, answer, 0, 3);//

		switch (answer)
		{
		case 1:
			cout << "In dev" << endl;
			system("pause");
			break;
		case 2:
			if (!ratingTestMenu())
				answer = 0;
			break;
		case 0:
			return;
		default:
			cout << "������������ ����, �������� ����� �� ����" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");

}

bool MainMenu::ratingTestMenu()
{
	size_t answer{};
	do {
		system("cls");
		cout << "����� �� ��������� ��������\n\n"

			<< "�������� �������:\n"
			<< "1: ����������\n"
			<< "2: ������\n\n"

			<< "9: ������� ����\n"
			<< "0: �����" << endl;

		inputSafe(cin, answer, 0, 9);//

		switch (answer)
		{
		case 1: {
			Interface<MathTest> inter;
			inter.init();
			inter.show();
			inter.chooseTest(2);
			system("pause");
			break;
		}
		case 2:
			cout << "In dev" << endl;
			system("pause");
			break;
		case 9:
			return true;
			break;
		case 0:
			return false;
			break;
		default:
			cout << "������������ ����, �������� ����� �� ����" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;
}
