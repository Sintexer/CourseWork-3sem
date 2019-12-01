#pragma once
#include "MostCommonHeaders.h"
#include <fstream>
#include <locale>
#include <codecvt>

class File
{
	
public:

	wstring file_path{};
	std::wofstream fout{};
	std::wifstream fin{};
//public:
	File(wstring path) : file_path(std::move(path)) {}
};

template<typename Ty>
class BinaryFile :
	public File
{
public:
	BinaryFile(wstring path) : File(path)
	{
		fout.open(path, std::ios::binary);
		fin.open(path, std::ios::binary);
	}

};


class TextFile :
	public File
{
public:
	TextFile(wstring path) : File(path) {}
	~TextFile()
	{
		fout.close();
		fin.close();
	}
	bool open_out();
	bool open_in();
	void flush();
	void close() {
		fin.close();
		fout.close();
	}

	template<typename Ty>
	void write(Ty obj);

	template<typename Ty>
	void read(Ty& obj);
};


inline bool TextFile::open_out()
{
	fout.open(file_path,std::ios::binary);
	fout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));
	return fout.is_open();
}


inline bool TextFile::open_in()
{
	fin.open(file_path,std::ios::binary);
	fin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));

	return fin.is_open();
}


inline void TextFile::flush()
{
	fout.flush();
}

template<typename Ty>
inline void TextFile::write(Ty obj)
{
	fout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
}

template<typename Ty>
inline void TextFile::read(Ty& obj)
{
	fin.read(reinterpret_cast<char*>(&obj), sizeof(obj));
}
