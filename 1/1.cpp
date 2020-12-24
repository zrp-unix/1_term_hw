#include <iostream>

using namespace std;

int p[100], n;

void Fill();
void Print();

int main()
{
	cin >> n;
	Fill();
	if(p[n - 1] > p[n - 2])
		swap(p[n - 1], p[n - 2]);
	else
	{
		int sval = -1;
		for(int i = n-1; i > 0; i--)
			if(p[i - 1] < p[i])
			{
				sval = i - 1;
				break;
			}

		if(sval == -1)
			for(int i = 0, j = n - 1; i < j; i++, j--)
				swap(p[i], p[j]);
		else
		{
			;
		}
	}
	Print();
	return 0;
}

void Fill(){for(int i = 0; i < n; i++) cin >> p[i];}
void Print(){for(int i = 0; i < n; i++) cout << p[i] << " "; cout << endl;}

