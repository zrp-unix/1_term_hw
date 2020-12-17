#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int c = 1;
	for(int i = 1; i <= n-k; i++) c = c*(k + i) / i;
	cout << c << endl;
	return 0;
}
