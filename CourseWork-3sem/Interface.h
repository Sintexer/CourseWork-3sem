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
	void chooseTest();
};

template<typename Ty>
inline void Interface<Ty>::init()
{
	setlocale(LC_ALL, "Russian");
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
		cout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline void Interface<Ty>::chooseTest()
{
	size_t n;
	cout << endl <<  "Выберите номер теста: " << endl;
	inputSafe(cin, n, 1, tr_tests.size());
	typename Tree<Ty>::iterator it = tr_tests.begin();
	it += n-1;
	Ty temp = *it;
	temp.start();
	temp.check();
}
