#include "Exc.h"



void unpackExc(std::ostream& out, Exc& error){
	out << "|Вызвано исключение|\n" << error.getExcDef() << endl;
}

const std::string &Exc::getExcDef() const {
    return exception_def;
}

void Exc::setExcDef(const std::string &exceptionDef) {
    exception_def = exceptionDef;
}

const int Exc_input::getExcCode() {
    return Exc_code;
}

void safeStr(std::istream& in, std::string& str)
{
	bool flag{ 1 };

	while (flag)
	{
		try {
			flag = false;
			rewind(stdin);
			getline(in, str);
			for (size_t i = 1; i < str.length(); ++i)
			{
				if (!(str[i] >= 'А' && str[i] <= 'я'))
					throw(Exc_input(5, "Введенная строка должна быть введена на русском языке"));
			}
			flag = false;
		}
		catch (Exc_input& error) {
			flag = true;
			unpackExc(cout, error);
			cout << "Введите строку" << endl;
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

const int Exc_input_range::getLeftBound()
{
	return left_bound;
}

const int Exc_input_range::getRightBound()
{
	return right_bound;
}
