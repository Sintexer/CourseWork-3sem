#include "File.h"
#include "Exc.h"

bool File::in() {
	while (fin.peek() == '\n') //������� �������� ����� ������ �� ������, ������� ����� �������� ����� ����� �����
		fin.get();
	return !fin.eof(); //������� ��������� ����� ������
}

void File::close() {
	fin.close(); //�������� ������� ����� � ������
	fout.close();
}

std::ifstream& File::getFin(){ //���������� ������� �����
	return fin;
}

std::ofstream& File::getFout(){ //���������� �������� �����
	return fout;
}

void File::open_out(){ //��������� ���� ��� ������
	try {
		fout.open(file_path);
		if (!fout.is_open())//���� ����� �� ��������
			throw Exc_file("���������� ������� ����", file_path);
	}
	catch (Exc_file& err) {
		unpackExc(cerr, err); //����� ������ �� �����
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
}

void File::open_in(){ //��������� ���� ��� ������
	try {
		fin.open(file_path);
		if (!fin.is_open())//���� ����� �� ��������
			throw Exc_file("���������� ������� ����", file_path);
	}
	catch (Exc_file& err) {
		unpackExc(cerr, err); //����� ������ �� �����
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
}


inline void File::flush(){ //����������� ������ �� ������ � ����
	fout.flush(); 
}