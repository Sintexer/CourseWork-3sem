#pragma once
#include "Tree.h"
#include "MathTest.h"
#include "File.h"
#include "Exc.h"
#include "TreeAlgorithm.h"
#include <list>

template<typename Ty>
class Interface
{
private:
	Tree<Ty> tr_tests{};
public:
	void init();
	void show();
	bool chooseTest();
};

template<typename Ty>
inline void Interface<Ty>::init()
{
	Ty test;
	File txt(test.getPath());
	txt.open_in();
	while (txt.read(test)) {
		tr_tests.insert(test);
	}
}

template<typename Ty>
inline void Interface<Ty>::show()
{
	typename Tree<Ty>::iterator it = tr_tests.begin();
	for (size_t i{2}; it != tr_tests.end(); ++it, ++i)
		cout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline bool Interface<Ty>::chooseTest()
{
	size_t n;
	do {
		system("cls");
		
		cout << "Выберите номер теста: \n\n"
		    << "1: Поиск по тестам\n" << endl;
		show(); // Выводит имена и описания тестов
		cout << endl << tr_tests.size()+2 <<": Назад" << endl;
		cout <<  "0: Выход" << endl;

		inputSafe(cin, n, 0, tr_tests.size()+2);

		if (n == tr_tests.size() + 2)
			return true; // Если выбрали пункт назад, то возвращаемся к меню

		switch (n) {	
		case 1: {
			system("cls");
			cout << "Введите слова для поиска среди тестов: " << endl;
			string temp{};
			safeStr(cin, temp);
			std::list<Ty> found;
			found = searchBySubstr(tr_tests, temp);
			typename std::list<Ty>::iterator it;
			int counter{1};
			
			if (!found.size()){
				system("cls");
				cout << "По данному запросу ничего не найдено" << endl;
				system("pause");
				break;
			}
			size_t answer{};
			do {
				it = found.begin();
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
				
				inputSafe(cin, answer, 0, found.size()+1);
				system("cls");
				if (!answer)
					return false;
				if (answer == found.size() + 1)
					break;
				counter = answer-1;
				it = found.begin();
				while (counter--)
					++it;
				static_cast<Test&>(*it).start();
				system("pause");
			} while (answer);
			break;
		}
		case 0:
			return false;
		default:
			system("cls");
			typename Tree<Ty>::iterator it = tr_tests.begin();
			it += n - 2;
			Ty temp = *it;
			temp.start();
			system("pause");
			break;
		}
	} while (n);
	return true;;
}
