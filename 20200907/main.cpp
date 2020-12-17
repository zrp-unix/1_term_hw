#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int d, l, x1, y1, x2, y2;
	cin >> l >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2 && (x1 == 0 || x1 == l)) d = abs (y1 - y2);
    	cout << d;
	return 0;
}
