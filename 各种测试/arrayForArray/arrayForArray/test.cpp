#include <iostream>
using namespace std;

int main() {
	int a[4][2] = { {1,2},{3,4},{5,6},{7,8} };
	cout << **a << endl;//1
	cout << (*a)[0] << endl;//1
	cout << (*a)[1] << endl;//2
	cout << (*a)[2] << endl;//3
	cout << (*a)[3] << endl;//4
	cout << *a[1] << endl;//3
	cout << **(a + 1) << endl;//3
	return 0;
}