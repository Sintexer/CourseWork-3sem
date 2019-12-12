#include "TreeAlgorithm.h"
#include <algorithm>//Для std::transform

bool Comparator::operator()(Test& obj1, string sub_str)
{
	string temp_l{}, temp_r{}; //Временные строки

	temp_l = obj1.getName(); //Копируем во временную строку Имя теста
	temp_r = sub_str; //Копируем во временную строку введенную пользователем подстроку
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower); //Переводит временную строку в нижний регистр
	std::transform(temp_r.begin(), temp_r.end(), temp_r.begin(), tolower); //Переводит временную строку в нижний регистр

	if (temp_l.find(temp_r) != string::npos) //Ищет введенную пользователем подстроку в Имени теста
		return true; //Если Имя содержит подстроку - функция возвращает true

	temp_l = obj1.getDefinition(); //Заносит определение теста во временную подстроку 
	std::transform(temp_l.begin(), temp_l.end(), temp_l.begin(), tolower); //Переводит временную строку в нижний регистр

	if (temp_l.find(temp_r) != string::npos)//Функция ищет введенную пользователем подстроку в Имени теста
		return true;//Если Описание теста содержит подстроку - функция возвращает true
	return false;//Если ни Имя теста, ни его описания не содержат подстроку, то функция возвращает false
}
