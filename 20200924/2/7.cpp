#include <iostream>

using namespace std;

int main()
{	
	int n, px = 1, x, p= 1, d = 1;
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
	{	
		px *= x;
		d += px;
		p *= d;
	}
	cout << p << endl;
	return 0;
}
