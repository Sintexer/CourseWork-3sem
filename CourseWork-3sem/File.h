#pragma once
#include "MostCommonHeaders.h"
#include <fstream>

class File
{
protected:
	string file_path{};
	std::ofstream fout{};
	std::ifstream fin{};
public:
	File(string path) : file_path(std::move(path)) {}
};

template<typename Ty>
class BinaryFile :
	public File
{
public:
	BinaryFile(string path) : File(path)
	{
		fout.open(path);
		fin.open(path);
	}

};