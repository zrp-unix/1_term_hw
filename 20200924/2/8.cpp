#include <iostream>

using namespace std;

int main()
{
	int x, n, px, q = 1, p = 0;
	cin >> x >> n;
	for(int i = 0; i <= n; i++)
	{
		p = 0;
		px = x;
		for(int j = 1; j <= i; j++)
		{
			px *= x;
			p += (i-j)*px;
		}
		p += i+1 + i*x;
		q *= p;
	}
	cout << q << endl;
}
