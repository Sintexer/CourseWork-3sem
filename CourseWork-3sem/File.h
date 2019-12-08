#pragma once
#include "MostCommonHeaders.h"
#include "Exc.h"
#include <fstream>

class File
{// Класс файла, для настраиваемого создания и уничтожения объектов файловых потоков
protected:
	string file_path{};
	//Путь файла
	std::ofstream fout{};
	//Файловый выходной поток, привязвнный к file_path
	std::ifstream fin{};
	//Файловый входной поток, привязвнный к file_path

public:
	File(string path): file_path(std::move(path)) {}
	//Конструктор через путь к файлу
	~File()
	{
		fout.close();
		fin.close();
	}//деструтор закрывает потоки

	bool open_out();
	//Открыть выходной поток
	bool open_in();
	//Открыть входной поток
	void flush();
	//Внести изменения в файл из выходного потока, без закрытия потока
	bool in();
	//Проверка, не закончился ли файл
	void close();
	//Метод закрытия обоих потоков

	template<typename Ty>
	void write(Ty obj);
	//Метод записи объекта в файл

	template<typename Ty>
	bool readLine(Ty& obj);
	//Метод считывает из файла строку и заносит ее в объект

	template<typename Ty>
	bool read(Ty& obj);
	//Метод считывает из файла объект
};

template<typename Ty>
inline void File::write(Ty obj)
{
	fout << obj <<  endl;
}

template<typename Ty>
inline bool File::readLine(Ty& obj)
{
	fin.ignore(32768, '\n');
	if (fin.eof())
		return false;
	//Если конец файла - возвращаем false
	getline(fin, obj);
	return true;
}

template<typename Ty>
inline bool File::read(Ty& obj)
{
	fin.ignore(32768, '\n');
	if (fin.eof())
		return false;
	//Если конец файла - возвращаем false
	fin >> obj;
	return true;
}
