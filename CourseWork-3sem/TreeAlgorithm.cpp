#include "TreeAlgorithm.h"

bool Comparator::operator()(Test& obj1, string sub_str)
{
	string temp_l{}, temp_r{}; //Временные строки	
	temp_l = obj1.getName(); //Заносит имя теста во временную подстроку 
	if (temp_l.find(sub_str) != string::npos) //Ищет введенную пользователем подстроку в Имени теста
		return true; //Если Имя содержит подстроку - функция возвращает true
	temp_l = obj1.getDefinition(); //Заносит определение теста во временную подстроку 

	if (temp_l.find(sub_str) != string::npos)//Функция ищет введенную пользователем подстроку в Имени теста
		return true;//Если Описание теста содержит подстроку - функция возвращает true
	return false;//Если ни Имя теста, ни его описания не содержат подстроку, то функция возвращает false
}
