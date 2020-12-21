#include <iostream>

using namespace std;

int main()
{
	int a, b, sum = 0;
	cin >> a >> b;
	for(int n = a; n <= b; n++){
		sum = 0;
		for(int i = 1; i <= n/2; i++)
			if(n % i == 0)
				sum += i;
		if(n == sum)
			cout << " " << sum;
	}
	cout << endl;
	return 0;
}
