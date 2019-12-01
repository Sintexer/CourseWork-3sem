
#include "MostCommonHeaders.h"
#include "Test.h"
#include "TestRating.h"
#include "MathTest.h"
#include "MainMenu.h"
#include "File.h"	


int main()
{
	setlocale(LC_ALL, "Russian");
	TextFile vf(L"MathTest1.txt");
	vf.open_in();


	MainMenu mm;
	mm.init();
	
	
	/*MathTest math;	
	math.setName("Math test");
	math.setDefinition("Common math problems and theory questions");
	Q_OneAns** array = new Q_OneAns*[2];
	array[0] = new Q_OneAns;
	array[1] = new Q_OneAns;
	array[0]->setQuestionDef("2+2=?");
	array[0]->addAnswer("4");
	array[0]->addAnswer("2");
	array[0]->setCorrectAns(1);
	
	array[1]->setQuestionDef("3*3=?");
	array[1]->addAnswer("4");
	array[1]->addAnswer("2");	
	array[1]->addAnswer("9");
	array[1]->setCorrectAns(3);
	math.addQuestion(*array[0]);
	math.addQuestion(*array[1]);
	math.start();
	math.check();*/

	/*Ty mt;
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
	tr_tests.insert(mt);*/
}