#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int maxlen=1, len=1, a, b;
	cin >> b;
	for(int i=1; i < n; i++)
	{
		a = b;
		cin >> b;
		if(a < b) len++;
		else
		{
			if(len > maxlen) maxlen = len;
			len = 1;
		}
	}
	if(len > maxlen) maxlen = len;
	cout << maxlen << endl;
	return 0;
}
