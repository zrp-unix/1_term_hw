// 03.12.2020

/*
1) Пример с типом Дата
- конструкторы по умолчанию и с параметрами
- ввод/вывод
- Проверка
- Номер дня в году
- День недели
- +1 (-1, +-число)
- високосный?

2) Структура ЛИЧНОСТЬ

*/

# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <cstring>

using namespace std;

struct Date
{
   int d, m, y;
   Date (int pd=1, int pm=1, int py=1);
   void Input () { cin >> d >> m >> y; }
   void Print () { cout << d << "." << m << "." << y << endl; }
   bool Check ();
   bool Leap () { return y % 400 == 0 || y % 4 == 0 && y % 100 != 0; }
   int DayInYear ();
   int DayOfWeek ();
   void NextDate ();
};

struct Person
{

};

int main()
{
   Date d;
   
   d. Input ();
   d.Print ();
   
   if ( d.Check () )
      cout << "OK" << endl;
   else
      cout << "invalid date" << endl;
   
   cout << d.DayInYear () << endl;
   
   cout << d.DayOfWeek () << endl;
   
   switch ( d. DayOfWeek () )
   {
      case 0 : cout << "sun" << endl; break;
      case 1 : cout << "mon" << endl; break;
      case 2 : cout << "tue" << endl; break;
      case 3 : cout << "wed" << endl; break;
      case 4 : cout << "thu" << endl; break;
      case 5 : cout << "fri" << endl; break;
      case 6 : cout << "sat" << endl; break;
   }
   
   d.NextDate ();
   
   d.Print ();
   
   system ("pause");
	return 0;
}

int Date::DayOfWeek ()       // 1.1.2020 - среда (3)
{
   int num = DayInYear () + 2;

   return num % 7;
}

void Date::NextDate ()
{
   d ++; // ???
   
}

int Date::DayInYear ()
{
   int dm [] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
   int num = dm [m] + d;
   if ( Leap () && m > 2 )
      num ++;
   return num;
}

bool Date::Check ()
{
   if ( d < 1 || d > 31 || m < 1 || m > 12 )
      return false;

   if ( d > 30 && ( m == 4 || m == 6 || m == 9 || m == 11) )
      return false;

   if ( m == 2 && (Leap () && d > 29 || ! Leap () && d > 28) )
      return false;

   return true;
}

Date::Date (int pd, int pm, int py)
{
   d = pd; m = pm; y = py;
}

