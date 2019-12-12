#pragma once
#include "MostCommonHeaders.h"

template <typename T>
class Tree {
private:

	template <typename N>
	class Node {
		// Класс узла, в котором хранится значение шаблонного типа
		// а также два указателя, налево и направо
		// слева храннится елемент, который меньше элемента в узла
		// справа наоборот
	public:
		N value{}; 
		//Значение узла
		Node<N>* left{ nullptr }, * right{ nullptr };
		//Указатели налево и направо
		Node<N>* parent{};
		//Указатель на родителя

		Node() = default;
		Node(T val, Node<T>* lef, Node<T>* rgt, Node<T>* prnt) :value(val), left(lef), right(rgt), parent(prnt) {}
		~Node() {
			delete left, right, parent;
		}
	};

	Node<T>* root;
	// В этой переменной хранится корень дерева

protected:
	// Методы, размещенные в protected части класса,
	// не предназначены для глаз пользователя
	// Производят реализацию удаления, поиска, вставки, извлечения

	void popItem(Node<T>*& tree, T val);
	// Данный метод рекурсивно ищет узел со значением val
	// При нахождении узла вызывает по отношению к нему метод deleteNode
	// Тем самым данный метод производит поиск нужного для удаления узла

	void insertItem(Node<T>*& tree, T newItem, Node<T>* prnt);
	// Данный метод рекурсивно ищет узел со значением newItem
	// Если такой узел существует, то значение не вставляется
	// Если же такого узла нет, то метод остановится на узле со значением nullptr
	// В который можно вставить новое значение, не нарушая структуру дерева поиска

	void extractMostLeft(Node<T>*& node, T& val);
	// Копирует значение самого левого от node узла, а затем удаляет этот самый левый узел
	// Данный метод необходим для удаления узла с двумя наследниками

	void deleteNode(Node<T>*& node);
	// Удалает переданную в метод ноду
	// Обрабатывает 4 ситуации:
	//   1) Нода не имеет наследников
	//   2) Нода имеет только левого наследника
	//   3) Нода имеет только правого наследника
	//   4) Нода имеет 2 наследника
	// Все ситуации, кроме ноера 4 обрабатываются прямо в теле метода
	// Для ситуации 4 используется метод извлечения ноды extractMostLeft

	void nodeAmount(Node<T>*& node, size_t& size);
	// Считает число узлов дерева рекурсивно

	void copyTree(Node<T>* tree, Node<T>*& newTree) const;
	// Копирует все ноды дерева tree в дерево newTree

	virtual void printTree(Node<T>* current, int level = 0);
	// Рекурсивный симметриный вывод дерева в консоль (Дерево лежит боком)

public:
	class iterator {
		friend class Tree;
	private:
		Node<T>* current{};	//Указатель на текущую ноду
	public:
		iterator() : current(nullptr) {};

		const Tree<T>::iterator operator++();
		const Tree<T>::iterator operator++(int);
		const Tree<T>::iterator operator--();
		const Tree<T>::iterator operator--(int);

		void operator+=(int num);
		void operator-=(int num);

		bool operator==(Tree<T>::iterator rht);
		bool operator!=(Tree<T>::iterator rht);

		T& operator*();
	};

	//
	// M
	// E
	// T
	// H
	// O
	// D
	// S
	//

	Tree() : root(nullptr) {}
	Tree(const Tree& tr) : root(std::move(tr.root)) {}
	Tree(T val);
	virtual ~Tree();

	Node<T>*& getRoot();
	virtual bool empty();

	virtual size_t size();// Считает вершины дерева, включая корень

	virtual void insert(T val);
	// Метод вставки значения в дерево
	// Используется protected method insertItem

	virtual void pop(T val); // Ищет значение val в дереве и производит удаление ноду

	virtual void show();

	Tree<T>::iterator begin(); //Возвращает итератор на первый элемент дерева
	Tree<T>::iterator end(); //Возвращает итератор на следующий за последним элемент дерева
	Tree<T>::iterator find(T obj); // Возвращает итератор на вхождение элемента в дерево, Если в дереве элемента нет, то итератор указывает на nullptr

	void destroyTree(Node<T>*& tree); // Очищает все дерево рекурсивно, освобождает память на указатели нод
};

template<typename T>
void Tree<T>::popItem(Node<T>*& tree, T val) {
	if (!tree)
	{//Такой ноды нет
		return;
	}
	else if (val == tree->value)
	{//Необходимый узел найден
		deleteNode(tree);
	}
	//Поиск нужного узла
	else if (val < tree->value)
		popItem(tree->left, val);
	else
		popItem(tree->right, val);
}

template<typename T>
void Tree<T>::insertItem(Node<T>*& tree, T newItem, Node<T>* prnt) {
	if (!tree)
	{//Если найдено нужное место
		tree = new Node<T>(newItem, nullptr, nullptr, prnt);
	}
	else if (newItem == tree->value)
	{//Такая нода уже есть
		return;
	}
	//Поиск нужного места по новый узел
	else if (newItem < tree->value) {
		prnt = tree;
		insertItem(tree->left, newItem, prnt);
	}
	else {
		prnt = tree;	
		insertItem(tree->right, newItem, prnt);
	}
}

