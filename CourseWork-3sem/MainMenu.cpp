#include "MainMenu.h"
#include "Interface.h"

void MainMenu::init()
{
	size_t answer{};
	do {
		system("cls");

		cout << "Главное меню\n\n"

			<< "Выберите вид тестов:\n"
			<< "1: Психологические тесты\n"
			<< "2: Тесты по предметам обучения\n"
			<< "3: Тесты обучающие\n\n"

			<< "0: Выход" << endl;

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
			cout << "Некорректный ввод, выберите цифру из меню" << endl;
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
		cout << "Тесты по предметам обучения\n\n"

			<< "Выберите предмет:\n"
			<< "1: Математика\n"
			<< "2: Физика\n\n"

			<< "9: Главное меню\n"
			<< "0: Выход" << endl;

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
			cout << "Некорректный ввод, выберите цифру из меню" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;
}
