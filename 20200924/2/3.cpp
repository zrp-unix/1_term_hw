#include <iostream> 

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	for (int n = a; n <= b; n++)
	{
		bool c = 1;
		for (int d = 2; d < n; d++)
			if (n % d == 0)
			{
				c = 0;
				break;
			}

		if (c)
			cout << " " << n;
	}
}
