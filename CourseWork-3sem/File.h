#pragma once
#include "MostCommonHeaders.h"
#include "Exc.h"
#include <fstream>

class File
{// ����� �����, ��� �������������� �������� � ����������� �������� �������� �������
protected:
	string file_path{};
	//���� �����
	std::ofstream fout{};
	//�������� �������� �����, ����������� � file_path
	std::ifstream fin{};
	//�������� ������� �����, ����������� � file_path

public:
	File(string path): file_path(std::move(path)) {}
	//����������� ����� ���� � �����
	~File()
	{
		fout.close();
		fin.close();
	}//��������� ��������� ������

	bool open_out();
	//������� �������� �����
	bool open_in();
	//������� ������� �����
	void flush();
	//������ ��������� � ���� �� ��������� ������, ��� �������� ������
	bool in();
	//��������, �� ���������� �� ����
	void close();
	//����� �������� ����� �������

	template<typename Ty>
	void write(Ty obj);
	//����� ������ ������� � ����

	template<typename Ty>
	bool readLine(Ty& obj);
	//����� ��������� �� ����� ������ � ������� �� � ������

	template<typename Ty>
	bool read(Ty& obj);
	//����� ��������� �� ����� ������
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
	//���� ����� ����� - ���������� false
	getline(fin, obj);
	return true;
}

template<typename Ty>
inline bool File::read(Ty& obj)
{
	fin.ignore(32768, '\n');
	if (fin.eof())
		return false;
	//���� ����� ����� - ���������� false
	fin >> obj;
	return true;
}
