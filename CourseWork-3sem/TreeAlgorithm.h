#pragma once
#include "Test.h"
#include "Tree.h"

class Comparator {
	//Класс компаратора ищет подстроку в имени и описании теста, возвращает true, если строка найдена
public:
	Comparator() = default;
	bool operator()(Test& obj1, string sub_str);
};

template <typename T>
std::list<T> searchBySubstr(Tree<T>& tr, std::string sub_str);
//Поиск в тесте по подстроке
//Ищет переданную строку в названии и описании теста, без учета регистра


template<typename T>
std::list<T> searchBySubstr(Tree<T>& tr, std::string sub_str) {
	Comparator comp;
	list<T> ans;//Лист тестов, которые содержат переданную подстроку
	typename Tree<T>::iterator it;
	it = tr.begin();//Итератор на начало дерева
	for (it; it != tr.end(); ++it) { //Обход всего дерева
		if (comp(*it, sub_str)) { //Если название или имя содержат подстроку
			ans.push_back(*it); //Добавляем тест в список подходящих
		}
	}
	return ans; //Возвращаем список тестов, в названии или описании которых есть введенная подстрока
}