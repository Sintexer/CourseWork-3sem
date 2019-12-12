#pragma once
#include "File.h"

	class Question //������������ ����� ������� ��� �������������
	{
	protected:
		string question_def{}; //����� �������� ������� �������
	public:
		Question() = default;
		Question(string question) : question_def(question) {};
		Question(const Question& qst) : question_def(qst.question_def) {};
		~Question() = default;

		virtual void ask() = 0; //����� ������� ������ � �������� ������ �� ����
	};

	class Q_OneAns : //������ � ����� �������
		public Question
	{
	protected:
		vector<string> answers{}; //������ ��������� ������ �� ������
		double correct_ans{}; //���������� �����
	public:
		Q_OneAns() = default;
		Q_OneAns(string qst) : Question(qst) {};
		Q_OneAns(const Q_OneAns& qoa) : Question(qoa.question_def), correct_ans(qoa.correct_ans), answers(qoa.answers) {};
		~Q_OneAns() = default;

		virtual void ask() override; //����� ������� ������ � �������� ������ �� ����

		double getCorrectAns(); //���������� ���������� ����� �� ������
		size_t getAnswersSize(); //���������� ���������� ������� �� ������

		friend std::istream& operator>> (std::istream& in, Q_OneAns& obj); //�������� ����� ������� �� ������ �����
	};

	class Q_Cost : //������, ��� � ������� �������� ������ ���� ����
	public Question
	{
	protected:
		vector<string> answers{"����� �����", "�����", "������", "�����", "�������"}; //������, ������� �������� �������� ������ �� ������
		vector<int> costs{5,4,3,2,1}; //������ �������� ���-�� ������, ������� ���� ������ �����
	public:
		Q_Cost() = default;
		Q_Cost(string qst) : Question(qst) {};
		Q_Cost(const Q_Cost& qoa) : Question(qoa.question_def), answers(qoa.answers), costs(qoa.costs) {};
		~Q_Cost() = default;

		virtual void ask() override; //����� ������� ������ � �������� ������ �� ����
		
		int getCost(int a);//���������� ���� �� ������� costs �� ����������� �������
		size_t getAnswersSize(); //���������� ���������� ������� �� ������
		
		friend std::istream& operator>> (std::istream& in, Q_Cost& obj); //�������� ����� ������� �� ������ �����
	};
