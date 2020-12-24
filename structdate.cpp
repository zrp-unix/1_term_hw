#include <iostream>
#include <cstdlib>

using namespace std;

struct Date
{
    int d, m, y;
    Date(int pd=1, int pm=1, int py=1);
    void Input() { cin >> d >> m >> y;}
    void Print() { cout << d << "." << m  << "." << y << endl;}
    bool Check();
    bool Leap(){ return y % 400 == 0 || (y%4 == 0 && y % 100 != 0);}
    int DayInYear();
    int DayOfWeek();
    void NextDate();
};

int main()
{
    Date d;
    d.Input();
    d.Print();
    if(d.Check())
        cout << "Ok" << endl;
    else
        cout << "Invalid date" << endl;
    cout << d.DayInYear() << endl;
    cout << d.DayOfWeek() << endl;
    switch (d.DayOfWeek())
    {
        case 0 : cout << "Sunday" << endl; break;
        case 1 : cout << "Monday" << endl; break;
        case 2 : cout << "Tuesday" << endl; break;
        case 3 : cout << "Wednesday" << endl; break;
        case 4 : cout << "Thursday" << endl; break;
        case 5 : cout << "Friday" << endl; break;
        case 6 : cout << "Saturday" << endl; break;
    }

    d.NextDate();
    d.Print();
    system("pause");
    return 0;
}

bool Date::Check ()
{
    if(d < 1 || d > 31 || m < 1 || m > 12)
        return false;
    if(d > 30 && (m == 4 || m ==6 || m == 9 || m == 11))
        return false;
    if(m == 2 && ((Leap() && d > 29) || (!Leap() && d > 28)))
        return false;
    else
        return true;
}

Date::Date(int pd, int pm, int py)
{
    d = pd; m = pm; y = py;
}

int Date::DayInYear()
{
    int dm [] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int num = dm[m] + d;
    if(Leap() && m > 2)
        num++;
    return num;
}

int Date::DayOfWeek()
{
    int num = DayInYear() + 2;
    return num % 7;
}

void Date::NextDate()
{
    if(d <= 27) d+=1;
    if(d == 28 && m == 2 && Leap()) d+=1;
    if(d == 28 && m == 2 && !Leap()) {d = 1; m+= 1;}
    if(d == 30 &&(m == 4 || m == 6 || m == 9 || m == 11)) {d = 1; m+= 1;}
    if(d == 31 &&(m != 4 || m != 6 || m != 9 || m != 11)) {d = 1; m+= 1;}
    if(d == 31 && m == 12) {d = 1; m = 1; y+=1;}
}
