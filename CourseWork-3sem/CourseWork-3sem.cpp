//#include "pch.h"
#include "MostCommonHeaders.h"
#include "Test.h"
#include "TestRating.h"
#include "MathTest.h"
#include "MainMenu.h"

int main()
{
	setlocale(LC_ALL, "Russian");
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
}