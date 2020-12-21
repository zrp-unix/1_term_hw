#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a = 0, b = 1, n = 6;
	for(int i = 0; i < n; i++){
		b = a + b;
		a = b - a; 
	}
	cout << a << endl;
}
