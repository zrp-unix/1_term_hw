#include <iostream>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n;
	for(int i = 1; i <= n/2; i++)
		for(int j = i; j <= n/2; j++)
			if(i*i + j*j == n)
				cout << i*i << " " << j*j << endl;
	return 0;
}
