#include "MainMenu.h"
#include "Interface.h"
#include "PhysTest.h"
#include "MathTest.h"
#include "PersonalityTest.h"
#include "ProfTest.h"
#include "TeachingTest.h"

void MainMenu::init() //Метод вывода меню на экран пользователя и работы с ним
{
	size_t answer{}; //Переменная для ввода пользователя
	do {
		system("cls");
		cout << "Главное меню\n\n"

			<< "Выберите вид тестов:\n"
			<< "1: Психологические тесты\n"
			<< "2: Тесты по предметам обучения\n"
			<< "3: Тесты обучающие\n\n"

			<< "0: Выход" << endl;
		inputSafe(cin, answer, 0, 3); //Метод безопасного ввода числа в диапазоне
		switch (answer){
		case 1:
			if (!psychoTestMenu()) //Меню психологических тестов, вернет false, если пользователь решил выйти
				return; //Выход из меню 
			break;
		case 2:
			if (!ratingTestMenu()) //Меню тестов оценивания знаний, вернет false, если пользователь решил выйти
				return; //Выход из меню 
			break;
		case 3:
			if (!teachingTestMenu()) //Меню обучающих тестов, вернет false, если пользователь решил выйти
				return; //Выход из меню 
			break;
		case 0:
			return;//Выход из программы
		default:
			cout << "Некорректный ввод, выберите цифру из меню\n" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
}

bool MainMenu::psychoTestMenu()
{
	size_t answer{};//Переменная для ввода пользователя
	do {
		system("cls");
		cout << "Психологические тесты\n\n"

			<< "Выберите вид тестов:\n"
			<< "1: Личностные\n"
			<< "2: Тесты на проф пригодность\n\n"

			<< "3: Главное меню\n"
			<< "0: Выход" << endl;
		inputSafe(cin, answer, 0, 3);//Метод безопасного ввода числа в диапазоне
		switch (answer){
		case 1: {
			Interface<PersTest> inter;//Инициализация интерфейса Личностных тестов
			inter.init(); //Вводит тесты из файла в дерево
			if (!inter.chooseTest()) //Вернет false, если пользователь решил выйти из программы
				return false;
			break;
		}
		case 2: {
			Interface<ProfTest> inter;//Инициализация интерфейса тестов на проф пригодность
			inter.init(); //Вводит тесты из файла в дерево
			if (!inter.chooseTest()) //Вернет false, если пользователь решил выйти из программы
				return false;
		}
		case 3:
			return true; //Возврат в главное меню
			break;
		case 0:
			return false; //Выход из программы
			break;
		default:
			cout << "Некорректный ввод, выберите цифру из меню" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;//Выход из программы
}

bool MainMenu::ratingTestMenu()
{
	size_t answer{};//Переменная для ввода пользователя
	do {
		system("cls");
		cout << "Тесты по предметам обучения\n\n"

			<< "Выберите предмет:\n"
			<< "1: Математика\n"
			<< "2: Физика\n\n"

			<< "3: Главное меню\n"
			<< "0: Выход" << endl;
		inputSafe(cin, answer, 0, 3);//Метод безопасного ввода числа в диапазоне
		switch (answer){
		case 1: {
			Interface<MathTest> inter; //Инициализация интерфейса тестов по математике
			inter.init(); //Вводит тесты из файла в дерево
			if (!inter.chooseTest()) //Вернет false, если пользователь решил выйти из программы
				return false;
			break;
		}
		case 2: {
			Interface<PhysTest> inter;
			inter.init(); //Инициализация интерфейса тестов по физике
			if (!inter.chooseTest()) //Вернет false, если пользователь решил выйти из программы
				return false;//Выход из программы
			break;
		}
		case 3:
			return true;//Возврат в главное меню
		case 0:
			return false;//Выход из программы
		default:
			cout << "Некорректный ввод, выберите цифру из меню" << endl;
			system("pause");
			break;
		}
	} while (answer);
	system("cls");
	return false;//Выход из программы
}

bool MainMenu::teachingTestMenu()
{
		Interface<TeachingTest> inter;
		inter.init(); //Вводит тесты из файла в дерево
		if (!inter.chooseTest()) //Вернет false, если пользователь решил выйти из программы
			return false;
		return true;//Возврат в главное меню
}