// 03.12.2020

/*
файловый ввод/вывод

0. схема движения данных при работе с файлами

ВВОД: источник (файл на диске) ==> вводной поток ifstream ==> получатель (переменная)
ВЫВОД: источник (переменная в памяти) ==> выводной поток ofstream ==> получатель (файл на диске)

1. Дан текстовый файл из нескольких строк.
Скопировать этот в другой 3-мя способами:

+ >> <<
+ посимвольно get / put
+ построчно   getline / <<
- блоками     read / write

+Описание файла=потока
+Открыть
+Анализ открытия
+Ввод/вывод
+[Закрыть]

Задание на дом:

//////2. Нужно сгенерировать несколько случайных чисел и записать их в текстовый файл.
//////Перед первым числом заранее вывести их количество.
//////
//////3. В текстовом файле находится несколько целых чисел. Перед числами записано
//////их количество. Раскидать числа по 2-м текстовым файлам (четные/нечетные)
//////
//////4. скопировать двоичный файл
 
*/

# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <fstream>

using namespace std;

int main()
{
   setlocale (LC_ALL, "rus");
   ifstream fin;
   ofstream fout ("20200907-copy.cpp");
   
   fin.open ("20200907.cpp");
   
   if ( ! fin.is_open () )
   {
      cout << "fin is not open!" << endl;
      system ("pause");
  	   return 0;
   }
   
   if ( ! fout.is_open () )
   {
      cout << "fout is not open!" << endl;
      system ("pause");
  	   return 0;
   }
   
   char c, s [200];
   for ( ; ! fin.eof (); )
   {
/*
      fin >> c;
      cout << c;
      fout << c;
*/
/*
      fin.get (c);
      cout << c;
      fout.put (c);
*/
      fin.getline (s, 200);
      fout << s << endl;
      cout << s << endl;

   }
   
   fin.close ();
   fout.close ();
   cout << "OK" << endl;
   system ("pause");
	return 0;
}

