#pragma once
#include "Tree.h"
#include "MathTest.h"
#include "File.h"


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
	TextFile txt(test.getPath());
	txt.open_in();
	while (test.readFile(txt)) {
		
		tr_tests.insert(test);
	}
}

template<typename Ty>
inline void Interface<Ty>::show()
{
	typename Tree<Ty>::iterator it = tr_tests.begin();
	for (size_t i{1}; it != tr_tests.end(); ++it, ++i)
		wcout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline bool Interface<Ty>::chooseTest()
{
	size_t n;
	do {
		system("cls");
		cout << endl << "Выберите номер теста: " << endl;
		show();
		wcout << endl << tr_tests.size()+1 <<L": Назад" << endl;
		wcout <<  L"0: Выход" << endl;
		inputSafe(cin, n, 0, tr_tests.size()+1);
		if (n == tr_tests.size() + 1)
			return true;
		switch (n) {	
		case 0:
			return false;
		default:
			system("cls");
			typename Tree<Ty>::iterator it = tr_tests.begin();
			it += n - 1;
			Ty temp = *it;
			temp.start();
			system("pause");
			break;
		}
	} while (n);
}
