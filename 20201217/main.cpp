// 17.12.2019
//
// Ежегодная пресс-конференция президента России Владимира В. Путина

/*
задача-1
чтение из текстового файла - список людей
для решения самостоятельных задач, наверное, понадобится заводить массив личностей
+
для примера организовать вывод в двоичный файл информации о людях, старше 50 лет

задача-2
ввести людей из двоичного файла и напечатать на экране
*/

# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <fstream>
# include <vector>

using namespace std;

const int N = 50;

struct Date
{
	int d, m, y;
	void Print () { cout << setw (2) << d << "." << setw (2) << m << "." << setw (2) << y; }
};

struct Person
{
	char Fa [N], Im [N], Ot [N];
	int deti, zplata, staj;
	Date dr;
	char obr [2], prof [2];
	bool pol, sem;
	void Print (int);
};

bool Task_1 ();	// вводим записи и выводим для проверки на экран
				// выводим старикашек в двоичный файл
bool Task_2 ();	// вводим записи из двоичного файла и распечатываем
				// здесь ввод будет в одно действие (read), а печать подлиннее

int main()	// главная функция традиционная - вызов основной функции Task_1 или Task_2
{
	setlocale (LC_ALL, "rus");
/*
	if ( Task_1 () )
		cout << "OK-1" << endl;
	else
		cout << "Error-1..." << endl;
*/

	if ( Task_2 () )
		cout << "OK-2" << endl;
	else
		cout << "Error-2..." << endl;

	return 0;
}


bool Task_1 ()
{
	ifstream fin ("..\\spisok1.txt");	// мой список находится в папке на один уровень выше программы
	// разделитель папок \\ в двух экземплярах!!!

	if ( ! fin.is_open () )		// открываем файл со списком - текстовый
	{
		cout << "SPISOK1.TXT not found\n";
		return false;
	}

	ofstream fout ("spisok.bin", ios::binary);

	if ( fout == 0 )	// такой способ проверки открытия будет работать не везде!?
		return false;

	char s [N], c;
	int dr, k50 = 0;
	Person p;	// одна переменная для одного человека, но можно завести и массив личностей

// разные свойства людей читаем разными способами - >>, get, read - для наглядности и удобства

	for ( int i=1; ; i++ )	// цикл работает до конца файла
	{
		fin >> p.Fa >> p.Im >> p.Ot >> dr;	// читаем Ф И О + дату в виде одного целого числа

		if ( fin.eof () )	// если попытка чтения после последней строки, то КОНЕЦ цикла
			break;

		fin.get (c);	// читаем : и ПОЛ
		fin.get (c);
		p.pol = c == 'м';	// МУЖ true, остальные - false
		
		fin.get (c);	// читаем : и ОБРАЗОВАНИЕ
		fin.read (p.obr, 2);
		
		fin.get (c);	// читаем : и СЕМЕЙНОЕ_ПОЛОЖЕНИЕ
		fin.get (c);
		p.sem = c == '1';
		
		fin.get (c);	// читаем : и Кол_Детей
		fin >> p.deti;
		
		fin.get (c);	// читаем : и ПРОФЕССИю
		fin.read (p.prof, 2);
		
		fin.get (c);	// читаем : и ??? и :
		fin.get (c);  // ???
		fin.get (c);
		
		fin >> p.zplata;	// читаем ЗПЛАТУ и : и СТАЖ
		fin.get (c);
		fin >> p.staj;
/*

ввод чисел заканчивается не только при чтении пробела или конца стоки,
но и при вводе неподходящих символов, которые не могут встречаться в числах,
например, двоеточия!!!
Чтобы обойти такой символ, надо его обязательно прочитать!
У меня это делает   fin.get (c);

*/
		// выделяем отдельные элементы даты рождения
		
		p.dr.d = dr / 1000000, p.dr.m = (dr/10000)%100,
		p.dr.y = dr%10000;
		
		// печать на экран сохраненной информации

		p.Print (i);
/*		
		cout << setw (3) << i << setw (15) << p.Fa << setw (10) << p.Im << " "
			 << setw (13) << p.Ot << " ";
		p.dr.Print ();
		cout << " " << p.pol << " " << p.sem << " " << p.deti << " ";
		cout << p.obr [0] << p.obr [1] << " ";
		cout << p.prof [0] << p.prof [1] <<
			 setw (6) << p.zplata << " " << setw (3) << p.staj << endl;
*/
// для примера организовать вывод в двоичный файл информации о людях, старше 50 лет

		if ( 2020 - p.dr.y > 50 )
		{
			// 1 человека выводим за 1 действие
			fout.write ((char *) & p, sizeof (Person));
			k50++;
		}

	}

// для проверки печатаем число записей и их размер,
// в произведении должны получить размер двоичного файла 22816
// двоичный файл ожидаемого размера появился...
// вся информация, кроме символьной, нечитаемая

	cout << "k50 = " << k50 << " * " << sizeof (p) << endl;
	cout << k50 * sizeof (p) << endl;

	fin.close ();
	fout.close ();
	
	return true;
}

void Person::Print (int pnum)
{
	cout << setw (3) << pnum << setw (15) << Fa << setw (10) << Im << " "
		 << setw (13) << Ot << " ";
	dr.Print ();
	cout << " " << pol << " " << sem << " " << deti << " ";
	cout << obr [0] << obr [1] << " ";
	cout << prof [0] << prof [1] <<
		 setw (6) << zplata << " " << setw (3) << staj << endl;
}

/*
контрольные вопросы
- что случится, если в структуру Дата добавить конструктор (любой), а в Персону - нет?
- почему ОБРАЗОВАНИЕ и ПРОФЕССИЯ нельзя вводить с помощью >> ?
*/

bool Task_2 ()
{
	ifstream fin ("spisok.bin", ios::binary);

	if ( ! fin.is_open () )
	{
		cout << "SPISOK.BIN not found\n";
		return false;
	}

	Person p;	// одна переменная для одного человека, но можно завести и массив личностей

	for ( int i=1; ; i++ )
	{
		fin.read ((char *) & p, sizeof (Person));	// вводим 1 человека

		if ( fin.eof () )	// если попытка чтения после последней строки, то КОНЕЦ цикла
			break;
		
		// печать на экран сохраненной информации - оформим в виде метода!?

		p.Print (i);
/*		
		cout << setw (3) << i << setw (15) << p.Fa << setw (10) << p.Im << " "
			 << setw (13) << p.Ot << " ";
		p.dr.Print ();
		cout << " " << p.pol << " " << p.sem << " " << p.deti << " ";
		cout << p.obr [0] << p.obr [1] << " ";
		cout << p.prof [0] << p.prof [1] <<
			 setw (6) << p.zplata << " " << setw (3) << p.staj << endl;
*/
	}

	fin.close ();
	
	return true;
}

р
