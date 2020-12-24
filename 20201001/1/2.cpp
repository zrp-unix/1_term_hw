#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;
	cin >> a;
	int maxsum = a, sum = a, amax = a;
	if(a < 0) sum = 0;
	for(int i=1; i < n; i++)
	{
		cin >> a;
		if(a > amax) amax = a;
		sum += a;
		if(sum < 0) sum = 0;
		if(sum > maxsum) maxsum = sum;
	}
	if(amax < 0) maxsum = amax;
	cout << maxsum << endl;
	return 0;
}
