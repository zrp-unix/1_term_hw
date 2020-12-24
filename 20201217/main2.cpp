// 17.12.2020
//
// Ежегодная пресс-конференция президента России Владимира В. Путина
//
// второй урок
//
// "Длинная" арифметика

/*
Даны 2 "длинных" натуральных числа. Написать функции для
- ввода числа и записи его в массив по цифрам
- печати числа без незначащих нулей
- сложения чисел
- умножения чисел
*/

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>
# include <ctime>
# include <cmath>
# include <algorithm>

using namespace std;

/*
Даны 2 "длинных" натуральных числа.
Число хранится по цифрам в элементах массива, спереди незначащие нули
длина всех массивов определяется константой N
Написать функции для
- ввода числа с клавиатуры и записи его в массив по цифрам
- печати числа без незначащих нулей
- сложения чисел
- умножения чисел
*/

int * Input (int);	// выделяет память для массива и вводит туда число по цифрам
void Print (int *, int);
// сложение/умножение двух длинных чисел
void Sum (int * c, int * a, int * b, int n);	// c = a + b
void Mul (int * c, int * a, int * b, int n);	// c = a * b
// сложение/умножение длинного числа на обычное
void Sum (int * c, int * a, int b, int n);		// c = a + b
void Mul (int * c, int * a, int b, int n);		// c = a * b

const int N = 1001;

int main ()
{
	int * a = Input (N);
	int * b = Input (N);
	//Print (a, N);
	//Print (b, N);

	int * c = new int [N];
	Sum (c, a, b, N);
	Print (c, N);

	int * d = new int [N+N];
	Mul (d, a, b, N);
	Print (d, N+N);

	system ("pause");
	return 0;
}

int * Input (int n)
{
}

void Print (int * a, int n)
{
}

void Sum (int * c, int * a, int * b, int n)
{
}

void Mul (int * c, int * a, int * b, int n)
{
}

