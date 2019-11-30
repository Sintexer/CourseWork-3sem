#pragma once
#include "Tree.h"
#include "MathTest.h"


template<typename Ty>
class Interface
{
private:
	Tree<Ty> tr_tests{};
public:
	void init();
	void show();
	void chooseTest(size_t n);
};

template<typename Ty>
inline void Interface<Ty>::init()
{
	Ty mt;
	mt.setName("Простые математические операции");
	mt.setDefinition("//В этом тесте проверяются ваши знания по сложению, вычитанию и умножению натуральных чисел");
	Q_OneAns qs;
	qs.setQuestionDef("321-123=?");
	qs.addAnswer("278");
	qs.addAnswer("298");
	qs.addAnswer("300");
	qs.addAnswer("-298");
	qs.addAnswer("-278");
	qs.setCorrectAns(2);
	mt.addQuestion(qs);
	Q_OneAns qst;
	qst.setQuestionDef("22*3=?");
	qst.addAnswer("66");
	qst.addAnswer("222222");
	qst.addAnswer("62");
	qst.addAnswer("-36");
	qst.addAnswer("268");
	qst.setCorrectAns(1);
	mt.addQuestion(qst);
	tr_tests.insert(mt);

	Ty mt1;
	mt.setName("Операции над дробными числами");
	mt.setDefinition("//В этом тесте проверяются ваши знания по сложению, вычитанию и умножению дробных чисеел");
	Q_OneAns qs1;
	qs1.setQuestionDef("1.23423*2=?");
	qs1.addAnswer("2.46423");
	qs1.addAnswer("1.23423");
	qs1.addAnswer("2.46846");
	qs1.addAnswer("2.46783");
	qs1.setCorrectAns(3);
	mt1.addQuestion(qs1);
	tr_tests.insert(mt);

}

template<typename Ty>
inline void Interface<Ty>::show()
{
	typename Tree<Ty>::iterator it = tr_tests.begin();
	for (size_t i{1}; it != tr_tests.end(); ++it, ++i)
		cout << i << ": " <<  *it << endl;
}

template<typename Ty>
inline void Interface<Ty>::chooseTest(size_t n)
{
	typename Tree<Ty>::iterator it = tr_tests.begin();
	it += n-1;
	Ty temp = *it;
	temp.start();
	temp.check();
}
