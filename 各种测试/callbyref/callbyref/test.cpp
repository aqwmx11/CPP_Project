#include <iostream>
using namespace std;

void swap(int& a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 1, y = 2;
	cout << "After swap" << endl;
	swap(x, y);
	cout << x << " " << y << endl;
	return 0;
}