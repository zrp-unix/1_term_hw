#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int x, p, mark = -1;
	cin >> x;
	p = x;
	double s = 1.0, fact = 1.0,usl=1.0, eps = 0.000001;
	for(int i = 2; abs(usl) >= eps; i+=2)
	{
		fact *= i-1;
		fact *= i;
		x *= p;
		x *= p;
		usl = x / fact;
		s += mark*(usl);
		mark *= -1;
	}
	cout << fixed;
	cout.precision(6);
	cout << s << endl;
	return 0;
}
