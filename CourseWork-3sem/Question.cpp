#include "Question.h"
#include "Exc.h"

//
//Q_OneAns
//

double Q_OneAns::getCorrectAns(){ //Возвращает правильный ответ на вопрос
	return correct_ans;
}

size_t Q_OneAns::getAnswersSize(){ //Возвращает число ответов на вопрос
	return answers.size();
}

void Q_OneAns::ask(){ //Выводит вопрос и варианты ответов на него
	cout << question_def << endl << endl; //Вывод вопроса 
	int counter{ 1 }; //Номер ответа
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl; //Вывод варианта ответа
	}
}

std::istream& operator>>(std::istream& in, Q_OneAns& obj){ //Ввод  вопроса с одним ответом из потока
	while (in.peek() == '\n')//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.question_def); //Ввод вопроса
	in >> obj.correct_ans; //Ввод правильного ответа
	size_t size; //Число ответов
	string temp; //Перемнная для ввода
	in >> size; //Ввод числа вариантов ответов
	while (size) {
		getline(in, temp); //Ввод варианта ответа
		obj.answers.push_back(temp); //Внесение варианта ответа в вектор вариантов ответа
		--size;
	}
	return in;
}

//
//Q_Cost
//

size_t Q_Cost::getAnswersSize() { //Возвращает число ответов на вопрос
	return answers.size();
}

void Q_Cost::ask() { //Выводит вопрос и варианты ответов на него
	cout << question_def << endl << endl; //Вывод вопроса 
	int counter{ 1 }; //Номер ответа
	for (typename std::vector<string>::iterator it = answers.begin(); it != answers.end(); ++it, ++counter) {
		cout << counter << ": " << *it << endl; //Вывод варианта ответа
	}
}

int Q_Cost::getCost(int a) { //Возвращает число баллов за ответ по номеру a
	try {
		if (a<0 || a>(int(costs.size()) - 1)) //Если переданного индекса не существует
			throw Exc("Индекс за границами массива");
		return costs[--a]; //Возвращает цену по индексу a-1
	}
	catch (Exc& err) {
		unpackExc(cerr, err); //Вывод исключения
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
	return 0;
}

std::istream& operator>>(std::istream& in, Q_Cost& obj)
{
	while (in.peek() == '\n')//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	getline(in, obj.question_def); //Ввод вопроса
	size_t size; //Число ответов
	string temp; //Перемнная для ввода
	in >> size;
	while (in.peek() == '\n')//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		in.get();
	obj.answers.clear(); //Очистка вектора вариантов ответа
	while (size) {
		while (in.peek() == '\n')//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
			in.get();
		getline(in, temp); //Ввод варианта ответа
		obj.answers.push_back(temp); //Внесение варианта ответа в вектор вариантов ответа
		--size;
	}
	int temp2; //Для ввода балла
	in >> size; //Ввод размер вектора отношений
	obj.costs.clear(); //Очистка вектора баллов
	while (size) {
		in >> temp2; //Ввод балла
		obj.costs.push_back(temp2); //Внесение балла в вектор
		--size;
	}
	return in;
}

