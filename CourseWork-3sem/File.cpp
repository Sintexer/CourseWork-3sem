#include "File.h"
#include "Exc.h"

bool File::in() {
	while (fin.peek() == '\n') //Пропуск символов новой строки из буфера, которые могут остаться после ввода числа
		fin.get();
	return !fin.eof(); //Возврат состояния конца потока
}

void File::close() {
	fin.close(); //Закрытие потоков ввода и вывода
	fout.close();
}

void File::open_out()
{
	try {
		fout.open(file_path);
		if (!fout.is_open())//Если поток не открылся
			throw Exc_file("Невозможно открыть файл", file_path);
	}
	catch (Exc_file& err) {
		unpackExc(cerr, err); //Вывод ошибки на экран
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
}

void File::open_in()
{
	try {
		fin.open(file_path);
		if (!fin.is_open())//Если поток не открылся
			throw Exc_file("Невозможно открыть файл", file_path);
	}
	catch (Exc_file& err) {
		unpackExc(cerr, err); //Вывод ошибки на экран
	}
	catch (...) {
		cerr << "Unexpected exception" << endl;
	}
}


inline void File::flush() //Выталкивает данные из потока в файл
{
	fout.flush(); 
}