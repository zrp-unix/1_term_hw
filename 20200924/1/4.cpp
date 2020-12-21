#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x, p;
	cin >> x;
	p = x;
	double e = 1.0, fact = 1.0,usl=1.0, eps = 0.000001;
	for(int i = 1;abs(usl) >= eps; i++)
	{
		fact *= i;
		usl = x / fact; 
		e += usl;
		x *= p;
	}
	cout << fixed;
	cout.precision(6);
	cout << e << endl;
	return 0;
}
