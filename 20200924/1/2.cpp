#include <iostream>

using namespace std;

int main()
{
	int x, n;
	cin >> x >> n;
	int s = 1, a = 1;
	for(int i = 0; i < n; i++)
	{
		a *= x; s+= a;
	}
	cout << s << endl;
	return 0;
}
