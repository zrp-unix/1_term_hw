#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream fin;
    ofstream fout1;
    ofstream fout2;
    string finname = "numbers.txt";
    string fout1name = "1.txt";
    string fout2name = "2.txt";
    fin.open(finname.c_str());
    fout1.open(fout1name.c_str());
    fout2.open(fout2name.c_str());
    int tmp;
    fin >> tmp;
    while (fin >> tmp)
    {
        if (tmp % 2 == 0)
            fout1 << tmp << " ";
        else 
            fout2 << tmp << " ";
    }
    fin.close();
    fout1.close();
    fout2.close();
    return 0;
}
