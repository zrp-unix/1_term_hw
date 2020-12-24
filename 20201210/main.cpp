# include <iostream>
# include <cstdlib>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>
# include <ctime>
# include <cmath>
# include <algorithm>

using namespace std;

bool Task_0 (char *, char *);
bool Task_2 (char *);

int main ()
{
	if ( Task_2 ("20201210-cope.docx") )
		cout << "OK-2" << endl;
	else
		cout << "Error 2..." << endl;
/*		
	if ( Task_0 ("..\\bachellor.docx", "20201210-copy.docx") )
		cout << "OK-0" << endl;
	else
		cout << "Error 0..." << endl;
*/		
	system ("pause");
	return 0;
}

// 6. ����������� ����� � ����� ����������� � �������� �������

bool Task_2 (char * fname)
{
	fstream f (fname);

	if ( ! f.is_open () )
		return false;
/*
	char s, c;
	f.seekg (0L, ios::beg);
	f.get (s);
	f.seekg (-1L, ios::end);
	f.get (c);

	// �������� 1-� � ��������� ������� - ���� �� ��� ����������

	cout << s << " " << c << endl;
	cout << (int) s << " " << (int) c << endl;

	// ������ ������ �� ��������

	f.seekp (0L, ios::beg);
	f.put (c);
	f.seekp (-1L, ios::end);
	f.put (s);
*/
	// ������ ��� ��� ������ � ����

	f.seekg (0L, ios::end);
	int n = f.tellg ();
	cout << n << endl;
	for ( int i=0, j=n-1; i < j; i++, j-- )
	{
		char s, c;
		f.seekg (i, ios::beg);		// ������ i-� ������� �� ������
		f.get (s);
		f.seekg (-i-1, ios::end);	// ������ j-� ������� �� �����
		f.get (c);

		f.seekp (i, ios::beg);		// ����� i-� ������� �� ������
		f.put (c);
		f.seekp (-i-1, ios::end);	// ����� j-� ������� �� �����
		f.put (s);
	}

	f.close ();
	return true;
}

// 4. ����������� �������� ���� !!!

bool Task_0 (char * ifname, char * ofname)
{
	ifstream fin (ifname, ios::binary);		// !!!
	ofstream fout (ofname, ios::binary);

	if ( ! fin.is_open () || fout == 0 )
		return false;

	int len = 0;
	for ( char c; ! fin.eof (); len++ )
	{
		fin.get (c);
		if ( fin.eof () )
			break;
		fout.put (c);
	}

	cout << len << endl;
	fin.close ();
	fout.close ();
	return true;
}
