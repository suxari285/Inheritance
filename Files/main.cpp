#include<iostream>
#include<fstream>
#include<Windows.h>

using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define INPUT_STRINGS

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	//создаем поток
	std::ofstream fout;
	//открываем поток
	fout.open("File.txt", std::ios_base::app);
	//записываем в поток
	fout << "FILES" << endl;
	//закрываем поток
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE
#ifdef INPUT_STRINGS
	const int SIZE = 256;
	char first_name[SIZE] = {};
	char last_name[SIZE] = {};
	SetConsoleCP(1251);
	cin >> first_name >> last_name;
	SetConsoleCP(866);
	cout << first_name << "\t" << last_name;
#endif // INPUT_STRINGS

	const int SIZE = 256;
	char sz_buffer[SIZE] = {};

	//создаем и открываем поток
	std::ifstream fin("main.cpp"); //если указать имя файла то он сразу откроется
	//проверяем сущевствование файла
	if (fin.is_open())
	{
		while (!fin.eof())// EOF- End Of File
		{
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		std::cerr << "File not found!" << endl;
	}
	//закрываем поток
	fin.close();
}