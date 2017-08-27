#include <iostream>
using namespace std;

int main() {
	int a[5] = { 1,10,100,-10,-100 };
	cout << *a << endl;
	int*b(a);
	cout << *b << endl;
	*b++;
	cout << *b << endl;//10
	*(b++);
	cout << *b << endl;//100
	for (int i = 0; i < 5; ++i)
		cout << a[i] << " ";//we still get 1 10 100 -10 -100
	cout << endl;
	return 0;
}
