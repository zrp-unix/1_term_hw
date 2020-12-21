#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool a = 1;
	for(int d = 2; d < n; d++)
		if(n % d == 0)
		{
			a = 0;
			break;
		}
	if(a)
		cout << "Простое" << endl;
	else
		cout << "Составное" << endl;
	return 0;
}
