#pragma once
#include "Tree.h"
#include "TreeAlgorithm.h"
#include "File.h"

template<typename Ty>
class Interface
{
private:
	Tree<Ty> tr_tests{}; //Дерево, в которое заносятся тесты
public:
	void init(); //Метод считывает из файла тесты, путь файла хранится в тесте
	void show(); //Выводит содержимое дерева
	bool chooseTest(); //Интерфейс выбора теста, либо поиска среди тестов по подстроке
};

template<typename Ty>
inline void Interface<Ty>::init(){
	Ty test;//Временный объект
	File txt(test.getPath());
	txt.open_in();
	while (txt.read(test)) { //Пока можно считывать тесты из файла
		tr_tests.insert(test);
	}
}

template<typename Ty>
inline void Interface<Ty>::show(){
	typename Tree<Ty>::iterator it = tr_tests.begin(); //Проход по дереву и вывод тестов
	for (size_t i{2}; it != tr_tests.end(); ++it, ++i)//i - Номер теста в меню
		cout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline bool Interface<Ty>::chooseTest(){ //Меню выбора теста
	size_t answer{};//Переменная для пользовательского ввода
	do {
		system("cls");
		
		cout << "Выберите номер теста: \n\n"
		    << "1: Поиск по тестам\n" << endl;
		show(); // Выводит имена и описания тестов
		cout << endl << tr_tests.size()+2 <<": Назад" << endl;
		cout <<  "0: Выход" << endl;

		inputSafe(cin, answer, 0, tr_tests.size()+2); //Метод ввода числа из Exc.h

		if (answer == tr_tests.size() + 2)
			return true; // Если выбрали пункт назад, то возврат в меню

		switch (answer) {	
		case 1: {
			system("cls");
			cout << "Введите слова для поиска среди тестов: " << endl;
			string temp{};//Строка, по которой будет осуществляться поиск
			safeStr(cin, temp);//Метод безопасного ввода строки из Exc.h
			std::list<Ty> found;//В этом списке хранятся тесты, которые содержат введенную подстроку
			found = searchBySubstr(tr_tests, temp);//Поиск подстроки в имени и описании теста, без учета регистра
			typename std::list<Ty>::iterator it;
			int counter{1};//Номер теста в списке, который выводится на экран
			
			if (!found.size()){//Если ничего не найдено
				system("cls");
				cout << "По данному запросу ничего не найдено" << endl;
				system("pause");
				break;
			}
			size_t answer{};//Переменная для пользовательского ввода
			do {
				it = found.begin();//Итератор на начало списка тестов, которые содержат подстроку
				counter = 1;
				system("cls");
				while (it != found.end()) {
					cout << counter << ": " << *it << endl;
					++it;
					++counter;
				}
				cout << endl << found.size() + 1 << ": Назад\n"
					<< "0: Выход\n" << endl;
				cout << "Выберите тест из найденных: \n" << endl;
				
				inputSafe(cin, answer, 0, found.size()+1);//Метод ввода числа из Exc.h
				system("cls");
				if (!answer)//Если пользователь выбрал пункт "Выход"
					return false; //Выход из программы
				if (answer == found.size() + 1)//Если выбрали пункт "Назад"
					break;
				counter = answer-1;//Если пользователь выбрал тест из списка
				it = found.begin();
				while (counter--)//Перемещение итератора на нужный тест в списке
					++it;
				static_cast<Test&>(*it).start();//Запуск теста
				system("pause");
			} while (answer);
			break;
		}
		case 0:
			return false;//Выход из программы
		default:
			system("cls");//Если пользователь выбрал тест из списка
			typename Tree<Ty>::iterator it = tr_tests.begin();
			it += answer - 2;//Перенос итератора на тест из дерева
			Ty temp = *it;
			temp.start();//Запуск теста
			system("pause");
			break;
		}
	} while (answer);
	return true;//Выход в меню
}
