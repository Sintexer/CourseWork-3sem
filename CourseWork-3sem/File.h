#pragma once
#include "Exc.h"
#include <fstream>

class File
{// ����� �����, ��� �������������� �������� � ����������� �������� �������� �������
protected:
	string file_path{}; //���� �����
	std::ofstream fout{}; //�������� �������� �����, ����������� � file_path
	std::ifstream fin{}; //�������� ������� �����, ����������� � file_path
public:
	File(string path): file_path(std::move(path)) //����������� ����� ���� � �����
	{} 
	~File(){ //��������� ��������� ������
		fout.close();
		fin.close();
	}

	void open_out(); //������� �������� �����
	void open_in(); //������� ������� �����

	void flush(); //������ ��������� � ���� �� ��������� ������, ��� �������� ������
	bool in();	//��������, �� ���������� �� ����
	void close();	//����� �������� ����� �������

	std::ifstream& getFin(); //���������� ������� �����
	std::ofstream& getFout(); //���������� �������� �����

	template<typename T>
	void write(T obj, char delim = '\n'); //����� ������ ������� � ����
		
	template<typename T>
	bool readLine(T& obj); //����� ��������� �� ����� ������ � ������� �� � ������

	template<typename T>
	bool read(T& obj); //����� ��������� �� ����� ������
};

template<typename T>
inline void File::write(T obj, char delim){ //���������� ������ T obj � ����, ����������� � ������ fout
	fout << obj <<  delim; //������ ������� � ����
}

template<typename T>
inline bool File::readLine(T& obj){//������ ������ �� ����� � ������� � ������ T obj
	while (fin.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		fin.get();
	if (fin.eof())//���� ����� �����
		return false;//���������� false
	getline(fin, obj);//��������� ������ �� �����
	return true;//���������� true
}

template<typename T>
inline bool File::read(T& obj){//������ ������ �� ����� � ������� � ������ T obj

	while (fin.peek() == '\n')//������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		fin.get();
	if (fin.eof())//���� ����� �����
		return false;//���������� false
	fin >> obj;//��������� ������ �� �����
	return true;//���������� true
}