template<typename T>
void Tree<T>::extractMostLeft(Tree::Node<T>*& node, T& val) { //Извлекает значение самого левого узла и удаляет его
	if (!node->left)
	{
		val = node->value;
		Node<T>* del = node;
		node = node->right;
		if (node) 
			node->parent = del->parent;
		delete del;
	}
	//Поиск самого левого узла
	else
		extractMostLeft(node->left, val);
}

template<typename T>
void Tree<T>::deleteNode(Node<T>*& node) { //Удаляет ноду
	Node<T>* del;
	T replaceVal;
	if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
		node = nullptr;
	}
	else if (!node->left)
	{
		del = node;
		node = node->right;
		node->parent = del->parent;
		del->right = nullptr;
		delete del;
	}
	else if (!node->right)
	{
		del = node;
		node = node->left;
		node->parent = del->parent;
		del->left = nullptr;
		delete del;
	}
	else
	//Если у ноды два наследника
	{
		extractMostLeft(node->right, replaceVal);
		node->value = replaceVal;
	}
}

template<typename T>
void Tree<T>::nodeAmount(Tree::Node<T>*& node, size_t& size) { //Метод подсчитывает количество нод в дереве
	if (node){
		++size;
		nodeAmount(node->left, size);
		nodeAmount(node->right, size);
	}
}

template<typename T>
void Tree<T>::copyTree(Tree::Node<T>* tree, Tree::Node<T>*& newTree) const { //Метод копирует ноды в новое дерево
	if (tree)
	{
		newTree = new Node<T>(tree->value, nullptr, nullptr);
		copyTree(tree->left, newTree->left);
		copyTree(tree->right, newTree->right);
	}
	else
		newTree = nullptr;
}

template<typename T>
void Tree<T>::printTree(Tree::Node<T>* current, int level) { //Метод выводит дерево
	if (current)
	{
		printTree(current->left, level + 1);
		cout << current->value << std::endl;
		printTree(current->right, level + 1);
	}
}	

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator++() {
	Node<T>* temp;
	if (current->right)
	//Если есть наследники справа
	{
		current = current->right;//Переход вправо
		while (current->left)//Проход до конца влево
			current = current->left;
	}
	else//Если наследников справа нет
	{
		temp = current->parent;
		while (temp && current == temp->right) //Переход наверх
		{
			current = temp;
			temp = temp->parent;
		}
		current = temp;
	}
	return *this;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator++(int) {
	Tree<T>::iterator temp = *this;
	++(*this);
	return temp;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator--() {
	Node<T>* temp;
	if (current->left)//Если есть наследники слева
	{
		current = current->left;//Шаг влево
		while (current->right)//Проход до конца вправо
			current = current->right;
	}
	else//Если наследников слева нет
	{
		temp = current->parent;//Проход вверх
		while (temp && current == temp->left)
		{
			current = temp;
			temp = temp->parent;
		}
		current = temp;
	}
	return *this;
}

template<typename T>
const typename Tree<T>::iterator Tree<T>::iterator::operator--(int) {
	Tree<T>::iterator temp = *this;
	--(*this);
	return temp;
}

template<typename T>
void Tree<T>::iterator::operator+=(int num) {
	if (num < 0)
		* this -= (-1 * num);
	else
		while (num > 0)
		{
			++(*this);
			--num;
		}
}

template<typename T>
void Tree<T>::iterator::operator-=(int num) {
	if (num < 0)
		* this += (-1 * num);
	else
		while (num > 0)
		{
			--(*this);
			--num;
		}
}

template<typename T>
bool Tree<T>::iterator::operator==(Tree<T>::iterator rht) {
	return current == rht.current;
}

template<typename T>
bool Tree<T>::iterator::operator!=(Tree<T>::iterator rht) {
	return !(*this == rht);
}

template<typename T>
T& Tree<T>::iterator::operator*(){ //Возвращает сслку на узел, на который указывает итератор
	return current->value;
}

template<typename T>
Tree<T>::Tree(T val) {
	root = new Node<T>(val, nullptr, nullptr);
}

template<typename T>
Tree<T>::~Tree() {
	destroyTree(root);
}

template<typename T>
typename Tree<T>::template Node<T>*& Tree<T>::getRoot() {
	return root;
}

template<typename T>
bool Tree<T>::empty() {
	return !root;
}

template<typename T>
size_t Tree<T>::size() {
	size_t size{};
	nodeAmount(root, size);
	return size;
}

template<typename T>
void Tree<T>::insert(T val) {
	insertItem(root, val, nullptr);
}

template<typename T>
void Tree<T>::pop(T val) {
	popItem(root, val);
}

template<typename T>
void Tree<T>::show() {
	printTree(getRoot(), 0);
	std::cout << std::endl;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::begin() {//Итератор на начало дерева
	Tree<T>::iterator it;
	Node<T>* temp = root;
	if (!temp)
		return it;
	while (temp->left)
		temp = temp->left;
	it.current = temp;
	return it;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::end() {//Итератор на конец дерева
	return Tree<T>::iterator();
}

template<typename T>
inline typename Tree<T>::iterator Tree<T>::find(T obj){
	Tree<T>::iterator it = begin();
	while (*it) {
		if (*it == obj)
			return it;
		++it;
	}
	return it;
}

template<typename T>
void Tree<T>::destroyTree(Tree::Node<T>*& tree) {
	if (tree)
	{
		destroyTree(tree->left);
		destroyTree(tree->right);
		delete tree;
		tree = nullptr;
	}
}