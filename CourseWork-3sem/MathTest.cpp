#include "MathTest.h"
#include "Exc.h"

void MathTest::AddUserAns(size_t ans)
{
	user_answers.push_back(ans);
}

void MathTest::start()
{
	cout << name << "\n" << endl;
	cout << test_def << endl;
	system("pause");
	system("cls");
	size_t answer;
	typename std::list<Q_OneAns>::iterator it = questions.begin();
	for (it; it != questions.end(); ++it) {
		static_cast<Q_OneAns>(*it).ask();
		cout << "\nВведите ваш ответ: \n" << endl;
		inputSafe(cin, answer, 1, dynamic_cast<Q_OneAns&>(*it).getAnswersSize());
		user_answers.push_back(answer);
		system("cls");
	}
}

void MathTest::check()
{
	double correct{};
	std::list<Q_OneAns>::iterator qstit = questions.begin();
	size_t vc{};
	for (qstit, vc; qstit != questions.end(); ++qstit, ++vc) {
		if (static_cast<Q_OneAns&>(*qstit).getCorrectAns() == user_answers[vc])
			++correct;
		else {
			cout << "Вы неправильно ответили на " << vc << "-й вопрос" << endl;
			cout << "Правильный ответ номер - " << static_cast<Q_OneAns&>(*qstit).getCorrectAns() << endl << endl;
		}
	}
	cout << "Ваш процент правильных ответов составляет: " << (correct / questions.size() )* 100 << endl;

}
