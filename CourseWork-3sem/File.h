#pragma once
#include "Exc.h"
#include <fstream>

class File
{// Класс файла, для настраиваемого создания и уничтожения объектов файловых потоков
protected:
	string file_path{}; //Путь файла
	std::ofstream fout{}; //Файловый выходной поток, привязвнный к file_path
	std::ifstream fin{}; //Файловый входной поток, привязвнный к file_path
public:
	File(string path): file_path(std::move(path)) //Конструктор через путь к файлу
	{} 
	~File(){ //Деструтор закрывает потоки
		fout.close();
		fin.close();
	}

	void open_out(); //Открыть выходной поток
	void open_in(); //Открыть входной поток

	void flush(); //Внести изменения в файл из выходного потока, без закрытия потока
	bool in();	//Проверка, не закончился ли файл
	void close();	//Метод закрытия обоих потоков

	std::ifstream& getFin(); //Возаращает входной поток
	std::ofstream& getFout(); //Возвращает выходной поток

	template<typename T>
	void write(T obj, char delim = '\n'); //Метод записи объекта в файл
		
	template<typename T>
	bool readLine(T& obj); //Метод считывает из файла строку и заносит ее в объект

	template<typename T>
	bool read(T& obj); //Метод считывает из файла объект
};

template<typename T>
inline void File::write(T obj, char delim){ //Записывает объект T obj в файл, привязанный к потоку fout
	fout << obj <<  delim; //Запись объекта в файл
}

template<typename T>
inline bool File::readLine(T& obj){//Читает строку из файла и заносит в объект T obj
	while (fin.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		fin.get();
	if (fin.eof())//Если конец файла
		return false;//Возвращает false
	getline(fin, obj);//Считывает строку из файла
	return true;//Возвращает true
}

template<typename T>
inline bool File::read(T& obj){//Читает строку из файла и заносит в объект T obj

	while (fin.peek() == '\n')//Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		fin.get();
	if (fin.eof())//Если конец файла
		return false;//Возвращает false
	fin >> obj;//Считывает объект из файла
	return true;//Возвращает true
}
