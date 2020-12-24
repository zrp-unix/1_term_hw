# include <iostream>
# include <ctime>
# include <cstdlib>
# include <fstream>

using namespace std;

void randFstream(int, ofstream&);


int main()
{
	int n;
	cin >> n;
	setlocale (LC_ALL, "rus");
	ofstream fout ("numbers.txt");
	if(!fout.is_open())
	{
	cout << "fout is not open!" << endl;
	return 0;
	}
	randFstream(n, fout);
	fout.close ();
	cout << "OK" << endl;
	return 0;
}

void randFstream(int n, ofstream& fout)
{
	srand(time(0));
	fout << n << " ";
	for(int i = 0; i < n; i++)
		fout << rand()%100 << " ";
	fout << endl;

}
