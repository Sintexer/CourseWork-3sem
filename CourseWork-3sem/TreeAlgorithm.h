#pragma once
#include <iostream>
#include <string>
#include <set>
#include <list>

#include "Tree.h"
#include "Test.h"


class Comparator {
public:
	Comparator() = default;
	bool operator()(Test& obj1, string sub_str);
};

template <typename T>
std::list<T> searchBySubstr(Tree<T>& tr, string sub_str);


template<typename T>
std::list<T> searchBySubstr(Tree<T>& tr, string sub_str)
{
	Comparator comp;
	std::list<T> ans;
	typename Tree<T>::iterator it;
	it = tr.begin();
	for (it; it != tr.end(); ++it) {
		if (comp(*it, sub_str)) {
			ans.push_back(*it);
		}
	}
	return ans;
}

//template<typename Iter>
//size_t size(Iter begin, Iter end)
//{
//	size_t ans{};
//	Iter it = begin;
//	for (it; it != end; ++it)
//		++ans;
//	return(ans);
//}
//
//template<typename T>
//typename Tree<T>::iterator lower_bound(Tree<T>& tree, T& obj) {
//	typename Tree<T>::iterator it = tree.begin();
//	for (it; it != tree.end(); ++it)
//		if (*it > obj)
//			break;
//	return it;
//}

//template<typename T>
//typename Tree<T>::iterator min(Tree<T>& tree)
//{
//	return tree.begin();
//}
//
//template<typename T>
//typename Tree<T>::iterator max(Tree<T>& tree)
//{
//	return tree.rbegin();
//}