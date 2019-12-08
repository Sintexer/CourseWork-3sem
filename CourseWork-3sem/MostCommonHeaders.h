#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <windows.h>
#include <locale>
#include <iomanip>

//В этом файле Подключенны заголовки, которые подключаются во многи других файлах
//Это помогает сократить время компиляции программы
//Так как заголовки, поключенные здесь, не надо перекомпилировать

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::list;
using std::vector;
using std::cout;
using std::cerr;


template<typename T>//Функция переводит любой тип в строку и возвращает ее
string toStr(T val) {
	std::ostringstream ost;
	ost << val;
	return ost.str();
}