// WorkWithFile.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "stdio.h."
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{

	setlocale(0, "RUS");
	string line;
	char str[100];
//==================================================================================================================================
//Создаем текстовый файл с именем file.txt, записываем в него текст	
// Чтение из файла
//указываем путь откуда брать файл
	ifstream MyFile("E:\\books\\институт\\Информатика\\SHIPELOV\\lab#6\\WorkWithFile\\file.txt");  
//при успешном открытии и пока не закончился файл, считываем данные полинейно и выводим на экран
	if (MyFile.is_open())												       
		{
		while (!MyFile.eof())
		{
			getline(MyFile, line);
			cout << line << endl;
			//	убирает в тексте лишние пробелы между словами 
			cout << endl;
			for (int i = 0; i < line.length(); i++)
			if (line[i] == ' ' && line[i + 1] == ' ') { line.erase(i, 1); i = (i - 1); }
			// начинает каждое предложе-ние с новой строки
			for (int i = 0; i < line.length(); i++)
		    // условие для замены точки на символ новой строки
			if (line[i] == '.') 
			{ 
				line[i] = '\n'; 
			}
			cout << line << endl;
		}
		// закрываем файл	
		MyFile.close();
		}

		else cout << "Unable to open file";

//==================================================================================================================================
	// Создаем второй текстовый документ и 
	// Копируем туда получившейся текст
		ofstream MyFile2;
		MyFile2.open("E:\\books\\институт\\Информатика\\SHIPELOV\\lab#6\\WorkWithFile\\file2.txt");
		MyFile2 << line;
		MyFile2.close();

	system("pause");
	return 0;
}

