#include "MathTest.h"
#include "Exc.h"
#include "OutputTable.h"

void MathTest::MakeTable() {
	OutputTable a("��� �����|���������");
	double correct{};
	size_t vc{};
	string temp{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			temp = std::to_string(vc+1)+"|"+std::to_string(user_answers[vc])+")|";
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				temp += "��";
			else
				temp += "���";
			a.add_str(temp);
		}
	cout << a << endl;
}


void MathTest::AddUserAns(size_t ans)
{
	user_answers.push_back(ans);
}

void MathTest::start()
{
	user_answers.clear();
	getAnswers();
	if (user_answers.size())
	{
		cout << "�� ��� ��������� ���� ����" << endl;
		cout << "������� ������ ��� �����?" << endl;
		cout << "\n1: ������ ���� ������\n"
			<< "2: ���������� ����������\n"
			<< "\n0: �����\n" << endl;
		size_t answer;
		inputSafe(cin, answer, 0, 2);
		switch (answer)
		{
		case 1:
			break;
		case 2:
			result();
			return;
		case 0:
			return;
		default:
			break;
		}
	}
	wcout << name << "\n" << endl;
	wcout << test_def << endl;
	system("pause");
	system("cls");
	size_t answer;
	typename std::list<Q_OneAns>::iterator it = questions.begin();
	user_answers.clear();
	while(it!=questions.end()){
		system("cls");
		static_cast<Q_OneAns>(*it).ask();
		cout << "0: �����" << endl;
		cout << "\n������� ��� �����: \n" << endl;
		inputSafe(cin, answer, 0, dynamic_cast<Q_OneAns&>(*it).getAnswersSize());
		if (answer == 0) {
			if (it == questions.begin())
				return;
			if (!user_answers.size())
				user_answers.pop_back();
			--it;

			continue;
		}
		user_answers.push_back(answer);
		
		++it;
	}
	system("cls");
	check();
}

void MathTest::check()
{
	MakeTable();
	result();
	system("pause");
	cout << "������� ��������� ��� ���������?" << endl;
	cout << "1: ��\n"
		<< "2: ���\n" << endl;
	size_t answer{};
	inputSafe(cin, answer, 1, 2);
	if(answer==1)
		putAnswers();

}

void MathTest::result()
{
	double correct{};
	size_t vc{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	if (questions.size())
		for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
			if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
				++correct;
		}
	cout << "��� ������� ���������� ������� ����������: " <<(int)((correct / questions.size()) * 100) << "%" << endl;

}

bool MathTest::writeFile(TextFile& txt)
{
	txt.open_in();
	if (txt.fout.eof())
		return false;
	txt.fout << name << endl;
	txt.fout << test_def << endl;
	txt.fout << questions.size() << endl;
	std::list<Q_OneAns>::iterator it = questions.begin();	
	for(it; it!=questions.end();++it)
		dynamic_cast<Q_OneAns&>(*it).writeFile(txt);
	txt.fout << answers_path << endl;
	txt.close();
	return true;
}

bool MathTest::putAnswers() {
	TextFile txt(answers_path);
	txt.open_out();
	txt.fout << user_answers.size() << endl;
	std::vector<size_t>::iterator in = user_answers.begin();
	while (in != user_answers.end()) {
		txt.fout << *in << endl;
		++in;
	}
	txt.close();
		return true;
}

bool MathTest::readFile(TextFile& txt)
{
	setlocale(LC_ALL, "Rus");
	if (txt.fin.eof())
		return false;
	while (txt.fin.peek() == '\n')
		txt.fin.get();
	
	getline(txt.fin, name);
	getline(txt.fin, test_def);
	size_t size{};
	txt.fin >> size;
	questions.clear();
	while (size) {
		Q_OneAns temp{};
		temp.readFile(txt);
		questions.push_back(temp);
		--size;
	}
	while (txt.fin.peek() == '\n')
		txt.fin.get();
	getline(txt.fin, answers_path);
	return true;
}

bool MathTest::getAnswers()
{
	TextFile txt(answers_path);
	if (!txt.open_in())
		return false;
	size_t size{};
	txt.fin >> size;
	while (size) {
		size_t temp{};
		txt.fin >> temp;
		user_answers.push_back(temp);
		--size;
	}
	return true;
}

wstring MathTest::getPath()
{
	return path;
}
