#pragma once
#include "MostCommonHeaders.h"

class Exc { //������������ ����� ����������
protected:
    std::string exception_def;
	//�������� ����������
public:
    Exc():exception_def("None definition")
    {}
    explicit Exc(std::string exception_definition): exception_def(std::move(exception_definition))
    {}

    const string& getExcDef() const;
	//���������� �������� ����������
};


class Exc_input: //����������, ��������� �������������� ������
        public Exc
{
protected:
    int Exc_code; //��� ������ �����
public:
    Exc_input(): Exc(), Exc_code(0)
    {}
    Exc_input(int code, std::string exception_definition):Exc(std::move(exception_definition)), Exc_code(code)
    {}

    const int getExcCode();
	//���������� ��� ������ �����
};

class Exc_input_range : //������ ����� � ��������� �����
	public Exc_input
{
protected:
	int left_bound, right_bound;
	//������� ����� �����, left_bound ������ ���� ������ right_bound
public:
	Exc_input_range() : Exc_input(), left_bound(0), right_bound(0)
	{}
	Exc_input_range(int code, std::string exception_definition, int lft, int rht) :Exc_input(code, std::move(exception_definition)), left_bound(lft), right_bound(rht)
	{}

	const int getLeftBound();
	const int getRightBound();
	//������ ���������� ����� � ������ ������� ��������������
};

class Exc_file : //���������� ������ � ������
	public Exc
{
protected:
	string path{};
	//���� �����, � ������ � ������� ��������� ������
public:
	Exc_file() : Exc() 
	{}
	Exc_file(string def, string file_path) : Exc(def), path(file_path)
	{}

	const string getPath();
	//����� ���������� ���� � �����
};


template<typename T>
void inputSafe(std::istream& in, T& num) {
	//������� ����������� ����� �����
	bool flag{ true };//��������������� � false, ���� ���� ������� ����������
	while (flag)//���� �� ���� ������� ����������, �� ����������� ����
	{
		try {
			flag = false;
			in >> num;
			if (!in.good() || in.peek() != '\n')//�������� �� ���� �����
				throw Exc_input(1, "���� �����������");
		}
		catch (Exc_input& error)
		{
			flag = true;
			unpackExc(cerr, error);
			cout << "������� �����" << endl;
			rewind(stdin);
			in.clear();
		}
		catch (...)
		{
			flag = true;
			cout << "Unexpected exception";
			rewind(stdin);
			in.clear();
		}
	}
}

template<typename T>
void inputSafe(std::istream& in, T& num, size_t range_left, size_t range_right) {
	//������� ����� ����� � �������� ���������
	bool flag{ true };//��������������� � false, ���� ���� ������� ����������
	while (flag)
	{
		try {
			flag = false;//���� �� ���� ������� ����������, �� ����������� ����
			in >> num;
			if (!in.good() || in.peek() != '\n')//�������� �� ���� �����
				throw Exc_input(2, "���� �� �������� ������");
			if (!(num >= range_left && num <= range_right))//�������� �� ������� ���������
				throw Exc_input_range(4, "��������� ������� �� ������ � ��������", range_left, range_right);

		}
		catch (Exc_input_range& error) {
			flag = true;
			unpackExc(std::cerr, error);
			cout << "������� ����� ����� " << error.getLeftBound() << " � " << error.getRightBound() << endl;
			rewind(stdin);
			in.clear();
		}
		catch (Exc_input& error) {
			flag = true;
			unpackExc(std::cerr, error);
			cout << "������� �����: " << endl;
			rewind(stdin);
			in.clear();
		}

		catch (...) {
			flag = true;
			cout << "Unexpected exception";
			rewind(stdin);
			in.clear();
		}
	}
}


void safeStr(std::istream& in, std::string& str);
//������� ����������� ����� ������

void unpackExc(std::ostream& out, Exc& error);
//������� ������� ���������� ���������� �� �����