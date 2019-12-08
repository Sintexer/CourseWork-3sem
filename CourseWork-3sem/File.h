#pragma once
#include "MostCommonHeaders.h"
#include <fstream>

class File
{// Класс файла, для настраиваемого создания и уничтожения объектов файловых потоков
protected:
	string file_path{};
	std::ofstream fout{};
	std::ifstream fin{};
public:
	File(string path) : file_path(std::move(path)) {}
	~File()
	{
		fout.close();
		fin.close();
	}
	bool open_out();
	bool open_in();
	void flush();
	bool in() {
		while (fin.peek() == '\n')
			fin.get();
		return !fin.eof();
	}
	void close() {
		fin.close();
		fout.close();
	}

	template<typename Ty>
	void write(Ty obj);

	template<typename Ty>
	void readLine(Ty obj);

	template<typename Ty>
	bool read(Ty& obj);
};


inline bool File::open_out()
{
	fout.open(file_path);
	if (!fout.is_open())
		cerr << "Невозможно открыть файл" << endl;
	return fout.is_open();
}


inline bool File::open_in()
{
	fin.open(file_path);
	if (!fin.is_open())
		cerr << "Невозможно открыть файл" << endl;
	return fin.is_open();
}


inline void File::flush()
{
	fout.flush();
}

template<typename Ty>
inline void File::write(Ty obj)
{
	fout << obj <<  endl;
}

template<typename Ty>
inline void File::readLine(Ty obj)
{
	while (fin.peek() == '\n')
		fin.get();
	if (fin.eof())
		return false;
	getline(fin, obj);
	return true;
}

template<typename Ty>
inline bool File::read(Ty& obj)
{
	while (fin.peek() == '\n')
		fin.get();
	if (fin.eof())
		return false;
	fin >> obj;
	return true;
}
