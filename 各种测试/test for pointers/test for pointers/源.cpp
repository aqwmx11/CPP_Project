#include <iostream>
using namespace std;

int main() {
	int* ptr;
	int j = 5;
	ptr = &j;
	cout << *ptr << endl;//Must initiate to assign an int to a pointer
	*ptr = 4;
	cout << *ptr << endl;
	return 0;
}