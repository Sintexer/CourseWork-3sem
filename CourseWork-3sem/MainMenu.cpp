#include "MainMenu.h"
#include "Interface.h"
#include "PhysTest.h"
#include "PersonalityTest.h"
#include "ProfTest.h"
#include "TeachingTest.h"

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
			if (!psychoTestMenu())
				answer = 0;
			break;
		case 2:
			if (!ratingTestMenu())
				answer = 0;
			break;
		case 3:
			if (!teachingTestMenu())
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

bool MainMenu::psychoTestMenu()
{
	size_t answer{};
	do {
		system("cls");
		cout << "Психологические тесты\n\n"

			<< "Выберите вид тестов:\n"
			<< "1: Личностные\n"
			<< "2: Тесты на проф пригодность\n\n"

			<< "3: Главное меню\n"
			<< "0: Выход" << endl;

		inputSafe(cin, answer, 0, 3);//

		switch (answer)
		{
		case 1: {
			Interface<PersTest> inter;
			inter.init();
			if (!inter.chooseTest())
				return false;
			break;
		}
		case 2: {
			Interface<ProfTest> inter;
			inter.init();
			if (!inter.chooseTest())
				return false;
		}
		case 3:
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

bool MainMenu::ratingTestMenu()
{
	size_t answer{};
	do {
		system("cls");
		cout << "Тесты по предметам обучения\n\n"

			<< "Выберите предмет:\n"
			<< "1: Математика\n"
			<< "2: Физика\n\n"

			<< "3: Главное меню\n"
			<< "0: Выход" << endl;

		inputSafe(cin, answer, 0, 3);//

		switch (answer)
		{
		case 1: {
			Interface<MathTest> inter;
			inter.init();
			if (!inter.chooseTest())
				return false;
			break;
		}
		case 2: {
			Interface<PhysTest> inter;
			inter.init();
			if (!inter.chooseTest())
				return false;
			break;
		}
		case 3:
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

bool MainMenu::teachingTestMenu()
{
		Interface<TeachingTest> inter;
		inter.init();
		if (!inter.chooseTest())
			return false;
		return true;
}