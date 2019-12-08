#include "File.h"

bool File::in() {
	fin.ignore(32768, '\n');
	return !fin.eof();
}

void File::close() {
	fin.close();
	fout.close();
}

inline bool File::open_out()
{
	fout.open(file_path);
	if (!fout.is_open())
		cerr << "Невозможно открыть файл" << endl;
	return fout.is_open();
}

inline bool File::open_in()
{
	fin.open(file_path);
	if (!fin.is_open())
		cerr << "Невозможно открыть файл" << endl;
	return fin.is_open();
}

inline void File::flush()
{
	fout.flush();
}